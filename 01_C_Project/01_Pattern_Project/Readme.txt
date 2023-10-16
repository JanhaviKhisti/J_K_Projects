

/**
 * File   : Readme.txt
 * Brief  : This file describes the information about patterns miniproject.
 * Author : Janhavi Khisti(janhavikhisti@gmail.com)
 * Date   : 16/10/2023
 */


#) The Pattern Project is Build in 3 Modules, which are as follows :-
	
	*) The Logical implementation of 50 patterns
	*) Client Server Architecture formation 
	*) Build complete project using bat file


#) Concepts used in project :- 

	*) Intra Functional Control Flow - which contains Branching and Looping Statements
	*) Inter Functional Control Flow - which contains Functions
	*) Array of Function Pointer - the each element of array contains pointer to pattern number function
	   (pattern number is as same as index)
	*) Client Server Architecture - which contains implementation of Header, Server and Client


#) Modules Description :- 

	*) The Logical implementation of 50 patterns done using Intra Functional Control Flow Statements,
	   After that we build function to print pattern, sample is as follows :- 

	   	int mv_pattern_01()
	   	{
	   		// code
	   	} 

	   	The all pattern function written in separate C file, which files are named as pattern number -
	   	i.e. mv_pattern_01.c,
	   		 mv_pattern_02.c, ..., mv_pattern_50.c

	*) To build Client Server Architecture we have written total 6 Header Files, 
	   In which 5 Header Files contains function declarations of 10 patterns in each file-
	   i.e. mv_pattern_header_01.h, 
	   		mv_pattern_header_02.h,
	   		mv_pattern_header_03.h,
	   		mv_pattern_header_04.h,
	   		mv_pattern_header_05.h

	   Last Header File is known as Client Header as it includes 5 pattern headers and implementation of Array of Function Pointer as well as the function definition of pattern caller function 

	   The 50 separate C files of patterns, it self act as a server of project.

	   The client C file contains client header and entry point function of pattern project.

	*) The bat file is known as batch file which stores commands to be executed in serial order.
	   The commands are as follows -
	   1) cl /EHsc mv_pattern_client.c mv_pattern_01.c mv_pattern_02.c mv_pattern_03.c (.... upto mv_pattern_50.c) 

	   2) pattern_client.exe


#) Conclusion :- 

	This project we successfully implement concepts such as Branching, Looping, Functions, Array, Pointer, etc.
	This projects gives primitive idea about multifile code handling as well as successful implementation of Client Server Architecture.

	
