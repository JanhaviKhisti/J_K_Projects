
/**
 * @File: mv_dcll_server.c
 * @Brief: This contains definitions of functions declared in header file mv_dcll.h
 * @Author: Janhavi Sunil Khisti(janhavikhisti@gmail.com)
 * @Date: 20-06-2024
 */

//  Headers
#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>

#include    "mv_dcll.h"

//  Global Function Declarations
static  ret_t   error_checking( const int assert_condition,
                                const char* assert_condition_str,
                                const char* file_name,
                                const long  line_no,
                                const int error_condition,
                                const char* error_condition_str,
                                void*(*error_handler)(void*),
                                void* error_handler_params);

static p_node_t create_node(data_t new_data);

static void* exit_program(void* param);

// Constant Literals and Macros

#define     CHECK_LIST      0x00000001
#define     CHECK_EMPTY     0x00000002

#define     CHECK_LIST_EMPTY    CHECK_LIST | CHECK_EMPTY

#define ERROR_CHECKING(assert_condition, error_condition, error_condition_str, error_handler, error_handler_params)     \
    (                                           \
        error_checking( assert_condition,       \
                        #assert_condition,      \
                        __FILE__,               \
                        __LINE__,               \
                        error_condition,        \
                        error_condition_str,    \
                        error_handler,          \
                        error_handler_params)   \
    )

#define ASSERTION(assert_condition)             \
    (                                           \
        error_checking( assert_condition,       \
                        #assert_condition,      \
                        __FILE__,               \
                        __LINE__,               \
                        0,                      \
                        NULL,                   \
                        exit_program,           \
                        NULL)                   \
    )

#define     CREATE_NODE(new_node, new_data, exit_program)   \
                    {                                       \
                        new_node = create_node(new_data);   \
                                                            \
                        ERROR_CHECKING( NULL != new_node,   \
                                        0,                  \
                                        NULL,               \
                                        exit_program,       \
                                        NULL);              \
                    }

#define     RETURN_FAILURE(status)  { if(FAILURE == status) {return(FAILURE);} }

#define     RETURN_NULL(status)  { if(FAILURE == status) {return(NULL);} }


//  List Helper Functions

/**
 * Function Name: Xmalloc
 * Function Brief: This function will allocate a memory of 'no_of_bytes' size
 * Input Params: no_of_bytes
 * Returns: The pointer to the memory dynamically allocated of 'no_of_bytes' size
 */
static void* Xmalloc(size_t no_of_bytes)
{
    // Code
    void* p = malloc(no_of_bytes);
        
    ERROR_CHECKING( 0,
                    NULL == p,
                    "ERROR: Out Of Memory",
                    exit_program,
                    NULL);

    return(p);
} 

/**
 * Function Name: error_checking
 * Function Brief: This function will check error and either print erroe message of will do assertion
 * Input Params: 1) Assert Condition
 *               2) String of Assert condition
 *               3) File where assertion occured
 *               4) Line no where assertion occured
 *               5) Error Condition
 *               6) Error Message
 *               7) Error Handler
 *               8) Params for Error Handler
 * Returns: Status of the error / asssert checking
 */
static  ret_t   error_checking( const int assert_condition,
                                const char* assert_condition_str,
                                const char* file_name,
                                const long  line_no,
                                const int error_condition,
                                const char* error_condition_str,
                                void*(*error_handler)(void*),
                                void* error_handler_params)
{
    // Code
    ret_t status;

    #ifdef DEBUG
        // Assertion
        if( !assert_condition )
        {
            fprintf(stderr, "Assertion Failed: %s, File %s, Line No %ld", assert_condition_str, file_name, line_no);
            fprintf(stderr, "\n");
            status = FAILURE;
        }
    #else
        // Error Checking
        if( error_condition )
        {
            if(error_condition_str)
            {
                fprintf(stderr, error_condition_str);
                fprintf(stderr, "\n");
            }

            status = FAILURE;
        }
    #endif

    if( FAILURE == status   &&
        NULL != error_handler )
    {
        error_handler(error_handler_params);
    }

    return(status);
}

