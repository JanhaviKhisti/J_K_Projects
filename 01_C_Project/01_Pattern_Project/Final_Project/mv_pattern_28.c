
/**
 * File   : mv_pattern_28.c
 * Brief  : Prints pattern 28th of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 10/10/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "mv_pattern_header_03.h"

/**
 * Function Name : mv_pattern_28
 * Description	 : This function print following pattern :-  
 *					1	2	3	4	5	6	7	8	9
 *						1	2	3	4	5	6	7		
 *							1	2	3	4	5		
 *								1	2	3		
 *									1
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_28()
{
	// Code

	// Outer Loop
	for(int ole = 0; ole <= 4; ole++)
	{
		// Initialization
		int index = 1;

		// Inner Loop
		for(int ile = 0; ile <= 9; ile++)
		{
			// Conditions
			if(ile >= ole && ile+ole <= 8)
			{
				// True Block
				// Print Number
				printf("%d   ", index);

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

