
/**
 * File   : mv_pattern_45.c
 * Brief  : Prints pattern 45th of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 10/10/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "mv_pattern_header_05.h"


/**
 * Function Name : mv_pattern_45
 * Description	 : This function print following pattern :-  
 *								1
 *							1		2
 *						1		2		3
 *					1		2		3		4
 *						1		2		3	
 *							1		2
 *								1
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_45()
{
	// Code

	// Outer Loop
	for(int ole = 6; ole >= 0; ole--)
	{
		// Initialization
		int index = 1;

		// Inner Loop
		for(int ile = 6; ile >= 0; ile--)
		{
			// Conditions
			if((ile+ole) % 2 != 0 && ile+ole < 10 && ile-ole < 4 && ole-ile < 4 && ole+ile >1)
			{
				// True Block
				// Print Number
				printf("%d   ", index);
				
				// Increment
				index++;
			}
			else
			{
				// False Block
				// Print Space
				printf("    ");
			}
		}

		// New Line
		printf("\n");
	}

	return(0);
}