/**
 * Function Name: exit_program
 * Function Brief: This function will exit the executing program
 * Input Params: Pointer to void
 * Returns: Pointer to void
 */
static void* exit_program(void* param)
{
    // Code
    exit(FAILURE);

    return(NULL);
}

/**
 * Function Name: create_node
 * Function Brief: This function will create a node
 * Input Params: New data to assign to new node
 * Returns: pointer to allocated node
 */
static p_node_t create_node(data_t new_data)
{
    // Code
    p_node_t new_node = (p_node_t)Xmalloc(SIZE_NODE);

    if( NULL == new_node )
        return(new_node);

    //  Assign new data to key of new node
    new_node->key = new_data;

    //  Assign self to next and previous pointers of self
    new_node->p_next = new_node;
    new_node->p_prev = new_node;

    return(new_node);
}

/**
 * Function Name: create_list
 * Function Brief: This function will create an object of DOUBLY CIRCULAR LINKED LIST
 * Input Params: void
 * Returns: The pointer the new list object
 */
static p_mv_dcll_t create_list(void)
{
    // Code

    //  Create new DCLL
    p_mv_dcll_t plist = (p_mv_dcll_t)Xmalloc(SIZE_DCLL);

    if( NULL == plist )
        return(plist);

    p_node_t sentinel = NULL;

    //  Create a sentinel with no data node
    CREATE_NODE(sentinel, NULL, exit_program);

    //  Assign the sentinel as the head of the new DCLL
    plist->p_head = sentinel;
    plist->p_tail = sentinel;
    plist->size = 0;

    return(plist);
}

/**
 * Function Name: mv_dcll_generic_insert
 * Function Brief: This function is going to insert a new node the DCLL
 * Input Params: 1)  List
 *               2)  First (Previous Node for new node)
 *               3)  Mid (New Node)
 *               4)  Last  (Next Node for new node)
 * Returns: status
 */
static ret_t mv_dcll_generic_insert(p_mv_dcll_t plist, p_node_t first,  p_node_t mid, p_node_t last)
{
    //  Code

    //  Add the new node(mid) in the list
    mid->p_prev = first;
    mid->p_next = last;

    // Manipulate the list pointer to incorporate the new node
    first->p_next = mid;
    last->p_prev = mid;

    //  Assign new tail
    plist->p_tail = plist->p_head->p_prev;

    //  Increment the size
    plist->size++;

    return(SUCCESS);
}

/**
 * Function Name: mv_dcll_generic_remove
 * Function Brief: This function will remove the 'd_node' from the list
 * Input Params: 1) List
 *               2) To Remove node
 * Returns: The data of the removed node
 */
static data_t mv_dcll_generic_remove(p_mv_dcll_t plist, p_node_t d_node)
{
    // Code
    p_node_t prev_node = d_node->p_prev;
    p_node_t next_node = d_node->p_next;

    // Disconnet the d_node from list
    prev_node->p_next = next_node;
    next_node->p_prev = prev_node;

    // NIL the pointer of d_node (OPTIONAL)
    d_node->p_next = NULL;
    d_node->p_prev = NULL;

    //  Get the data to return
    data_t to_return_data = d_node->key;

    free(d_node);
    d_node = NULL;

    // Decrement the size
    plist->size--;

    //  Assign new tail
    plist->p_tail = plist->p_head->p_prev;

    return(to_return_data);
}

/**
 * Function Name: check_list_conditions
 * Function Brief: This function checks for list present and list empty
 * Input Params: 1) List
 *               2) Condition to check
 * Returns: Status of the condition checking
 */
static ret_t check_list_conditions(p_mv_dcll_t plist, int conditions)
{
    // Code
    if( CHECK_LIST & conditions )
    {
        RETURN_FAILURE( ERROR_CHECKING( NULL != plist,
                                        NULL == plist,
                                        "ERROR: List not found",
                                        NULL,
                                        NULL) );
    }

    if( CHECK_EMPTY & conditions )
    {
        RETURN_FAILURE( ERROR_CHECKING( 1,
                                        plist->p_head == plist->p_tail,
                                        //"ERROR: List is empty",
                                        "ERROR : Not Value Object",
                                        NULL,
                                        NULL) ); 
    }

    return(SUCCESS);
}

