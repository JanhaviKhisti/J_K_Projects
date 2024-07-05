
/**
 * File   : mv_pattern_04.c
 * Brief  : Prints pattern 4th of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 28/09/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "mv_mv_pattern_01.h"

/**
 * Function Name : mv_pattern_04
 * Description	 : This function print following pattern :-  
 *					E	E	E	E	E
 *					D	D	D	D	D
 *					C 	C	C	C	C
 *					B	B	B	B	B
 *					A	A	A	A	A
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_04()
{
	// Code

	// Initialization 
	int index = 69;

	// Outer Loop
	for(int ole = 0; ole < 5; ole++)
	{
		// Inner Loop
		for(int ile = 0; ile < 5; ile++)
		{
			// Print Characters
			printf("%c  ", index);
		}

		// New Line
		printf("\n");

		// Decrement
		index--;
	}

	return(0);
}

