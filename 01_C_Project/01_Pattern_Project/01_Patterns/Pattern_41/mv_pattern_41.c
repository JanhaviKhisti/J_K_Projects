
/**
 * File   : mv_pattern_41.c
 * Brief  : Prints pattern 41th of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 10/10/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "mv_pattern_05.h"

/**
 * Function Name : mv_pattern_41
 * Description	 : This function print following pattern :-  
 *									*	
 *								*		*
 *							*				*
 *						*						*
 *					*								*
 *						*						*
 *							*				*
 *								*		*
 *									*
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_41()
{
	// Code

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
				// Print Star
				printf("*   ");
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

