
/**
 * File   : mv_pattern_11.c
 * Brief  : Prints pattern 11th of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 03/10/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "mv_pattern_header_02.h"

/**
 * Function Name : mv_pattern_11
 * Description	 : This function print following pattern :-  
 *					*
 *					*	*
 *					*	*	*
 *					*	*	*	*
 *					*	*	*
 *					*	*
 *					*
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_11()
{
	// Code

	// Outer Loop
	for(int ole = 0; ole < 8; ole++)
	{
		// Condition 1
		if(ole < 5)
		{
			// True Block
			// Inner Loop
			for(int ile = 0; ile < ole; ile++)
			{
				// Print Star
				printf("*  ");
		
			}
		}
		else
		{
			// False Block
			// Inner Loop
			for(int ile = 8; ile > ole; ile--)
			{
				// Print Star
				printf("*  ");
	
			}
		}

		// New Line
		printf("\n");
	}

	return(0);
}

