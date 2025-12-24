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

int hashtbl_insert(HASHTBL *hashtbl, const char *key, char* data ,int scope, array_t *arr, int istype, int visibility)
{
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
	}

	if(!strcmp(data, "union")){
		node->un = malloc(sizeof(union_t));
		node->un->untb = hashtbl_create(4, NULL);	
	}
	else
		node->un = NULL; 
	if(!strcmp(data, "func")){
		node->func = malloc(sizeof(func_t));	
	}
	else
		node->func = NULL;

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
