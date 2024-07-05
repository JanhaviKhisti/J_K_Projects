
/**
 * File   : mv_pattern_02.c
 * Brief  : Prints pattern 2nd of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 28/09/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "mv_pattern_01.h"

/**
 * Function Name : mv_pattern_02
 * Description	 : This function print following pattern :-  
 *					A	A	A	A	A
 *					B	B	B	B	B
 *					C	C	C	C	C
 *					D	D	D	D	D
 *					E	E	E	E	E
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_02()
{
	// Code

	// Initialization 
	int index = 65;

	// Outer Loop 
	for(int ole = 0; ole < 5; ole++)
	{
		// Inner Loop
		for(int ile = 0; ile < 5; ile++)
		{
			// Print Characters
			printf("%c  ", index);
		}

		// New line
		printf("\n");

		// Increment
		index++;
	}

	return(0);
}

