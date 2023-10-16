
/**
 * File   : mv_pattern_16.c
 * Brief  : Prints pattern 16th of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 03/10/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "mv_pattern_header_02.h"

/**
 * Function Name : mv_pattern_16
 * Description	 : This function print following pattern :-  
 *									*
 *								*	*
 * 							*	*	*
 * 						*	*	*	*
 *					*	*	*	*	*
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_16()
{
	// Code 

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
				// Print Star
				printf("*   ");
			}
		}

		// New Line
		printf("\n");
	}

	return(0);
}

