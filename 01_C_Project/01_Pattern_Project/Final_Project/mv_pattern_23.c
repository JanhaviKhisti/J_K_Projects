
/**
 * File   : mv_pattern_23.c
 * Brief  : Prints pattern 23th of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 10/10/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "mv_pattern_header_03.h"

/**
 * Function Name : mv_pattern_23
 * Description	 : This function print following pattern :-  
 * 									A		
 *								A	B	A			
 *							A	B	C	B	A	
 *						A	B	C	D	C	B	A	
 *					A	B	C	D	E	D	C	B	A
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_23()
{
	// Code

	// Outer Loop
	for(int ole = 4; ole >= 0; ole--)
	{
		// Initialization
		int index = 65;

		// Inner Loop
		for(int ile = 8; ile >= 0; ile--)
		{
			// Conditions
			if(ile >= ole && ile+ole <= 8)
			{
				// True Block
				// Print Character
				printf("%c   ", index);
				if(ile > 4)
				{
					index++;
				}
				else
				{
					index--;
				}
			}
			else
			{
				// False Block
				printf("    ");
			}
		}

		// New Line 
		printf("\n");
	}

	return(0);
}
