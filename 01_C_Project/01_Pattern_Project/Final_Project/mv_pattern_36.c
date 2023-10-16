
/**
 * File   : mv_pattern_36.c
 * Brief  : Prints pattern 36th of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 10/10/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "mv_pattern_header_04.h"

/**
 * Function Name : mv_pattern_36
 * Description	 : This function print following pattern :-  
 *									A
 *								B		B
 * 							C		 		C
 * 						D		 		 		D
 *					E		 		 		 		E
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_36()
{
	// Code

	// Initialization
	int index = 65;

	// Outer Loop
	for(int ole = 4; ole >= 0; ole--)
	{
		// Inner Loop
		for(int ile = 8; ile >= 0; ile--)
		{
			// Condition 1
			if(ile == ole && ile+ole <= 8)
			{
				// True Block
				// Print Character
				printf("%c   ", index);
			}
			// Condition 2
			else if(ile+ole == 8)
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
		// Increment
		index++;

		// New Line
		printf("\n");
	}

	return(0);
}

