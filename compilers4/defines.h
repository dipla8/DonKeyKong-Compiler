#ifndef DEFINES_H
#define DEFINES_H
#define MAX_DIMENSIONS 15

#include <stdlib.h>

typedef size_t hash_size;

typedef struct asd_st{
	char* name;
	struct asd_st *lchild;
	struct asd_st *rchild;
} asd_t;

typedef struct {
	int islist;
	int *listsize;
	int dims;
	int dim_size[MAX_DIMENSIONS];
} array_t;

typedef struct hashtbl {
        hash_size size;
        struct hashnode_s **nodes;
        hash_size (*hashfunc)(const char *);
} HASHTBL;
typedef struct{
	HASHTBL *classtb;
	char *superclass;
}class_t;

typedef struct{
	HASHTBL *untb;
}union_t;

typedef struct MyList {
	char* type;
	array_t *arr;
	struct MyList *next;
} par_list_t;

typedef struct {
	int header_declared;
	char* ret_type;
	par_list_t *node;
}func_t;

struct hashnode_s {
        char *key;
        char *data;
        int scope;
        array_t *arr;
	class_t *cla;
	union_t *un;
	func_t *func;
	int istype;
        int visibility;
	struct hashnode_s *next;
};

typedef enum {
	T_CHAR,
	T_INT,
	T_FLOAT,
	T_VOID,
	T_ID
} type_t;

typedef union {
	float fval;
	int ival;
	char cval;
} union_const
;
typedef struct {
	char *id;
	array_t *arr;
	char *data;
} my_id_t;

typedef struct IdList {
	my_id_t *id;
	struct IdList *next;
} id_list_t;

typedef struct {
	type_t type;
	union_const val;	// address
	int rec_count;
	struct hashnode_s *n;
	asd_t *node;
} expr_t;
typedef struct explist{
	expr_t *exp;
	int listsize;
	struct explist *next;
}expr_list_t;

typedef struct {
	char* type;
	char* name;
}header_t;

HASHTBL *hashtbl_create(hash_size size, hash_size (*hashfunc)(const char *));
void hashtbl_destroy(HASHTBL *hashtbl);
int hashtbl_insert(HASHTBL *hashtbl, const char *key, char *data, int scope, array_t *arr, int istype, int visibility);
int hashtbl_remove(HASHTBL *hashtbl, const char *key,int scope, array_t *arr);
void *hashtbl_get(HASHTBL *hashtbl, int scope);
struct hashnode_s *hashtbl_lookup(HASHTBL *hashtbl, int scope, const char *key, int perm);
void var_decl(id_list_t *var_list, char* data);
void var_to_expr(expr_t *expr, char* name);
void header_decl_check(HASHTBL *hashtbl);
#endif