//  List Interface Functions

/**
 * Function Name: create_doubly_circular_list
 * Function Brief: This function will return a pointer to an DOUBLY CIRCULAR LIST OBJECT
 * Input Params: None
 * Returns: pointer to the created list object
 */
extern p_mv_dcll_t  create_doubly_circular_list()
{
    // Code
    return( create_list() );
}

//  List Data Insertion Functions
/**
 * Function Name: mv_dcll_insert_back
 * Function Brief: This function will add a new data to the BACK of the list
 * Input Params: 1) List
 *               2) New Data
 * Returns: status of insertion
 *          SUCCESS if successful / FAILURE if unsuccessful
 */
extern ret_t mv_dcll_insert_back(p_mv_dcll_t plist, data_t new_data)
{
    // Code
    #ifdef  DEBUG
    ASSERTION( NULL != plist );
    #endif

    RETURN_FAILURE( check_list_conditions(plist, CHECK_LIST) );

    p_node_t new_node = NULL;

    CREATE_NODE(new_node, new_data, exit_program);

    return( mv_dcll_generic_insert(plist, plist->p_tail, new_node, plist->p_tail->p_next ) );
}

/**
 * Function Name: mv_dcll_insert_front
 * Function Brief: This function will add a new data to the FRONT of the list
 * Input Params: 1) List
 *               2) New Data
 * Returns: status of insertion
 *          SUCCESS if successful / FAILURE if unsuccessful
 */
extern ret_t mv_dcll_insert_front(p_mv_dcll_t plist, data_t new_data)
{
    // Code
    #ifdef  DEBUG
    ASSERTION( NULL != plist );
    #endif

    RETURN_FAILURE( check_list_conditions(plist, CHECK_LIST) );

    p_node_t new_node = NULL;

    CREATE_NODE(new_node, new_data, exit_program);

    return( mv_dcll_generic_insert(plist, plist->p_head, new_node, plist->p_head->p_next) );
}

/**
 * Function Name: mv_dcll_insert_at
 * Function Brief: This function will add a new data at a specified INDEX in the list
 * Input Params: 1) List
 *               2) New Data
 *               3) INDEX
 * Returns: status of insertion
 *          SUCCESS if successful / FAILURE if unsuccessful
 */
extern ret_t mv_dcll_insert_at(p_mv_dcll_t plist, data_t new_data, size_t index)
{
    // Code
    #ifdef DEBUG
    ASSERTION( NULL != plist )
    #endif

    RETURN_FAILURE( check_list_conditions(plist, CHECK_LIST_EMPTY) );

    if( 0 == index )
        return( mv_dcll_insert_front(plist, new_data) );
    else if( index == plist->size )
        return( mv_dcll_insert_back(plist, new_data) );

    //printf("--1");

    RETURN_FAILURE( ERROR_CHECKING( index < plist->size,
                                    index > plist->size,
                                    "ERROR: Index Out Of Bound.",
                                    NULL,
                                    NULL) ); 
    //printf("--2");

    p_node_t prunner = plist->p_head;

    for( size_t le = 0; le < index; ++le)
        prunner = prunner->p_next;

    p_node_t new_node = NULL;

    CREATE_NODE(new_node, new_data, exit_program);

    return( mv_dcll_generic_insert(plist, prunner, new_node, prunner->p_next ) );
}

/**
 * Function Name: mv_dcll_insert_before
 * Function Brief: This function will add a new data BEFORE an existing data
 * Input Params: 1) List
 *               2) New Data
 *               3) Existing Data
 *               4) Compare Callback function pointer
 * Returns: status of insertion
 *          SUCCESS if successful / FAILURE if unsuccessful
 */
