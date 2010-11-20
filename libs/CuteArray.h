/** The string class designed for the Cute Programming Language

File: /libs/CuteArray.h

Author: Mikolaj Pawlikowski: mikolaj@pawlikowski.pl
	
Date: 19/11/2010

*/

#ifndef CuteArray
#define CuteArray

#include "CuteCore.h"
#include "CuteString.h"

/* STRUCTURES */
typedef struct arrayDataContainerHolder{
	char type;
	union {
		char c;
		long int i;
		float f;
		//string *s;
		struct ArrayHolder *a;
	} cont;
} arrayBox;

typedef struct arrayHolder{
	unsigned long int size;
	unsigned long int next;
	arrayBox *data;
} array;


/* CONSTRUCTORS */
array *createArray();
/** mallocs a new array */

array *copyArray(array *T);
/** mallocs a new structure, and copies its content */

void deleteArray(array *T);
/** frees dContainers, arrayBoxes and finally array */


/* MANIPULATORS */
unsigned long int sizeArray(array *T);
/** gets a size of used part of an array */

int resizeArray(array *T, unsigned long int to);
/** tries to reallocate memmory, doesn't create any cells */

int joinArray(array *T1, array *T2);
/** creates e new array, containing cells from T1 and then cells from T2 */

int setCellArray(array *T, unsigned long int which, void *what, char type);
/** sets a content in a cell in an array. Creates cell if it doesn't exist, resizes array if necessary */

char getCellTypeArray(array *T, unsigned long int which);
/** gets a type of the content of a table cell */

void getCellArray(array *T, unsigned long int which, void *where);
/** gets a content of a table cell */

int pushArray(array *T, void *what, char type);
/** sets a content in a new cell of index: last used + 1 */


/* UTILITIES */
void printArray(array *T);
/** prints an array to stdout */

#endif
