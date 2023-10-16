
/**
 * File   : mv_pattern_13.c
 * Brief  : Prints pattern 13th of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 03/10/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "mv_pattern_header_02.h"

/**
 * Function Name : mv_pattern_13
 * Description	 : This function print following pattern :-  
 *					1
 *					2   1
 *					1	2	3
 *					4	3	2	1
 *					1	2	3	4	5
 *  				4   3   2   1
 *  				1   2   3
 *  				2   1
 *  				1
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_13()
{
	// Code

	// Local Variable
	int index;

	// Outer Loop
	for(int ole = 0; ole <= 9; ole++)
	{
		// Condition 1
		if(ole < 5)
		{
			// Nested Condition
			if(ole % 2)
			{
				index = ole+1;
			}

			// Inner Loop
			for(int ile = 0; ile <= ole; ile++)
			{
				// Nested Condition
				if(ole % 2)
				{
					// True Block
					// Print Numbers
					printf("%d   ", index);

					// Decrement
					index--;
				}
				else
				{
					// False Block
					// Print Numbers
					printf("%d   ", ile+1);
				}
			}
		}
		// Condition 2
		else if(ole >= 5)
		{
			// Index Initialization
			int index2 = 1;

			// Inner Loop
			for(int ile = 8; ile >= ole; ile--)
			{
				index = ile - ole + 1;

				// Nested Condition
				if(ole % 2)
				{
					// Print Numbers
					printf("%d   ", index);

					// Decrement
					index--;
				}
				else
				{
					// Print Numbers
					printf("%d   ",index2);

					// Increment
					index2++;
				}
			}
		}

		// New Line
		printf("\n");
	}

	return(0);
}

