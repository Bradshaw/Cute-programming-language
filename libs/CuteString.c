/** The string class designed for the Cute Programming Language

File: /libs/CuteString.c

Author: Mikolaj Pawlikowski: mikolaj@pawlikowski.pl
	
Date: 14/11/2010

*/

#include "CuteString.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

string *consString(const char *what){
   string *new = malloc(sizeof(*new));
   if (new != NULL) {
	new->size = strlen(what) + 1;
	new->data = strdup(what);
   }
   return new;
}

string *copyString(string *s){
   return consString(s->data);
}

void changeStringSize(string *s, int len){
	s->size = len + 1;
	s->data = realloc(s->data, (sizeof(char) * s->size));
}

void writeString(string *s, char *input){
	int needed = strlen(input);
	changeStringSize(s, needed); // this is a subject to change - we certainly dont need to reallocate teh memory each time we write to a string.
	strcpy(s->data, input);
}

void deleteString(string *s){
	free(s->data);
	free(s);
}

int stringLength(string *s){
	return s->size - 1;
}

long int stringToLong(string *s){
	return atol(s->data);
}

void joinString(string *to, string *from){
	changeStringSize(to, stringLength(to) + stringLength(from));
	strcat(to->data, from->data);
}

int stringFind(string *s, char what, int from){
	return (s->data + from - strchr(s->data + from, what));
}

string *stringSplit(string *s, int from, int to){
	
	int actual_len = stringLength(s);

	if(from < 0) { from = 0; }
	if(from > actual_len) { from = actual_len - 1; }
	while(to < 0 ) { to = actual_len + to; }
	if(to > actual_len) { to = actual_len; }
	
	int new_len = to - from + 1;

	printf("from index set to %d and to set to %d, new len = %d.\n", from, to, new_len);

	string *copy = consString(s->data + from);

	*(copy->data + new_len) = '\0'; // finishes the string

	changeStringSize(copy, new_len); // reallocates memory

	return copy;
}
