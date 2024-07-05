
/**
 * File   : mv_pattern_33.c
 * Brief  : Prints pattern 33th of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 10/10/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "mv_pattern_04.h"

/**
 * Function Name : mv_pattern_33
 * Description	 : This function print following pattern :-  
 *					5		 		 		 		5
 * 						4		 		 		4
 * 							3		 		3
 *								2		2
 *									1
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_33()
{
	// Code

	// Initialization
	int index = 5;

	// Outer Loop
	for(int ole = 0; ole <= 4; ole++)
	{
		// Inner Loop
		for(int ile = 0; ile <= 9; ile++)
		{
			// Condition 1
			if(ile == ole && ile+ole <= 8)
			{
				// True Block
				// Print Number
				printf("%d   ", index);
			}
			// Condition 2
			else if(ile+ole == 8)
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
		// Decrement
		index--;

		// New Line
		printf("\n");
	}

	return(0);
}

