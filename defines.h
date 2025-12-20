#ifndef DEFINES_H
#define DEFINES_H

#define MAX_DIMENSIONS 5

typedef enum {
	T_CHAR,
	T_INT,
	T_FLOAT,
	T_VOID,
	T_ID
} type_t;

typedef struct {
	int dims;
	int dim_size[MAX_DIMENSIONS];
} array_t;
typedef union {
	float fval;
	int ival;
	char cval;
} union_const;
typedef struct {
	char *id;
	array_t *arr;
} my_id_t;

typedef struct IdList {
	my_id_t *id;
	struct IdList *next;
} id_list_t;

typedef struct {
	type_t type ;
	union_const val;
} expr_t;

void var_decl(id_list_t *var_list, int type);
void var_to_expr(expr_t *expr, int type);
#endif
