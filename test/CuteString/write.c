/** The string class designed for the Cute Programming Language

File: write.c

Author: Mikolaj Pawlikowski: mikolaj@pawlikowski.pl
	
Date: 14/11/2010

*/

#include <stdio.h>
#include "../../libs/CuteString.h"

int main(){

	
	string * ptr_to_string = consString("Nope");
	char buffer[512];
	
	//just to demonstrate how it handles the job
	changeStringSize(ptr_to_string , 20);

	writeString(ptr_to_string, "Hey there! q to finish !");
	printf("%s\n", ptr_to_string->data);
	
	
	while(buffer[0] != 'q'){
	
		printf("Write something and watch our beatyful string handle it's dynamic length: ");
		scanf("%s", buffer);
		writeString(ptr_to_string , buffer);
		printf("String is: %s (%d chars)\n", ptr_to_string->data, stringLength(ptr_to_string));
		if(stringToLong(ptr_to_string)){
			printf("Long detected = %d \n", stringToLong(ptr_to_string));
		}
		
	}
	
	deleteString(ptr_to_string);
	return 0;
}
