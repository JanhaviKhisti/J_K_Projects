
/**
 * File   : mv_pattern_44.c
 * Brief  : Prints pattern 44th of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 10/10/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "mv_pattern_05.h"

/**
 * Function Name : mv_pattern_44
 * Description	 : This function print following pattern :-  
 *									1	
 *								2		2
 *							3				3
 *						4						4
 *					5								5
 *						4						4
 *							3				3
 *								2		2
 *									1
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_44()
{
	// Code

	// Increment
	int index = 1;

	// Outer Loop
	for(int ole = 0; ole <= 8; ole++)
	{
		// Inner Loop
		for(int ile = 0; ile <= 8; ile++)
		{
			// Conditions
			if(ile+ole == 4 && ile+ole <= 8 || ile-ole == 4 || ole-ile == 4 || ole+ile == 12)
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
		// Condition
		if(ole > 3)
		{
			//True Block
			// Decrement
			index--;
		}
		else
		{
			// False Block
			// Increment
			index++;
		}

		// New Line
		printf("\n");
	}

	return(0);
}

