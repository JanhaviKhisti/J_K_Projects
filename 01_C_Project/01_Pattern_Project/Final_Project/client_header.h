
/**
 * File   : client_header.h
 * Brief  : Contains all headers and array of function pointer to pattern functions
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 13/10/2023
 */

#ifndef _MV_CLIENT_HEADER_H
#define _MV_CLIENT_HEADER_H

// Headers
#include "mv_pattern_header_01.h"
#include "mv_pattern_header_02.h"
#include "mv_pattern_header_03.h"
#include "mv_pattern_header_04.h"
#include "mv_pattern_header_05.h"


// Array of Function Pointers
int (*mv_pattern_functions[50])() = {	mv_pattern_01, mv_pattern_02, mv_pattern_03, mv_pattern_04, mv_pattern_05,
										mv_pattern_06, mv_pattern_07, mv_pattern_08, mv_pattern_09, mv_pattern_10,
										mv_pattern_11, mv_pattern_12, mv_pattern_13, mv_pattern_14, mv_pattern_15,
										mv_pattern_16, mv_pattern_17, mv_pattern_18, mv_pattern_19, mv_pattern_20,
										mv_pattern_21, mv_pattern_22, mv_pattern_23, mv_pattern_24, mv_pattern_25,
										mv_pattern_26, mv_pattern_27, mv_pattern_28, mv_pattern_29, mv_pattern_30,
										mv_pattern_31, mv_pattern_32, mv_pattern_33, mv_pattern_34, mv_pattern_35,
										mv_pattern_36, mv_pattern_37, mv_pattern_38, mv_pattern_39, mv_pattern_40,
										mv_pattern_41, mv_pattern_42, mv_pattern_43, mv_pattern_44, mv_pattern_45,
										mv_pattern_46, mv_pattern_47, mv_pattern_48, mv_pattern_49, mv_pattern_50
									 };


// Function Definition
/**
 * Function Name : call_pattern
 * Description	 : This function call patterns function    
 * Input Param	 : user_input_value
 * Returns		 : none
 */
void call_pattern(int user_input_value)
{
	// Code

	// Error Checking
	if( user_input_value < 1 || user_input_value > 50 )
	{
		if( 0 == user_input_value )
		{
			printf("Exit\n\n");
		}
		else
		{
			// Error Message 
			printf("ERROR: Pattern not exists between 1 to 50\n\n");
		}
	}
	else
	{
		// Pattern Function Call 
		mv_pattern_functions[ user_input_value-1 ]();	
	}

}


#endif/* _MV_CLIENT_HEADER_H */

