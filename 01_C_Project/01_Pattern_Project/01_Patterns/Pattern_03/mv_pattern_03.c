
/**
 * File   : mv_pattern_03.c
 * Brief  : Prints pattern 3rd of project
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 28/09/2023
 */

#include <stdio.h>
#include <stdlib.h>

#include "mv_pattern_01.h"

/**
 * Function Name : mv_pattern_03
 * Description	 : This function print following pattern :-  
 *	        		5	4	3	2	1
 *					5	4	3	2	1
 *					5	4	3	2	1
 *					5	4	3	2	1
 *					5	4	3	2	1
 * Input Param	 : none
 * Returns		 : int
 */
int mv_pattern_03()
{
	// Code

	// Outer Loop
	for(int ole = 0; ole < 5; ole++)
	{
		// Inner Loop
		for(int ile = 5; ile > 0; ile--)
		{
			// Print Numbers
			printf("%d  ", ile);
		}

		// New Line
		printf("\n");
	}

	return(0);
}

