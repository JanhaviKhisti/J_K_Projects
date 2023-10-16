
/**
 * File   : mv_pattern_19.c
 * Brief  : Prints pattern 19th of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 03/10/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "mv_pattern_header_02.h"

/**
 * Function Name : mv_pattern_19
 * Description	 : This function print following pattern :-  
 *					1	2	3	4	5
 *					 	1	2	3	4
 *					 	 	1	2	3
 *								1	2
 *									1
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_19()
{
	// Code

	// Outer Loop
	for(int ole = 4; ole >= 0; ole--)
	{ 
		// Initialization
		int index = 1;
		// Inner Loop
		for(int ile = 5; ile >= 0; ile--)
		{
			// Condition 1
			if( ile <= ole && ile-ole<= 4 )
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

