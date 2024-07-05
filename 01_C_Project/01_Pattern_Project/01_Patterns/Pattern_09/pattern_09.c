
/**
 * File   : mv_pattern_09.c
 * Brief  : Prints pattern 9th of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 28/09/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "mv_pattern_01.h"

/**
 * Function Name : mv_pattern_09
 * Description	 : This function print following pattern :-  
 *					A	A	A	A	A
 *					B	B	B	B
 *					C	C	C
 *					D	D
 *					E
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_09()
{
	// Code

	// Initialization
	int index = 65;

	// Outer Loop
	for(int ole = 5; ole > 0; ole--)
	{ 
		// Inner Loop
		for(int ile = 0; ile < ole; ile++)
		{
			// Print Characters
			printf("%c  ", index);
		}
		// Increment
		index++;

		// New Line
		printf("\n");
	}

	return(0);
}

