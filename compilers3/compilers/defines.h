typedef enum {
	T_CHAR,
	T_INT,
	T_FLOAT,
	T_VOID,
	T_ID
} type_t;


typedef struct {
	type_t type ;
} expr_t;

typedef struct IdList {
char *id;
struct IdList *next;
} id_list_t;
