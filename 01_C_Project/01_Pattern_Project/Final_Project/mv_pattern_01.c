
/**
 * File   : mv_pattern_01.c
 * Brief  : Prints pattern 1st of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 28/09/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "mv_pattern_header_01.h"

/**
 * Function Name : mv_pattern_01
 * Description	 : This function print following pattern :-  
 *					*	*	*	*	*
 *					*	*	*	*	*
 *					*	*	*	*	*
 *					*	*	*	*	*
 *					*	*	*	*	*
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_01()
{
	// Code

	// Outer Loop
	for(int ole = 0; ole < 5; ole++)
	{
		// Inner Loop
		for(int ile = 0; ile < 5; ile++)
		{
			// Print Stars
			printf("*  ");
		}

		// New Line
		printf("\n");
	}

	return(0);
}

