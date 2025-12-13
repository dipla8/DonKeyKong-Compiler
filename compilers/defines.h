typedef enum {
	T_INT,
	T_FLOAT,
	T_CHAR
} type_t;


typedef struct {
	type_t type ;
} expr_t;

typedef struct IdList {
char *id;
struct IdList *next;
} id_list_t;
