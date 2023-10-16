
/**
 * File   : mv_pattern_12.c
 * Brief  : Prints pattern 12th of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 03/10/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "mv_pattern_header_02.h"

/**
 * Function Name : mv_pattern_12
 * Description	 : This function print following pattern :-  
 *					D
 *					C	D
 *					B	C	D
 *					A	B	C	D
 *					B	C	D	
 *					C	D	
 *					D
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_12()
{
	// Code

	// Initialization
	int index = 69;

	// Outer Loop
	for(int ole = 0; ole < 8; ole++)
	{
		// Condition 1
		if(ole < 5)
		{
			// True Block
			index = index - ole;

			// Inner Loop
			for(int ile = 0; ile < ole; ile++)
			{
				// Print Character
				printf("%c   ", index);

				// Increment
				index++;
			}
		}
		// Condition 2
		if(ole >= 5)
		{
			// True Block
			index = 61 + ole;

			// Inner Loop
			for(int ile = 8; ile > ole; ile--)
			{
				// Print Character
				printf("%c   ", index);
				
				// Increment
				index++;
			}
		}

		// New Line
		printf("\n");
	}

	return(0);
}

