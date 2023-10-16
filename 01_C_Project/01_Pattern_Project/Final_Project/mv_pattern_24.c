
/**
 * File   : mv_pattern_24.c
 * Brief  : Prints pattern 24th of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 10/10/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "mv_pattern_header_03.h"

/**
 * Function Name : mv_pattern_24
 * Description	 : This function print following pattern :-  
 * 									A		
 *								C	B	A			
 *							E	D	C	B	A		
 *						G	F	E	D	C	B	A
 *					I	H	G	F	E	D	C	B 	A
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_24()
{
	// Code

	// Initialization
	int index = 65;

	// Outer Loop
	for(int ole = 4; ole >= 0; ole--)
	{	
		// Initialization
		int index2 = 0;

		// Inner Loop
		for(int ile = 8; ile >= 0; ile--)
		{	
			// Conditions
			if(ile >= ole && ile+ole <= 8)
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
				//Print Space
				printf("    ");
			}	
		}
		// Increment
		index = index + 2;

		// New Line
		printf("\n");
	}

	return(0);
}

