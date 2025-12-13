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

typedef struct {
	char *id;
	array_t *arr;
} id_t;

typedef struct IdList {
	id_t *id;
	struct IdList *next;
} id_list_t;

typedef struct {
	type_t type ;
} expr_t;

#endif
