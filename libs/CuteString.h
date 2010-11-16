/** The string class designed for the Cute Programming Language

File: /libs/CuteString.h

Author: Mikolaj Pawlikowski: mikolaj@pawlikowski.pl
	
Date: 14/11/2010

*/

#ifndef CuteString
#define CuteString

typedef struct stringContainer{
	unsigned long int size;
	char *data;
} string;

/** Main string structure */

string *consString(const char *what);
/** string constructor */

string *copyString(string *s);
/** string copier */

void deleteString(string *s);
/** frees memory allocated */



void changeStringSize(string *s, int length);
/** resizes the memory allocated fo the string */

void writeString(string *s, char *input);
/** writes to a streen at the start offset */

void joinString(string *s1, string *s2);
/** merges two strings: s1 + s2 */



int stringLength(string *s);
/** returns string length */

long int stringToLong(string *s);
/** returns long from a string*/

int stringFind(string *s, char what, int from);
/** returns index of the first occurence of char what in string s */

string *stringSplit(string *s, int from, int to);
/** returns a new string, containing chars between from and to */

#endif
