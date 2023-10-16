
/**
 * File   : mv_pattern_47.c
 * Brief  : Prints pattern 47th of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 10/10/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "mv_pattern_header_05.h"


/**
 * Function Name : mv_pattern_47
 * Description	 : This function print following pattern :-  
 *					*												*
 *					*	*										*	*
 *					*	*	*								*	*	*
 *					*	*	*	*						*	*	*	*
 *					*	*	*	*	*				*	*	*	*	*
 *					*	*	*	*	*	*		*	*	*	*	*	*
 *					*	*	*	*	*	*	*	*	*	*	*	*	*
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_47()
{
	// Code

	// Outer Loop
	for(int ole = 0; ole <= 6; ole++)
	{
		// Inner Loop
		for(int ile = 0; ile <= 12; ile++)
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

