
/**
 * File   : mv_pattern_30.c
 * Brief  : Prints pattern 30th of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 10/10/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "mv_pattern_03.h"

/**
 * Function Name : mv_pattern_30
 * Description	 : This function print following pattern :-  
 *					I	I	I	I	I	I	I	I	I
 *						G	G	G	G	G	G	G		
 *							E	E	E	E	E		
 *								C	C	C		
 *									A
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_30()
{
	// Code

	// Initialization
	int index = 73;

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
		index = index -2;

		// New Line
		printf("\n");
	}

	return(0);
}

