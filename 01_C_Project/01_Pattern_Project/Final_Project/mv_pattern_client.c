
/**
 * File   : mv_pattern_client.c
 * Brief  : Contains client side  C source code
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 13/10/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "client_header.h"

// Global Data Definition
int user_input = 0;

int main(void)
{
	// Code

	// Loop for continuous printing of pattern which user wants
	while(1)
	{
		// Taking user input number 
		printf("Enter Pattern Number Between 1 to 50 : ");
		scanf("%d", &user_input);

		// Function Call for Print Pattern
		call_pattern(user_input);

		// Condition for exit 
		if(0 == user_input)
			break;
		
	}
		exit(0);

}


