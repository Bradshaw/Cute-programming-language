/** The array class designed for the Cute Programming Language

File: /libs/CuteArray.c

Author: Mikolaj Pawlikowski: mikolaj@pawlikowski.pl
	
Date: 19/11/2010

*/

#include "CuteCore.h"
#include "CuteArray.h"
#include "CuteString.h"
#include <stdio.h>
#include <stdlib.h>

array *createArray(){
/** mallocs a new array */

	array *new = malloc(sizeof(array));
	// creates a structure of arrayHolder.
	
	arrayBox *newData = calloc(ARRAY_STD_LENGTH, sizeof(arrayBox));
	// creates a table of arrayBox structures, to hold in things
	
	if (new != NULL) {
		if(newData != NULL){
			// if mallocs went good
			
			new->size = ARRAY_STD_LENGTH;
			new->next = 0;
			new->data = newData;
			// initialises the arrayHolder instance
			
			/* optionally sets a default value */
			for(int i=0; i < ARRAY_STD_LENGTH; i++){
				(newData + i)->type = TYPE_CHAR;
				(newData + i)->cont.c = '0';
			}
		}
	}
	return new;
}

array *copyArray(array *T){
/** mallocs a new structure, and copies its content */

	array *new = malloc(sizeof(array));
	// creates a structure of arrayHolder, initialises it.
	
	arrayBox *newData = calloc(T->size, sizeof(arrayBox));
	// creates a table of arrayBox structures, to hold in things */
	
	if (new != NULL && newData != NULL) {
		// if mallocs went good
		
		new->data = newData;
		new->next = T->next;
		new->size = T->size;
		// copy proprieties
		
		/* and copy all the values of cells */
		for(unsigned long int i = 0; i < (T->next); i++){
		
			// depending on a type of content saved
			switch ((new->data + i)->type) {
				case TYPE_CHAR: 
					setCellArray(new,  i, &((new->data + i)->cont.c), (new->data + i)->type);
					break;
				case TYPE_INTEGER:
					setCellArray(new,  i, &((new->data + i)->cont.i), (new->data + i)->type);
					break;
				case TYPE_FLOAT: 
					setCellArray(new,  i, &((new->data + i)->cont.f), (new->data + i)->type);
					break;
				/*case TYPE_STRING: 
					setCellArray(new,  i, &((new->data + i)->cont.s), (new->data + i)->type);
					break;*/
				case TYPE_ARRAY: 
					setCellArray(new,  i, &((new->data + i)->cont.a), (new->data + i)->type);
					break;
			}
		}
	}
	
	return new;
}


void deleteArray(array *T){
/** frees arrayBoxes and  array */
	free(T->data);
	free(T);
}


unsigned long int sizeArray(array *T){
/** gets a size of used part of an array */

	return T->next;
}

int resizeArray(array *T, unsigned long int to){
/** tries to reallocate memmory, doesn't create any cells */

	if(to > (T->size)){
	// is it's too short...
	
		T->data = realloc(T->data, sizeof(arrayBox));
		// try to realloc
		
		if (T->data != NULL) {
			// if realloc went well
			
			T->size = to;
			// set properties
			
			/* optionally initialise new cells */
			
			for(int i = T->size; i < to; i++){
				(T->data + i)->type = TYPE_CHAR;
				(T->data + i)->cont.c = '0';
			}
			
			return 1;
		}else{
			return 0;
		}
	}else{
		return 1;
	}
}

int joinArray(array *T1, array *T2){
/** creates e new array, containing cells from T1 and then cells from T2 */
	array *new = copyArray(T1);
	for(unsigned long int i = 0; i < T2->next; i++){
		
		// depending on a type of content saved
		switch ((new->data + i)->type) {
			case TYPE_CHAR: 
				setCellArray(new,  (new->next + i + 1), &((T2->data + i)->cont.c), (T2->data + i)->type);
				break;
			case TYPE_INTEGER:
				setCellArray(new,  (new->next + i + 1), &((T2->data + i)->cont.i), (T2->data + i)->type);
				break;
			case TYPE_FLOAT: 
				setCellArray(new,  (new->next + i + 1), &((T2->data + i)->cont.f), (T2->data + i)->type);
				break;
			/*case TYPE_STRING: 
				setCellArray(new,  (new->next + i + 1), &((T2->data + i)->cont.s), (T2->data + i)->type);
				break;*/
			case TYPE_ARRAY: 
				setCellArray(new,  (new->next + i + 1), &((T2->data + i)->cont.a), (T2->data + i)->type);
				break;
		}
	}
}

