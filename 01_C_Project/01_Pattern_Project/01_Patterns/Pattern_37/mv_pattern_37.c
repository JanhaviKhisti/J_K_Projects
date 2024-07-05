
/**
 * File   : mv_pattern_37.c
 * Brief  : Prints pattern 37th of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 10/10/2023
 */
#include <stdio.h>
#include <stdlib.h>

#include "mv_pattern_04.h"

/**
 * Function Name : mv_pattern_37
 * Description	 : This function print following pattern :-  
 *									1
 *								2		2
 * 							3		3		3
 * 						4		4		4		4
 *					5		5		5		5		5
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_37()
{
	// Code

	// Initialization
	int index = 1;

	// Outer Loop
	for(int ole = 4; ole >= 0; ole--)
	{
		// Inner Loop
		for(int ile = 8; ile >= 0; ile--)
		{
			// Conditions
			if((ile+ole) % 2 == 0 && ile >= ole && ile <= 8-ole)
			{
				// True Block
				// Print Number
				printf("%d   ", index);
			}
			else
			{
				// False Block 
				// Print Space
				printf("    ");
			}
		}
		// Increment
		index++;

		// New Line
		printf("\n");
	}

	return(0);
}


