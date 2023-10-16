
/**
 * File   : mv_pattern_43.c
 * Brief  : Prints pattern 43th of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 10/10/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "mv_pattern_header_05.h"


/**
 * Function Name : mv_pattern_43
 * Description	 : This function print following pattern :-  
 *									E	
 *								D		D
 *							C				C
 *						B						B
 *					A								A
 *						B						B
 *							C				C
 *								D		D
 *									E
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_43()
{
	// Code

	// Initialization
	int index = 69;

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
				// Print Character
				printf("%c   ", index);
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
			// True Block 
			// Increment
			index++;
		}
		else
		{
			// False Block
			// Decrement
			index--;
		}

		// New Line
		printf("\n");
	}

	return(0);
}

