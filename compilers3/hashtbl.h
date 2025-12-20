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

#ifndef HASHTBL_H_INCLUDE_GUARD
#define HASHTBL_H_INCLUDE_GUARD

#include<stdlib.h>
#include "defines.h"

HASHTBL *hashtbl_create(hash_size size, hash_size (*hashfunc)(const char *));
void hashtbl_destroy(HASHTBL *hashtbl);
int hashtbl_insert(HASHTBL *hashtbl, const char *key, char *data, int scope, array_t *arr);
int hashtbl_remove(HASHTBL *hashtbl, const char *key,int scope, array_t *arr);
void *hashtbl_get(HASHTBL *hashtbl, int scope);
struct hashnode_s *hashtbl_lookup(HASHTBL *hashtbl, int scope, const char *key);
#endif