extern ret_t mv_dcll_insert_before(p_mv_dcll_t plist, data_t new_data, data_t e_data, COMPAREDATAPROC  pcomparedataproc)
{
    // Code
    #ifdef  DEBUG
    ASSERTION( NULL != plist )
    #endif

    RETURN_FAILURE( check_list_conditions(plist, CHECK_LIST_EMPTY) );

    RETURN_FAILURE( ERROR_CHECKING( NULL != pcomparedataproc,
                                    NULL == pcomparedataproc,
                                    "ERROR: Compare Callback must not be NULL",
                                    NULL,
                                    NULL) ); 

    p_node_t prunner = plist->p_head->p_next;

    while(1)
    {
        RETURN_FAILURE( ERROR_CHECKING( 1,
                                        prunner == plist->p_head,
                                        "ERROR: Existing Data no found",
                                        NULL,
                                        NULL) );

        if( SUCCESS == pcomparedataproc(prunner->key, e_data) )
            break;

        prunner = prunner->p_next;
    }

    p_node_t new_node = NULL;

    CREATE_NODE(new_node, new_data, exit_program);

    return( mv_dcll_generic_insert(plist,prunner->p_prev, new_node, prunner) );
}

/**
 * Function Name: mv_dcll_insert_after
 * Function Brief: This function will add a new data AFTER an existing data
 * Input Params: 1) List
 *               2) New Data
 *               3) Existing Data
 *               4) Compare Callback function pointer
 * Returns: status of insertion
 *          SUCCESS if successful / FAILURE if unsuccessful
 */
extern ret_t mv_dcll_insert_after(p_mv_dcll_t plist, data_t new_data, data_t e_data, COMPAREDATAPROC pcomparedataproc)
{
    // Code
    #ifdef  DEBUG
    ASSERTION( NULL != plist )
    #endif

    RETURN_FAILURE( check_list_conditions(plist, CHECK_LIST_EMPTY) );

    RETURN_FAILURE( ERROR_CHECKING( NULL != pcomparedataproc,
                                    NULL == pcomparedataproc,
                                    "ERROR: Compare Callback must not be NULL",
                                    NULL,
                                    NULL) ); 

    p_node_t prunner = plist->p_head->p_next;

    while(1)
    {
        RETURN_FAILURE( ERROR_CHECKING( 1,
                                        prunner == plist->p_head,
                                        "ERROR: Existing Data no found",
                                        NULL,
                                        NULL) );

        if( SUCCESS == pcomparedataproc(prunner->key, e_data) )
            break;

        prunner = prunner->p_next;
    }

    p_node_t new_node = NULL;

    CREATE_NODE(new_node, new_data, exit_program);

    return( mv_dcll_generic_insert(plist, prunner, new_node, prunner->p_next) );
}

//  List Data Removal Functions

/**
 * Function Name: mv_dcll_remove_back
 * Function Brief: This function will remove data from BACK of the list
 * Input Params: List
 * Returns: Removed data from the list OR NULL if no data.
 */
extern data_t mv_dcll_remove_back(p_mv_dcll_t plist)
{

    // Code
    #ifdef DEBUG
    ASSERTION( NULL != plist )
    #endif

    RETURN_NULL( check_list_conditions(plist, CHECK_LIST_EMPTY) );

    return( mv_dcll_generic_remove(plist, plist->p_tail) );
}

/**
 * Function Name: mv_dcll_remove_front
 * Function Brief: This function will remove data from FRONT of the list
 * Input Params: List
 * Returns: Removed data from the list OR NULL if no data.
 */
extern data_t mv_dcll_remove_front(p_mv_dcll_t plist)
{
    // Code
    #ifdef DEBUG
    ASSERTION( NULL != plist )
    #endif

    RETURN_NULL( check_list_conditions(plist, CHECK_LIST_EMPTY) );

    return( mv_dcll_generic_remove(plist, plist->p_head->p_next) );
}

/**
 * Function Name: mv_dcll_remove_at
 * Function Brief: This function will remove data from list from a specific INDEX
 * Input Params: 1) List
 *               2) INDEX
 * Returns: Removed data from the list OR NULL if no data. 
 */
extern data_t mv_dcll_remove_at(p_mv_dcll_t plist, size_t index)
{
    // Code
    #ifdef DEBUG
    ASSERTION( NULL != plist );
    #endif

    RETURN_NULL( check_list_conditions(plist, CHECK_LIST_EMPTY ));

    RETURN_NULL( ERROR_CHECKING(index < plist->size,
                                index >= plist->size,
                                "ERROR: Index Out Of Bound.",
                                NULL,
                                NULL) );

    p_node_t prunner = plist->p_head->p_next;

    for( size_t le = 0; le < index; ++le )
        prunner = prunner->p_next;

    return( mv_dcll_generic_remove(plist, prunner) ); 
}

