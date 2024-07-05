
/**
 * File   : mv_pattern_15.c
 * Brief  : Prints pattern 15th of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 03/10/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "mv_mv_pattern_02.h"

/**
 * Function Name : mv_pattern_15
 * Description	 : This function print following pattern :-  
 *								3
 *							2	3
 *						1	2	3
 *					0	1	2	3
 *						1	2	3
 *							2	3
 *								3
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_15()
{
	// Code 

	// Outer Loop
	for(int ole = 0; ole <= 6; ole++)
	{
		// Initialization
		int index = 0;
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
					// Print Space
					printf("    ");
				}
				else
				{
					// Print Number
					printf("%d   ", index);
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
					// Print Number
					printf("%d   ", index);
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

