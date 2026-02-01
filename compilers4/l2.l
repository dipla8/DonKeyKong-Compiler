%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
 
/* --- Buffers (Size 256 for input, 512 for temp to prevent overflow) --- */
char op[256], arg1[256], arg2[256], res[256];
 
/* --- Helper Prototypes --- */
char* get_mem_loc(char *name);
char* get_input_reg(char *arg, char *load_reg);
void handle_bin_op(char *operator, char *a1, char *a2, char *r);
void handle_assignment(char *src, char *dest);
void handle_branch(char *op_name, char *a1, char *a2, char *label);
 
int is_register(char *str) {
    if (strcmp(str, "ra") == 0) return 1;
    if (str[0] == 't' || str[0] == 'a' || str[0] == 'v' || str[0] == 's') {
        if (isdigit(str[1])) return 1;
    }
    return 0;
}
 
int is_immediate(char *str) {
    if (str == NULL || *str == '\0') return 0;
    if (isdigit(str[0]) || (str[0] == '-' && isdigit(str[1]))) return 1;
    return 0;
}
%}
 
%option noyywrap
 
/* Macros */
SEP         [ \t]*,[ \t]*
WS          [ \t]+
ANY         [^,\n\r]+
 
%%
 
    /* --- 1. Labels --- */
[a-zA-Z_][a-zA-Z0-9_.]*: {
    printf("%s\n", yytext);
}
 
    /* --- 2. Equality Checks (==) --- */
"=="{SEP}{ANY}{SEP}{ANY}{SEP}{ANY} {
    sscanf(yytext, "==, %[^,], %[^,], %s", arg1, arg2, res);
    
    char *dest_reg = is_register(res) ? res : "k3";
    char *r1 = get_input_reg(arg1, "$k1");
    char *r2 = get_input_reg(arg2, "$k2");
    
    printf("\tseq $%s, %s, %s\n", dest_reg, r1, r2);
    
    if (!is_register(res)) {
        printf("\tsw $k3, %s\n", get_mem_loc(res));
    }
}
 
    /* --- 3. Arithmetic (+, -, *, /) --- */
[\+\-\*\/]{SEP}{ANY}{SEP}{ANY}{SEP}{ANY} {
    sscanf(yytext, "%[^,], %[^,], %[^,], %s", op, arg1, arg2, res);
    handle_bin_op(op, arg1, arg2, res);
}
 
    /* --- 4. Assignments (=) --- */
"="{SEP}{ANY}{SEP}{SEP}{ANY} {
    sscanf(yytext, "=, %[^,], , %s", arg1, res);
    handle_assignment(arg1, res);
}
 
    /* --- 5. Branches (bne) --- */
"bne"{SEP}{ANY}{SEP}{ANY}{SEP}{ANY} {
    sscanf(yytext, "bne, %[^,], %[^,], %s", arg1, arg2, res);
    handle_branch("bne", arg1, arg2, res);
}
 
    /* --- 6. Jumps (jal, jr) --- */
"jal"{SEP}{SEP}{SEP}{ANY} {
    sscanf(yytext, "jal, , , %s", res);
    printf("\tjal %s\n", res);
}
 
"jr"{SEP}{SEP}{SEP}{ANY} {
    sscanf(yytext, "jr, , , %s", res);
    printf("\tjr $%s\n", res);
}
 
    /* --- 7. Explicit Load (lw) --- */
"lw"{SEP}{ANY}{SEP}{ANY}{SEP}{ANY} {
    sscanf(yytext, "lw, %[^,], %[^,], %s", arg1, arg2, res);
    printf("\tlw $%s, %s\n", res, get_mem_loc(arg2));
}
 
    /* --- 8. Explicit Store (sw) --- */
"sw"{SEP}{ANY}{SEP}{ANY}{SEP}{ANY} {
    sscanf(yytext, "sw, %[^,], %[^,], %s", arg1, arg2, res);
    
    char *src;
    if (is_immediate(arg1)) {
        printf("\tli $k3, %s\n", arg1);
        src = "$k3";
    } else {
        /* FIX: Buffer increased to 512 to safely hold arg1 + "$" */
        static char tmp[512];
        sprintf(tmp, "$%s", arg1);
        src = tmp;
    }
    printf("\tsw %s, %s\n", src, get_mem_loc(res));
}
 
    /* --- 9. Cleanup --- */
^\     { }
.            { printf("# Unrecognized: %s\n", yytext); }
 
%%
 
int main() {
    yylex();
    return 0;
}
 
char* get_mem_loc(char *name) {
    static char buf[512];
    if (strcmp(name, "index") == 0 || strcmp(name, "stride") == 0)
        sprintf(buf, "%s($gp)", name);
    else
        sprintf(buf, "%s($fp)", name);
    return buf;
}
 
char* get_input_reg(char *arg, char *load_reg) {
    static char buf[512];
    
    if (is_register(arg)) {
        sprintf(buf, "$%s", arg);
        return buf;
    }
    
    if (is_immediate(arg)) {
        printf("\tli %s, %s\n", load_reg, arg);
        return load_reg;
    }
 
    printf("\tlw %s, %s\n", load_reg, get_mem_loc(arg));
    return load_reg;
}
 
void handle_bin_op(char *op_sym, char *a1, char *a2, char *r) {
    char mips_op[16];
    int is_addi = 0;
 
    if (strcmp(op_sym, "+") == 0) strcpy(mips_op, "add");
    else if (strcmp(op_sym, "-") == 0) strcpy(mips_op, "sub");
    else if (strcmp(op_sym, "*") == 0) strcpy(mips_op, "mul");
    else if (strcmp(op_sym, "/") == 0) strcpy(mips_op, "div");
    
    if (strcmp(mips_op, "add") == 0 && is_immediate(a2)) {
        strcpy(mips_op, "addi");
        is_addi = 1;
    }
 
    char *src1 = get_input_reg(a1, "$k1");
    char *src2 = is_addi ? a2 : get_input_reg(a2, "$k2");
 
    char *dest_reg;
    int store_needed = 0;
 
    if (is_register(r)) {
        static char reg_buf[512];
        sprintf(reg_buf, "$%s", r);
        dest_reg = reg_buf;
    } else {
        dest_reg = "$k3";
        store_needed = 1;
    }
 
    printf("\t%s %s, %s, %s\n", mips_op, dest_reg, src1, src2);
 
    if (store_needed) {
        printf("\tsw $k3, %s\n", get_mem_loc(r));
    }
}
 
void handle_assignment(char *src, char *dest) {
    if (is_register(dest)) {
        if (is_immediate(src)) {
            printf("\tli $%s, %s\n", dest, src);
        } else if (is_register(src)) {
            printf("\tmove $%s, $%s\n", dest, src);
        } else {
            printf("\tlw $%s, %s\n", dest, get_mem_loc(src));
        }
        return;
    }
 
    char *src_reg = "$k3";
    if (is_register(src)) {
        static char tmp[512];
        sprintf(tmp, "$%s", src);
        src_reg = tmp;
    } else if (is_immediate(src)) {
        printf("\tli $k3, %s\n", src);
    } else {
        printf("\tlw $k3, %s\n", get_mem_loc(src));
    }
    
    printf("\tsw %s, %s\n", src_reg, get_mem_loc(dest));
}
 
void handle_branch(char *op_name, char *a1, char *a2, char *label) {
    char *r1 = get_input_reg(a1, "$k1");
    char *r2 = get_input_reg(a2, "$k2");
    printf("\t%s %s, %s, %s\n", op_name, r1, r2, label);
}