/**
 * Function Name: mv_dcll_remove_before
 * Function Brief: This function will remove data BEFORE an existing data
 * Input Params: 1) List
 *               2) Existing Data
 *               3) Compare Callback function pointer
 * Returns: Removed data form the list OR NULL if no data.
 */
extern data_t mv_dcll_remove_before(p_mv_dcll_t plist, data_t e_data, COMPAREDATAPROC pcomparedataproc)
{
    // Code
    #ifdef  DEBUG
    ASSERTION( NULL != plist )
    #endif

    RETURN_NULL( check_list_conditions(plist, CHECK_LIST_EMPTY) );

    RETURN_NULL( ERROR_CHECKING(NULL != pcomparedataproc,
                                NULL == pcomparedataproc,
                                "ERROR: Compare Callback must not be NULL",
                                NULL,
                                NULL) ); 

    p_node_t prunner = plist->p_head->p_next;

    while(1)
    {
        RETURN_NULL( ERROR_CHECKING(1,
                                    prunner == plist->p_head,
                                    "ERROR: Existing Data no found",
                                    NULL,
                                    NULL) );

        if( SUCCESS == pcomparedataproc(prunner->key, e_data) )
            break;

        prunner = prunner->p_next;
    }

    if( prunner->p_prev == plist->p_head )
        prunner = plist->p_head;

    return( mv_dcll_generic_remove(plist, prunner) );
}

/**
 * Function Name: mv_dcll_remove_after
 * Function Brief: This function will remove data AFTER an existing data
 * Input Params: 1) List
 *               2) Existing Data
 *               3) Compare Callback function pointer
 * Returns: Removed data from the list OR NULL is no data.
 */
extern data_t mv_dcll_remove_after(p_mv_dcll_t plist, data_t e_data, COMPAREDATAPROC pcomparedataproc)
{
    // Code
    #ifdef  DEBUG
    ASSERTION( NULL != plist )
    #endif

    RETURN_NULL( check_list_conditions(plist, CHECK_LIST_EMPTY) );

    RETURN_NULL( ERROR_CHECKING(NULL != pcomparedataproc,
                                NULL == pcomparedataproc,
                                "ERROR: Compare Callback must not be NULL",
                                NULL,
                                NULL) ); 

    p_node_t prunner = plist->p_head->p_next;

    while(1)
    {
        RETURN_NULL( ERROR_CHECKING(1,
                                    prunner == plist->p_head,
                                    "ERROR: Existing Data no found",
                                    NULL,
                                    NULL) );

        if( SUCCESS == pcomparedataproc(prunner->key, e_data) )
            break;

        prunner = prunner->p_next;
    }

    if( prunner == plist->p_tail )
        prunner = plist->p_head;

    return( mv_dcll_generic_remove(plist, prunner) );
}


//  List Data Getter Functions

/**
 * Function Name: mv_dcll_get_head
 * Function Brief: This function will return the head data of the list
 * Input Params: List
 * Returns: Data of head of the list if present else NULL.
 */
extern data_t mv_dcll_get_head(p_mv_dcll_t plist)
{
    // Code
    #ifdef DEBUG
    ASSERTION( NULL != plist )
    #endif

    RETURN_NULL( check_list_conditions(plist, CHECK_LIST_EMPTY) );

    return( plist->p_head->p_next->key );
}

/**
 * Function Name: mv_dcll_get_tail
 * Function Brief: This function will return the tail of the list
 * Input Params: List
 * Returns: Data of tail of the list if present else NULL.
 */
extern data_t mv_dcll_get_tail(p_mv_dcll_t plist)
{
    // Code
    #ifdef DEBUG
    ASSERTION( NULL != plist )
    #endif

    RETURN_NULL( check_list_conditions(plist, CHECK_LIST_EMPTY) );

    return( plist->p_tail->key );
}

/**
 * Function Name: mv_dcll_get_size
 * Function Brief: This function will return the size(no of elements) of list
 * Input Params: List
 * Returns: Size(No of elements)
 */
