
/**
 * File   : mv_pattern_46.c
 * Brief  : Prints pattern 46th of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 10/10/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "mv_pattern_05.h"

/**
 * Function Name : mv_pattern_46
 * Description	 : This function print following pattern :-  
 *					*	*	*	*	*	*	*	*	*	*	*	*	*
 *					*	*	*	*	*	*		*	*	*	*	*	*
 *					*	*	*	*	*				*	*	*	*	*
 *					*	*	*	*						*	*	*	*
 *					*	*	*								*	*	*
 *					*	*										*	*
 *					*												*
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_46()
{
	// Code

	// Outer Loop
	for(int ole = 6; ole >= 0; ole--)
	{
		// Inner Loop
		for(int ile = 12; ile >= 0; ile--)
		{
			// Conditions
			if(ile > ole && ile+ole <= 11)
			{
				// True Block
				// Print Space
				printf("    ");
			}
			else
			{
				// False Block
				// Print Star
				printf("*   ");
			}
		}

		// New Line
		printf("\n");
	}

	return(0);
}

