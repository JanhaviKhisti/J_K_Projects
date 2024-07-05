
/**
 * File   : mv_pattern_25.c
 * Brief  : Prints pattern 25th of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 10/10/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "mv_pattern_03.h"

/**
 * Function Name : mv_pattern_25
 * Description	 : This function print following pattern :-  
 * 									1
 *								3	3	3
 *							5	5	5	5	5
 *						7	7	7	7	7	7	7
 *					9	9	9	9	9	9	9	9	9
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_25()
{
	// Code 

	// Initialization
	int index = 1;

	// Outer Loop
	for(int ole = 4; ole >= 0; ole--)
	{
		// Inner Loop
		for(int ile = 8; ile >= 0; ile--)
		{
			// Conditions
			if(ile >= ole && ile+ole <= 8)
			{
				// True Block 
				// Print Number
				printf("%d   ", index);
			}
			else
			{
				// False Block
				// Print Space
				printf("    ");
			}
		}
		// Increment
		index = index + 2;

		// New Line
		printf("\n");
	}

	return(0);
}

