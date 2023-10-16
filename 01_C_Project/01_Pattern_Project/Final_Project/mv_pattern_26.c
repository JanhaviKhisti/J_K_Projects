
/**
 * File   : mv_pattern_26.c
 * Brief  : Prints pattern 26th of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 10/10/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "mv_pattern_header_03.h"

/**
 * Function Name : mv_pattern_26
 * Description	 : This function print following pattern :-  
 *					*	*	*	*	*	*	*	*	*
 *						*	*	*	*	*	*	*		
 *							*	*	*	*	*		
 *								*	*	*		
 *									*
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_26()
{
	// Code

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
				// Print Star
				printf("*   ");
			}
			else
			{
				// False Block
				printf("    ");
			}
		}

		// New Line
		printf("\n");
	}

	return(0);
}

