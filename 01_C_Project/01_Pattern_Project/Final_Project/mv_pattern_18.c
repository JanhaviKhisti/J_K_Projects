
/**
 * File   : mv_pattern_18.c
 * Brief  : Prints pattern 18th of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 03/10/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "mv_pattern_header_02.h"

/**
 * Function Name : mv_pattern_18
 * Description	 : This function print following pattern :-  
 *									1
 *								2	2
 * 							3	3	3
 * 						4	4	4	4
 *					5	5	5	5	5
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_18()
{
	// Code

	// Initialization
	int index = 1;

	// Outer Loop
	for(int ole = 0; ole <= 4; ole++)
	{
		// Inner Loop
		for(int ile = 4; ile >= 0; ile--)
		{
			// Condition 1
			if( ile > ole )
			{
				// True Block 
				// Print Space
				printf("    ");
			}
			else
			{
				// False Block
				// Print Number
				printf("%d   ", index);
			}
		}

		// Increment
		index++;

		// New Line
		printf("\n");
	}

	return(0);
}

