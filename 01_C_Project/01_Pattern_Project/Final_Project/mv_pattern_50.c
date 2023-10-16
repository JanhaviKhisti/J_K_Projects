
/**
 * File   : mv_pattern_50.c
 * Brief  : Prints pattern 50th of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 10/10/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "mv_pattern_header_05.h"


/**
 * Function Name : mv_pattern_50
 * Description	 : This function print following pattern :-  
 *					A						G	F	E	D	C	B	A
 *					A	B						F	E	D	C	B	A
 *					A	B	C						E	D	C	B	A
 *					A	B	C	D						D	C	B	A
 *					A	B	C	D	E						C	B	A
 *					A	B	C	D	E	F						B	A
 *					A	B	C	D	E	F	G						A
 *					A	B	C	D	E	F						B	A
 *					A	B	C	D	E						C	B	A
 *					A	B	C	D						D	C	B	A
 * 					A	B	C						E	D	C	B	A
 * 					A	B						F	E	D	C	B	A
 *					A						G	F	E	D	C	B	A					
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_50()
{
	// Code

	// Outer Loop
	for( int ole = 0; ole < 13; ++ole )	
	{
		// Initialization
		int index = 65;

		// Inner Loop
		for( int ile = 0; ile < 13; ++ile )
		{
			// Condition
			if(ole < 7)
			{
				// True Block
				// Nested Conditions
				if( 1 + ole <= ile && ile <= 5 + ole )
				{
					// True Block
					// Print Space
					printf("   ");
				}
				else
				{
					// False Block
					// Print Character
					printf("%c  ", index);
				}
			}
			else
			{
				// False Block
				// Nested Condition
				if( 13 - ole <= ile && ile <= 17 - ole)
				{
					// True Block
					// Print Space
					printf("   ");
				}
				else
				{
					// False Block
					// Print Character
					printf("%c  ", index);
				}
			}

			// Condition
			if( ile < 6 )
			{
				// Increment
				index++;
			}
			else
			{
				// Decrement
				index--;
			}
		}

		// New Line
		printf("\n");
	}

	return(0);
}

