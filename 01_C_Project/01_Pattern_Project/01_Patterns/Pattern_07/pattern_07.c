
/**
 * File   : mv_pattern_07.c
 * Brief  : Prints pattern 7th of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 28/09/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "mv_pattern_01.h"

/**
 * Function Name : mv_pattern_07
 * Description	 : This function print following pattern :-  
 * 					1
 *  				1   2
 *  				1   2   3
 *  				1   2   3   4
 *  				1   2   3   4   5
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_07()
{
	// Code

	// Outer Loop
	for(int ole = 0; ole < 5; ole++)
	{ 
		// Initialization
		int index = 1;

		// Inner Loop
		for(int ile = 0; ile <= ole; ile++)
		{
			// Print Numbers
			printf("%d  ", index);

			// Increment
			index++;
		}

		// New Line
		printf("\n");
	}

	return(0);
}


