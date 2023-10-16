
/**
 * File   : mv_pattern_05.c
 * Brief  : Prints pattern 5th of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 28/09/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "mv_pattern_header_01.h"

/**
 * Function Name : mv_pattern_05
 * Description	 : This function print following pattern :-  
 *					1	1	1	1	1
 *					A	B	C	D	E
 *					*	*	*	*	*
 *					A	B	C	D	E
 *					1	1	1	1	1
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_05()
{
	// Code

	// Outer Loop
	for(int ole = 0; ole < 5; ole++)
	{
		// Condition 1
		if(ole == 0 || ole == 4)
		{
			// True Block
			// Initialization
			int index = 1;

			// Inner Loop
			for(int ile = 0; ile < 5; ile++)
			{
				// Print Number
				printf("%d  ", index);
			}
		}
		// Condition 2
		else if(ole == 1 || ole == 3)
		{
			// True Block
			// Initialization
			int index = 65;

			// Inner Loop
			for(int ile = 0; ile < 5; ile++)
			{
				// Print Character
				printf("%c  ", index);

				// Increment
				index++;
			}
		}
		else
		{
			// False Block
			// Inner Loop
			for(int ile = 0; ile < 5; ile++)
			{
				// Print Star
				printf("*  ");
			}
		}

		// New Line
		printf("\n");
	}

	return(0);
}