extern size_t mv_dcll_get_size(p_mv_dcll_t plist)
{
    // Code
    #ifdef DEBUG
    ASSERTION( NULL != plist )
    #endif

    if( FAILURE == check_list_conditions(plist, CHECK_LIST) )
        return(0);

    return( plist->size );
}

/**
 * Function Name: mv_dcll_empty
 * Function Brief: This function will return if list is present or not
 * Input Params: List
 * Returns: TRUE is list present 
 *          FALSE if list not present
 */
extern bool_t mv_dcll_empty(p_mv_dcll_t plist)
{
    // Code
    if( NULL == plist   ||
        plist->p_head == plist->p_tail )
        return(TRUE);
    
    return(FALSE);
}

//  List Show Data Functions

/**
 * Function Name: mv_dcll_print_forward
 * Function Brief: This function will print the data in forward order
 * Input Params: 1) List
 *               2) Show Data Callback function pointer
 * Returns: Status of printing data
 */
extern ret_t mv_dcll_print_forward(p_mv_dcll_t plist, SHOWDATAPROC pshowdataproc)
{
    // Code
    #ifdef DEBUG
    ASSERTION( NULL != plist)
    #endif

    RETURN_FAILURE( check_list_conditions(plist, CHECK_LIST) );

    RETURN_FAILURE( ERROR_CHECKING( NULL != pshowdataproc,
                                    NULL == pshowdataproc,
                                    "ERROR: Show Data Proc must not be NULL.",
                                    NULL,
                                    NULL) );

    p_node_t prunner = plist->p_head->p_next;

    //fprintf(stdout, "\nDOUBLY CIRCULAR LIST FORWARD:\n");
    //fprintf(stdout, "{START}->");
    for( prunner; prunner != plist->p_head; prunner = prunner->p_next )
        pshowdataproc(prunner->key);
    //fprintf(stdout, "{END}\n");

    return(SUCCESS);
}

/**
 * Function Name: mv_dcll_print_reverse
 * Function Brief: This function will print the data in reverse order
 * Input Params: 1) List
 *               2) Show Data Callback function pointer
 * Returns: Staus of printing data
 */
extern ret_t mv_dcll_print_reverse(p_mv_dcll_t plist, SHOWDATAPROC pshowdataproc)
{
    // Code
    #ifdef DEBUG
    ASSERTION( NULL != plist)
    #endif

    RETURN_FAILURE( check_list_conditions(plist, CHECK_LIST) );

    RETURN_FAILURE( ERROR_CHECKING( NULL != pshowdataproc,
                                    NULL == pshowdataproc,
                                    "ERROR: Show Data Proc must not be NULL.",
                                    NULL,
                                    NULL) );

    p_node_t prunner = plist->p_tail;

    for( prunner; prunner != plist->p_head; prunner = prunner->p_prev )
        pshowdataproc(prunner->key);

    return(SUCCESS);
}

/**
 * Function Name: mv_dcll_destroy
 * Function Brief: This function will destroy the passed list
 * Input Params: 1) Pointer to list
 *               2) Destroy Data Callback function pointer
 * Returns: Status of detroying the list
 */
extern ret_t mv_dcll_destroy(pp_mv_dcll_t pplist)
{
    // Code
    #ifdef DEBUG
    ASSERTION( NULL != pplist)
    #endif

    p_mv_dcll_t plist = *pplist;

    #ifdef DEBUG
    ASSERTION( NULL != plist)
    #endif

    RETURN_FAILURE( check_list_conditions(plist, CHECK_LIST) );

    p_node_t prunner = plist->p_head->p_next;

    for( prunner; prunner != plist->p_head;)
    {
        p_node_t prunner_next = prunner->p_next;
        prunner->key = NULL;

        free(prunner);
        prunner = prunner_next;
    }

    fprintf(stdout, "\n DESTROYED STACK\n\n ");

    if( plist->p_head )
    {
        free(plist->p_head);
        plist->p_head = NULL;
    }

    if( plist )
    {
        free(plist);
        plist = NULL;
    }

    *pplist = NULL;

    return(SUCCESS);
}

