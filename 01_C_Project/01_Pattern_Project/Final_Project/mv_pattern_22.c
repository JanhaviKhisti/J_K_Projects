
/**
 * File   : mv_pattern_22.c
 * Brief  : Prints pattern 22th of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 10/10/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "mv_pattern_header_03.h"

/**
 * Function Name : mv_pattern_22
 * Description	 : This function print following pattern :-  
 * 									A		
 *								B	A	B			
 *							C	B	A	B	C		
 *						D	C	B	A	B	C	D		
 *					E	D	C	B	A	B	C	D	E
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_22()
{
	// Code

	// Initialization
	int index;

	// Outer Loop
	for(int ole = 4; ole >= 0; ole--)
	{
		// Inner Loop
		for(int ile = 8; ile >= 0; ile--)
		{
			// Condition 1
			if(ile >= ole && ile+ole <= 8)
			{
				// True Block
				if(ile == 4)
				{
					index = 65;
				}
				else if(ile == 5 || ile == 3)
				{
					index = 66;
				}
				else if(ile == 6 || ile == 2)
				{
					index = 67;
				}
				else if(ile == 7 || ile == 1)
				{
					index = 68;
				}
				else
				{
					index = 69;
				}

				// Print Character
				printf("%c   ", index);
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