int setCellArray(array *T, unsigned long int which, void *what, char type){
/** sets a content in a cell in an array. Creates cell if it doesn't exist, resizes array if necessary */

	if(which > T->size){
		resizeArray(T, which + 10);
		// resize the array if needed
	}
	
	/* sets an appropriate value for the cell */
	switch (type) {
		case TYPE_CHAR: 
			(T->data + which)->cont.c = *((char *)what);
			break;
		case TYPE_INTEGER:
			(T->data + which)->cont.i = *((long int *)what);
			break;
		case TYPE_FLOAT: 
			(T->data + which)->cont.f = *((float *)what);
			break;
		/*case TYPE_STRING: 
			(T->data + which)->cont.s = what;
			break;*/
		case TYPE_ARRAY: 
			(T->data + which)->cont.a = (struct arrayHolder *)what;
			break;
	}
		
	(T->data + which)->type = type;
	// save the type of the content

	T->next = which + 1;
	// keep track of next property
	
	return 1;
}

char getCellTypeArray(array *T, unsigned long int which){
/** gets a type of the content of a table cell */

	if(which <= T->size && (T->data + which) != NULL){
		return T->data->type;
	}else{
		return 0;
	}
}

void getCellArray(array *T, unsigned long int which, void *where){
/** gets a content of a table cell and saves it to where */

	if(which <= T->size && (T->data + which) != NULL){
	
	/* sets an appropriate value for the cell */
	switch ((T->data + which)->type) {
		case TYPE_CHAR: 
			where = &(T->data + which)->cont.c;
			break;
		case TYPE_INTEGER:
			where = &(T->data + which)->cont.i;
			break;
		case TYPE_FLOAT: 
			where = &(T->data + which)->cont.f;
			break;
		/*case TYPE_STRING: 
			where = &(T->data + which)->cont.s;
			break;*/
		case TYPE_ARRAY: 
			where = &(T->data + which)->cont.a;
			break;
	}
	}
}


int pushArray(array *T, void *what, char type){
/** sets a content in a new cell of index: last used + 1 */
	return setCellArray(T, (T->next), what, type);
}

void printArray(array *T){
/** prints an array to stdout */

	printf("an array[%d/%d] =\t{", (int)T->next,  (int)T->size);

	for(unsigned long int i = 0; i < T->next; i++){
	
		/* printfs */
		switch ((T->data + i)->type) {
			case TYPE_CHAR: 
				printf("'%c'", (T->data + i)->cont.c);
				break;
			case TYPE_INTEGER:
				printf("%d", (int)(T->data + i)->cont.i);
				break;
			case TYPE_FLOAT: 
				printf("%f", (T->data + i)->cont.f);
				break;
			/*case TYPE_STRING: 
				printString((T->data + i)->cont.s);
				break;*/
			case TYPE_ARRAY: 
				printArray((T->data + i)->cont.a);
				break;
		}
		if(i + 1 < T->next){
			printf(", ");
		}
	}
	
	printf("}\n");
}

/*
array *splitArray(array *T, int from, int to){
	
	int actual_len = stringLength(s);

	if(from < 0) { from = 0; }
	if(from > actual_len) { from = actual_len - 1; }
	while(to < 0 ) { to = actual_len + to; }
	if(to > actual_len) { to = actual_len; }
	
	int new_len = to - from + 1;

	printf("from index set to %d and to set to %d, new len = %d.\n", from, to, new_len);
	
	
	
	return copy;
}
*/
