
/**
 * File   : mv_pattern_39.c
 * Brief  : Prints pattern 39th of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 10/10/2023
 */
#include <stdio.h>
#include <stdlib.h>

#include "mv_pattern_header_04.h"

/**
 * Function Name : mv_pattern_39
 * Description	 : This function print following pattern :-  
 *					E		D		C		B		A
 * 						D		C		B		A
 * 							C		B		A
 *								B		A
 * 									A
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_39()
{
	// Code

	// Initialization
	int index = 69;

	// Outer Loop
	for(int ole = 0; ole <= 4; ole++)
	{
		// Initialization
		int index2 = 0;

		// Inner Loop
		for(int ile = 0; ile <= 8; ile++)
		{
			// Conditions
			if((ile+ole) % 2 == 0 && ile >= ole && ile <= 8-ole)
			{
				// True Block
				// Print Character
				printf("%c   ", index-index2);

				// Increment
				index2++;
			}
			else
			{
				// False Block
				// Print Space
				printf("    ");
			}
		}
		// Decrement
		index = index--;

		// New Line
		printf("\n");
	}

	return(0);
}

