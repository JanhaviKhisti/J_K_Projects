
/**
 * File   : mv_pattern_29.c
 * Brief  : Prints pattern 29th of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 10/10/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "mv_mv_pattern_03.h"


/**
 * Function Name : mv_pattern_29
 * Description	 : This function print following pattern :-  
 *					E	E	E	E	E	E	E	E	E
 *						D	D	D	D	D	D	D		
 *							C	C	C	C	C		
 *								B	B	B		
 *									A
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_29()
{
	// Code

	// Initialization 
	int index = 69;

	// Outer Loop
	for(int ole = 0; ole <= 4; ole++)
	{
		// Inner Loop
		for(int ile = 0; ile <= 9; ile++)
		{
			// Conditions
			if(ile >= ole && ile+ole <= 8)
			{
				// True Block
				// Print Character
				printf("%c   ", index);
			}
			else
			{
				// False Block
				// Print Space
				printf("    ");
			}
		}
		// Decrement
		index--;

		// New Line
		printf("\n");
	}

	return(0);
}

