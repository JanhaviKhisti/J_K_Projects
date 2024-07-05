
/**
 * File   : mv_pattern_14.c
 * Brief  : Prints pattern 14th of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 03/10/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "mv_pattern_02.h"

/**
 * Function Name : mv_pattern_14
 * Description	 : This function print following pattern :-  
 *								D
 *							C	D
 *						B	C	D
 *					A	B	C	D
 *						B	C	D
 *							C	D
 *								D
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_14()
{
	// Code

	// Outer Loop
	for(int ole = 0; ole <= 6; ole++)
	{
		// Initialization
		int index = 65;
		// Condition 1
		if(ole <= 3)
		{
			// True Block
			// Inner Loop
			for(int ile = 3; ile >= 0; ile--)
			{
				// Nested Condition 
				if( ile > ole )
				{
					// Print Spaces
					printf("    ");
				}
				else
				{
					// Print Characters
					printf("%c   ", index);
				}

				// Increment
				index++;
			}
		}
		else
		{
			// False Block
			// Inner Loop
			for(int ile = 3; ile >= 0; ile--)
			{
				// Nested Condition
				if( ile+ole-4 > 2 )
				{
					// Print Space
					printf("    ");
				}
				else
				{
					// Print Character
					printf("%c   ", index);
				}

				// Increment
				index++;
			}
		}

		// New Line
		printf("\n");
	}

	return(0);
}

