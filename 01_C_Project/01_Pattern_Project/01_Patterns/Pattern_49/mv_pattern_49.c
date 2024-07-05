
/**
 * File   : mv_pattern_49.c
 * Brief  : Prints pattern 49th of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 10/10/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "mv_pattern_05.h"

/**
 * Function Name : mv_pattern_49
 * Description	 : This function print following pattern :-  
 *					A	B	C	D	E	F	G						A
 *					A	B	C	D	E	F						B	A
 *					A	B	C	D	E						C	B	A
 * 					A	B	C	D						D	C	B	A
 *					A	B	C						E	D	C	B	A
 *					A	B						F	E	D	C	B	A
 *					A						G	F	E	D	C	B	A					
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_49()
{
	// Code

	// Outer Loop
	for( int ole = 0; ole < 7; ++ole )	
	{
		// Initialization
		int index = 65;

		// Inner Loop
		for( int ile = 0; ile < 13; ++ile )
		{
			// Conditions
			if( 7 - ole <= ile && ile <= 11 - ole)
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

			// Condition
			if( ile < 6 )
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
		}

		// New Line
		printf("\n");
	}

	return(0);
}

