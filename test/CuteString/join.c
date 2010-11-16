/** The string class designed for the Cute Programming Language

File: join.c

Author: Mikolaj Pawlikowski: mikolaj@pawlikowski.pl
	
Date: 14/11/2010

*/

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "../../libs/CuteString.h"

int main(){

	
	string * ptr_to_string = consString("Something that will be erased anyway");
	string * ptr_to_string2 = consString("");
	char buffer[512];

	writeString(ptr_to_string, "Hey there! q to finish !");
	printf("%s\n", ptr_to_string->data);
	
	
	while(buffer[0] != 'q'){
	
		printf("Write something: "); scanf("%s", buffer);
		
		
		writeString(ptr_to_string, buffer);
		printf("String is: %s (%d chars)\n", ptr_to_string->data, stringLength(ptr_to_string));
		
		joinString(ptr_to_string2, ptr_to_string);
		printf("Concat is: %s (%d chars)\n", ptr_to_string2->data, stringLength(ptr_to_string2));
		
	}
	
	deleteString(ptr_to_string);
	deleteString(ptr_to_string2);
	return 0;
}
