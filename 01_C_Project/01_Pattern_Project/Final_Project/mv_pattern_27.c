
/**
 * File   : mv_pattern_27.c
 * Brief  : Prints pattern 27th of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 10/10/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "mv_pattern_header_03.h"

/**
 * Function Name : mv_pattern_27
 * Description	 : This function print following pattern :-  
 *					A	B	C	D	E	F	G	H	I
 *						A	B	C	D	E	F	G		
 *							A	B	C	D	E		
 *								A	B	C		
 *									A	
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_27()
{
	// Code

	// Outer Loop
	for(int ole = 0; ole <= 4; ole++)
	{
		// Initialization
		int index = 65;

		// Inner Loop
		for(int ile = 0; ile <= 9; ile++)
		{
			// Conditions
			if(ile >= ole && ile+ole <= 8)
			{
				// True Block
				// Print Character
				printf("%c   ", index);

				// Increment
				index++;
			}
			else
			{
				// False Block 
				// Print Space
				printf("    ");
			}
		}

		// New Line
		printf("\n");
	}

	return(0);
}

