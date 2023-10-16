
/**
 * File   : mv_pattern_21.c
 * Brief  : Prints pattern 21th of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 10/10/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "mv_pattern_header_03.h"

/**
 * Function Name : mv_pattern_21
 * Description	 : This function print following pattern :-  
 * 									*			
 *								*	*	*			
 *							*	*	*	*	*		
 *						*	*	*	*	*	*	*		
 *					*	*	*	*	*	*	*	*	*
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_21()
{
	// Code

	// Outer Loop
	for(int ole = 4; ole >= 0; ole--)
	{
		// Inner Loop
		for(int ile = 8; ile >= 0; ile--)
		{
			// Condition 1
			if(ile >= ole && ile+ole <= 8)
			{
				// True Block
				// Print Star
				printf("*   ");
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

