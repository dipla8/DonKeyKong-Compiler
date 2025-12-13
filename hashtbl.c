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

#include"hashtbl.h"
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

int hashtbl_insert(HASHTBL *hashtbl, const char *key, char* data ,int scope, array_t *arr)
{
	struct hashnode_s *node;
	hash_size hash=hashtbl->hashfunc(key)%hashtbl->size;

	printf("\t\t\t\t\tHASHTBL_INSERT(): KEY = %s, HASH = %ld,  \tDATA = %s, SCOPE = %d\n", key, hash, data, scope);

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

	if (arr != NULL){
		node->arr = malloc(sizeof(array_t));
		memcpy(node->arr, arr, sizeof(array_t));
	} else {
		node->arr = NULL;
	}

	node->scope = scope;
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

int hashtbl_lookup(HASHTBL *hashtbl, int scope, const char* key){
	struct hashnode_s *node;
	hash_size hash=hashtbl->hashfunc(key)%hashtbl->size;
	node=hashtbl->nodes[hash];
	while(node) {
		if(!strcmp(node->key, key) && (node->scope == scope)) {
			if(!strcmp(node->data, "char"))
				return 0;
			else if(!strcmp(node->data, "int"))
				return 1;
			else if(!strcmp(node->data, "float"))
				return 2;
			else if(!strcmp(node->data, "void"))
				return 3;
			else return 4;
		}
		node=node->next;
	}
	return -1;
}
