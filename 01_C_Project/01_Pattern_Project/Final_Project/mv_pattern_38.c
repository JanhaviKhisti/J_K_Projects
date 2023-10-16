
/**
 * File   : mv_pattern_38.c
 * Brief  : Prints pattern 38th of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 10/10/2023
 */
#include <stdio.h>
#include <stdlib.h>

#include "mv_pattern_header_04.h"

/**
 * Function Name : mv_pattern_38
 * Description	 : This function print following pattern :-  
 *									1
 *								1		2
 * 							1		2		3
 * 						1		2		3		4
 *					1		2		3		4		5
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_38()
{
	// Code

	// Outer Loop
	for(int ole = 4; ole >= 0; ole--)
	{
		// Initialization
		int index = 1;

		// Inner Loop
		for(int ile = 8; ile >= 0; ile--)
		{
			// Conditions
			if((ile+ole) % 2 == 0 && ile >= ole && ile <= 8-ole)
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

