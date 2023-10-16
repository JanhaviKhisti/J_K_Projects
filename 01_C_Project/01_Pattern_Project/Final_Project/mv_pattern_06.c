
/**
 * File   : mv_pattern_06.c
 * Brief  : Prints pattern 6th of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 28/09/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "mv_pattern_header_01.h"

/**
 * Function Name : mv_pattern_06
 * Description	 : This function print following pattern :-  
 *					*
 *					*	*
 *					*	*	*
 *					*	*	*	*
 *					*	*	*	*	*
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_06()
{
	// Code

	// Outer Loop 
	for(int ole = 5; ole >= 0; ole--)
	{
		// Inner Loop 
		for(int ile = ole; ile < 5; ile++)
		{
			// Print Star
			printf("*  ");
		}
		// New Line 
		printf("\n");
	}

	return(0);
}

