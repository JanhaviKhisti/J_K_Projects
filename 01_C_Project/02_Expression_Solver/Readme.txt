# Expression Interpreter

## Project Problem Statement
The project is to evaluate and solve any expression given by the user.

## Project Output
This expression Interpreter can perform addition, subtraction, and multiplication on any numbers with n digits.

## Concepts and Data Structures Used in Project
1. C Programming Language Basics
2. Pointers
3. String and all string operations
4. Vector
5. Doubly Circular Linked List
6. Expression Stack
7. Expression Tree
8. Infix to Postfix Expression Conversion
9. Postfix Expression Solving

## Project Implementation

### Expression Input as a String
Read the expression as a string continuously until the "exit" command is given. 
For user input string, fgets function is used, and string length function is use to put '\0' at the end of input string. 

### Tokenization
Create tokens of the given expression, for that string tokanization function named as 'mv_strtok' is implemented.
The function which takes string and delimiter as an arguments and returns a vector of tokens named as 'token_vector'. 
The delimiter is space character in this project.

### Type Checking
For type checking, type checker function named as 'mv_type_checking' is implemented. 
The function takes tokenized string as argument and returns the type of token as IMMIDIATE, IDENTIFIER, OPERATOR.
If tokenized string is type of operator, then type of operator is checked and decides the priority of operator. 
For operators priority, the function named as 'get_operator_priority' is implemented.

### Object Creation
Create an object which will contain tokens and types of tokens. 
Read each token from `token_vector` and then create an object. 
When objects are created then they pushed into one vector named as 'object_vector', for this functionality, function named as 'create_object_vector' is implemented.

### Expression Stack
Create an expression stack using objects in `object_vector`. 
To create expression stack, the function named as 'create_expression_stack' is implemented. 
This function takes object_vetor as argument and returns created expression stack. 
If object is of type IMMIDIATE or IDENTIFIER then that directly push on stack. 
If object is of type OPERATOR then expression node and expression object is created, that expression object is push on stack. 

### Expression Tree
Create an expression tree using the expression stack. 
To create expression tree, the function named as create_expression_tree is implemented.
This function takes expression stack as argument and returns expression object.
This function pops the objects from stack and create expression tree of objects.

### Expression Solving
After creating the expression tree, evaluate and solve the expression tree using post-order traversal. 
For this, the function named as 'expression_solver' is implemented. 
This function actually evaluate and solve the expression.
The answer is given by operation solving functions.
This expression solving part is very important part of project. 

## Conclusion
In this project, I have successfully implemented various C concepts such as control flow, functions, pointers, strings.
The data structures such as vectors, doubly circular linked lists, stacks, trees, etc are also implemented. 
This project provides a detailed understanding about the strength of data structures.

