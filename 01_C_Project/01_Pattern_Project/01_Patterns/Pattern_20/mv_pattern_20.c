
/**
 * File   : mv_pattern_20.c
 * Brief  : Prints pattern 20th of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 03/10/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "mv_pattern_02.h"

/**
 * Function Name : mv_pattern_20
 * Description	 : This function print following pattern :-  
 *					D
 *					D	C
 *					D	C	B
 *					D	C	B	A
 *					D	C	B	
 *					D	C	
 *					D	
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_20()
{
	// Code

	// Outer Loop
	for(int ole = 0; ole < 8; ole++)
	{
		// Initialization
		int index = 68; 

		// Condition 1
		if(ole < 5)
		{
			// True Block
			// Inner Loop
			for(int ile = 0; ile < ole; ile++)
			{
				// Print Character
				printf("%c  ", index);

				// Decrement
				index--;
			}
		}
		else
		{
			// False Block
			// Inner Loop
			for(int ile = 8; ile > ole; ile--)
			{
				// Print Character
				printf("%c  ", index);

				// Decrement
				index--;
			}
		}

		// New Line
		printf("\n");
	}

	return(0);
}

