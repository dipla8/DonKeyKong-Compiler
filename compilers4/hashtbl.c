/* The authors of this work have released all rights to it and placed it
in the public domain under the Creative Commons CC0 1.0 waiver
(http://creativecommons.org/publicdomain/zero/1.0/).

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Retrieved from: http://en.literateprograms.org/Hash_table_(C)?oldid=19638
*/

#include "defines.h"
#include<string.h>
#include<stdio.h>

static char *mystrdup(const char *s)
{
	char *b;
	if(!(b=malloc(strlen(s)+1))) return NULL;
	strcpy(b, s);
	return b;
}

static hash_size def_hashfunc(const char *key)
{
	hash_size hash=0;
	
	while(*key) hash+=(unsigned char)*key++;

	return hash;
}

HASHTBL *hashtbl_create(hash_size size, hash_size (*hashfunc)(const char *))
{
	HASHTBL *hashtbl;

	if(!(hashtbl=malloc(sizeof(HASHTBL)))) return NULL;

	if(!(hashtbl->nodes=calloc(size, sizeof(struct hashnode_s*)))) {
		free(hashtbl);
		return NULL;
	}

	hashtbl->size=size;

	if(hashfunc) hashtbl->hashfunc=hashfunc;
	else hashtbl->hashfunc=def_hashfunc;

	return hashtbl;
}

void hashtbl_destroy(HASHTBL *hashtbl)
{
	hash_size n;
	struct hashnode_s *node, *oldnode;
	array_t *prt;
	
	for(n=0; n<hashtbl->size; ++n) {
		node=hashtbl->nodes[n];
		while(node) {
			free(node->key);
			free(node->data);
			prt = node->arr;
			if(prt != NULL)
				free(prt);
			oldnode=node;
			node=node->next;
			free(oldnode);
		}
	}
	free(hashtbl->nodes);
	free(hashtbl);
}

int hashtbl_insert(HASHTBL *hashtbl, const char *key, char* data ,int scope, array_t *arr, int istype, int visibility, init_vals *init, bindf** list){
	struct hashnode_s *node;
	hash_size hash=hashtbl->hashfunc(key)%hashtbl->size;

	printf("\t\t\t\t\tHASHTBL_INSERT(): KEY = %s, HASH = %ld,  DATA = %s, SCOPE = %d, ISTYPE = %d, VIS = %d\n", key, hash, data, scope, istype, visibility);
	
	node=hashtbl->nodes[hash];
	while(node) {
		if(!strcmp(node->key, key) && (node->scope == scope)) {
			node->data=data;
			return 0;
		}
		node=node->next;
	}

	if(!(node=malloc(sizeof(struct hashnode_s)))) return -1;

	if(!(node->key=mystrdup(key))) {
		free(node);
		return -1;
	}
	
	if(!(node->data=mystrdup(data))) {
		free(node);
		return -1;
	}
	node->visibility = visibility;
	if(!strcmp(data, "class")){
		node->cla = malloc(sizeof(class_t));
		node->cla->classtb = hashtbl_create(5, NULL);	
		bindf* tmp = malloc(sizeof(bindf));
		tmp->next = NULL;
		tmp->head = NULL;
		tmp->name = malloc(20);
		tmp->name[0] = 'c';
		strcpy(&tmp->name[1], key);
 		//tmp->name = strdup(key);
		
		if (*list == NULL)
			*list = tmp;
		else {
			bindf *next = *list;
			while (next->next)
				next = next->next;
			next->next = tmp;		
		}
	}
	if(!strcmp(data, "union")){
		node->un = malloc(sizeof(union_t));
		node->un->untb = hashtbl_create(4, NULL);	
	}
	else
		node->un = NULL; 
	if(!strcmp(data, "#")){
		node->func = malloc(sizeof(func_t));	
		node->funcsize = 8;
		bindf* tmp = malloc(sizeof(bindf));
		tmp->next = NULL;
		tmp->head = NULL;
		tmp->name = malloc(20);
		tmp->name[0] = 'f';
		strcpy(&tmp->name[1], key);
 		//tmp->name = strdup(key);
		
		if (*list == NULL)
			*list = tmp;
		else {
			bindf *next = *list;
			while (next->next)
				next = next->next;
			next->next = tmp;		
		}
	}	
	else
		node->func = NULL;
	node->init = init;
	struct hashnode_s *p = hashtbl_lookup(hashtbl, scope, data, 0);
	printf("RIGHT AFTR LOOKUP\n");
	if(p != NULL){
		if(p->cla != NULL){
			node->cla = malloc(sizeof(class_t));
			node->cla->classtb = p->cla->classtb;
			if(p->cla->superclass)
				node->cla->superclass = strdup(p->cla->superclass);
		}
		if(p->arr != NULL){
			node->arr = malloc(sizeof(array_t));
			memcpy(node->arr, p->arr, sizeof(array_t));
		}
		if(arr != NULL){
			if(node->arr == NULL){
				node->arr = malloc(sizeof(array_t));
				node->arr->dims = 0;
			}
			for(int i= node->arr->dims; i<node->arr->dims + arr->dims; i++)
				node->arr->dim_size[i] = arr->dim_size[i - node->arr->dims];
			node->arr->dims = node->arr->dims + arr->dims;
		}
	}
	else if (arr != NULL){
			node->arr = malloc(sizeof(array_t));
			memcpy(node->arr, arr, sizeof(array_t));
		} 
	else node->arr = NULL;
	node->scope = scope;
	node->istype = istype;
	node->next=hashtbl->nodes[hash];
	hashtbl->nodes[hash]=node;
	
	return 0;
}

