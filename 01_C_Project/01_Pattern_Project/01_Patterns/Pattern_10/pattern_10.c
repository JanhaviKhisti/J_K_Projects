
/**
 * File   : mv_pattern_10.c
 * Brief  : Prints pattern 10th of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 03/10/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "mv_mv_pattern_01.h"

/**
 * Function Name : mv_pattern_10
 * Description	 : This function print following pattern :-  
 *  				5   4   3   2   1
 *  				5   4   3   2
 *  				5   4   3
 *  				5   4
 *  				5
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_10()
{
	// Code

	// Outer Loop
	for(int ole = 5; ole > 0; ole--)
	{
		// Initialization
		int index = 5; 

		// Inner Loop
		for(int ile = 0; ile < ole; ile++)
		{
			// Print Numbers
			printf("%d  ", index);

			// Decrement
			index--;
		}

		// New Line 
		printf("\n");
	}

	return(0);
}