int hashtbl_remove(HASHTBL *hashtbl, const char *key,int scope, array_t *arr)
{
	struct hashnode_s *node, *prevnode=NULL;
	hash_size hash=hashtbl->hashfunc(key)%hashtbl->size;
	node=hashtbl->nodes[hash];
	while(node) {
		if((!strcmp(node->key, key)) && (node->scope == scope)) {
			free(node->key);
			free(node->data);
			if (node->arr != NULL)
				free(node->arr);
			if(prevnode) prevnode->next=node->next;
			else hashtbl->nodes[hash]=node->next;
			free(node);
			return 0;
		}
		prevnode=node;
		node=node->next;
	}

	return -1;
}

void *hashtbl_get(HASHTBL *hashtbl, int scope)
{
	int rem;
	hash_size n;
	struct hashnode_s *node, *oldnode;
		
	for(n=0; n<hashtbl->size; ++n) {
		node=hashtbl->nodes[n];
		while(node) {
			if(node->scope == scope) {
				printf("\t\t\t\t\tHASHTBL_GET():\tSCOPE = %d, KEY = %s,  \tDATA = %s\n", node->scope, node->key, (char*)node->data);
				oldnode = node;
				node=node->next;
				rem = hashtbl_remove(hashtbl, oldnode->key, scope, oldnode->arr);
			}else
				node=node->next;
		}
	}
	if (rem == -1)
		printf("\t\t\t\t\tHASHTBL_GET():\tThere are no elements in the hash table with this scope!\n\t\tSCOPE = %d\n", scope);
	
	return NULL;
}
int findsize2(struct hashnode_s *n, HASHTBL *hashtbl, int scope){
	int mul = 1, tally=0;
	struct hashnode_s *temp;
	if(n == NULL)
		return 0;
	if(n->arr != NULL)
		for(int i = 0; i < n->arr->dims; i++)
			mul = mul * n->arr->dim_size[i];
	if(n->cla != NULL){
		for(int i=0; i < 5; i++){
			temp = n->cla->classtb->nodes[i];
			while(temp){
				tally = tally + findsize2(temp, n->cla->classtb, scope);
				temp = temp->next;
			}
		}
	}
				 
	if (!strcmp(n->data,"int"))
		return sizeof(int)*mul;
	else if (!strcmp(n->data,"char"))
		return sizeof(char)*mul;
	else if (!strcmp(n->data, "float"))
		return sizeof(float)*mul;
	else {
		struct hashnode_s *tmp;
		tmp = hashtbl_lookup(hashtbl, scope, n->data, 5);
		return (findsize2(tmp, hashtbl, scope) * mul + tally);
	} 
	return 0;
}
int findsize3(struct hashnode_s *n, HASHTBL *hashtbl, int scope){
	int mul = 1;
	if(n->arr != NULL)
		for(int i = 0; i < n->arr->dims; i++)
			mul = mul * n->arr->dim_size[i];
	if (!strcmp(n->data,"int"))
		return mul;
	else if (!strcmp(n->data,"char"))
		return mul;
	else if (!strcmp(n->data, "float"))
		return mul;
	else {
		struct hashnode_s *tmp;
		tmp = hashtbl_lookup(hashtbl, scope, n->data, 5);
		return (findsize2(tmp, hashtbl, scope) * mul);
	} 
	return 0;
}
void print_top(FILE* fd, HASHTBL *hashtbl){
	fprintf(fd, ".data\n");
	//fprintf(fd, "\tindex: .space 4\n");
	//fprintf(fd, "\tstride: .space 4\n");
	hash_size n;
	struct hashnode_s *node, *oldnode;	
	for(n=0; n<hashtbl->size; ++n) {
		node=hashtbl->nodes[n];
		while(node) {
			if(node->scope == 0 && strcmp(node->data, "#") && strcmp(node->data, "class")) {
				if(node->init == NULL)
					fprintf(fd, "\t%s: .space %d\n", node->key, findsize2(node, hashtbl, 0));
				else{
					int real_size = findsize3(node, hashtbl, 0);
					init_vals *temp = node->init;
					fprintf(fd, "\t%s: .word", node->key);
					for(int i = 0; i < real_size; i++){
						if(temp != NULL){
							if(temp->type == T_CHAR)
								fprintf(fd, " %c", temp->val.cval);
							if(temp->type == T_INT)
								fprintf(fd, " %d", temp->val.ival);
							if(temp->type == T_FLOAT)
								fprintf(fd, " %f", temp->val.fval);
							temp = temp->next;
						}
						else{
							if(node->init->type == T_CHAR)
								fprintf(fd, "\\0");
							else fprintf(fd, " 0");
						}
						if(i != real_size - 1)
							fprintf(fd, ",");
					}
					fprintf(fd,"\n");
				}
				oldnode = node;
				node=node->next;
			}else node=node->next;
		}
	}
	fprintf(fd, ".text\n");
	fprintf(fd, "\t.globl main");
	for(n=0; n<hashtbl->size; ++n) {
		node=hashtbl->nodes[n];
		while(node) {
			if(node->scope == 0 && !strcmp(node->data, "#") && strcmp(node->key, "main"))
				fprintf(fd, ", %s",node->key);
			node = node->next;
		}
	}
	fprintf(fd, "\n");
}
void print_txt(FILE* fd, HASHTBL *hashtbl){
	hash_size n;
	struct hashnode_s *node, *oldnode;
	for(n=0; n<hashtbl->size; ++n) {
		node=hashtbl->nodes[n];
		while(node) {
			if(!strcmp(node->data, "#")){
				fprintf(fd, "%s:\n", node->key);
				fprintf(fd, "\taddi $sp, $sp, -%d\n", node->funcsize);
				fprintf(fd, "\tsw $ra, %d($sp)\n", node->funcsize-4);
				fprintf(fd, "\tsw $fp, %d($sp)\n", node->funcsize-8);
				fprintf(fd, "\taddi $fp, $sp, %d\n", node->funcsize);
				fprintf(fd, "\n\trest goes here\n\n");
				fprintf(fd, "\tlw $ra, %d($sp)\n", node->funcsize-4);
				fprintf(fd, "\tlw $fp, %d($sp)\n", node->funcsize-8);
				fprintf(fd, "\taddi $sp, $sp, %d\n", node->funcsize);
				fprintf(fd, "\tj $ra\n");
				
			}
			oldnode = node;
			node=node->next;
		}
	}
}
struct hashnode_s *hashtbl_lookup(HASHTBL *hashtbl, int scope, const char* key, int perm){
	struct hashnode_s *node;
	hash_size hash=hashtbl->hashfunc(key)%hashtbl->size;
	node=hashtbl->nodes[hash];
	while(node) {
		if(!strcmp(node->key, key) && (node->scope <= scope) && node->visibility <= perm) {
			return node;
		}	
		node=node->next;
	}
	
	return NULL;
}
