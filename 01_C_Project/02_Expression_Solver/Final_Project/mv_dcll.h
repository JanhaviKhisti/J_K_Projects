
/**
 * @File: mv_dcll.h
 * @Brief: This contains function declarations for mv_dcll
 * @Author: Janhavi Sunil Khisti(janhavikhisti@gmail.com)
 * @Date: 20-06-2024
 */

#ifndef	_MV_DCLL_H
#define	_MV_DCLL_H

//	Constant Literals
#ifndef	SUCCESS	
#define	SUCCESS 0
#endif

#ifndef	FAILURE
#define	FAILURE	1
#endif	

//	Enums
enum
{
	FALSE = 0,
	TRUE
};

//	Struct Type Declarations and Typedefs

struct 	list_node;

typedef	struct list_node	node_t;
typedef	struct list_node*	p_node_t;
typedef	struct list_node**	pp_node_t;

struct mv_doubly_circular_list;

typedef struct mv_doubly_circular_list		mv_doubly_list_t;
typedef	struct mv_doubly_circular_list*		p_mv_doubly_list_t;
typedef	struct mv_doubly_circular_list**	pp_mv_doubly_list_t;

typedef	mv_doubly_list_t	mv_dcll_t;
typedef	p_mv_doubly_list_t	p_mv_dcll_t;
typedef	pp_mv_doubly_list_t	pp_mv_dcll_t;

typedef	void*	data_t;
typedef	int 	ret_t;

typedef	char	bool_t;

typedef		ret_t (*COMPAREDATAPROC)(data_t, data_t);
typedef		void (*SHOWDATAPROC)(data_t);

//	Struct Type Definitions
struct list_node
{
	data_t	key;
	p_node_t 	p_next;
	p_node_t 	p_prev;
};
#define	SIZE_NODE	(sizeof(node_t))

struct 	mv_doubly_circular_list
{
	p_node_t p_head;
	p_node_t p_tail;
	size_t	size;
};
#define	SIZE_DCLL	(sizeof(mv_dcll_t))

//	List Interface Functions

/**
 * Function Name: create_doubly_circular_list
 * Function Brief: This function will return a pointer to an DOUBLY CIRCULAR LIST OBJECT
 * Input Params: None
 * Returns: pointer to the created list object
 */
extern p_mv_dcll_t	create_doubly_circular_list();

//	List Data Insertion Functions

/**
 * Function Name: mv_dcll_insert_back
 * Function Brief: This function will add a new data to the BACK of the list
 * Input Params: 1) List
 * 				 2) New Data
 * Returns: status of insertion
 * 			SUCCESS if successful / FAILURE if unsuccessful
 */
extern ret_t mv_dcll_insert_back(p_mv_dcll_t plist, data_t new_data);

/**
 * Function Name: mv_dcll_insert_front
 * Function Brief: This function will add a new data to the FRONT of the list
 * Input Params: 1) List
 * 				 2) New Data
 * Returns: status of insertion
 * 			SUCCESS if successful / FAILURE if unsuccessful
 */
extern ret_t mv_dcll_insert_front(p_mv_dcll_t plist, data_t new_data);

/**
 * Function Name: mv_dcll_insert_at
 * Function Brief: This function will add a new data at a specified INDEX in the list
 * Input Params: 1) List
 * 				 2) New Data
 * 				 3) INDEX
 * Returns: status of insertion
 * 			SUCCESS if successful / FAILURE if unsuccessful
 */
extern ret_t mv_dcll_insert_at(p_mv_dcll_t plist, data_t new_data, size_t index);

/**
 * Function Name: mv_dcll_insert_before
 * Function Brief: This function will add a new data BEFORE an existing data
 * Input Params: 1) List
 * 				 2) New Data
 * 				 3) Existing Data
 * 				 4) Compare Callback function pointer
 * Returns: status of insertion
 * 			SUCCESS if successful / FAILURE if unsuccessful
 */
extern ret_t mv_dcll_insert_before(p_mv_dcll_t plist, data_t new_data, data_t e_data, COMPAREDATAPROC  pcomparedataproc);

/**
 * Function Name: mv_dcll_insert_after
 * Function Brief: This function will add a new data AFTER an existing data
 * Input Params: 1) List
 * 				 2) New Data
 * 				 3) Existing Data
 * 				 4) Compare Callback function pointer
 * Returns: status of insertion
 * 			SUCCESS if successful / FAILURE if unsuccessful
 */
extern ret_t mv_dcll_insert_after(p_mv_dcll_t plist, data_t new_data, data_t e_data, COMPAREDATAPROC pcomparedataproc);

//	List Data Removal Functions

/**
 * Function Name: mv_dcll_remove_back
 * Function Brief: This function will remove data from BACK of the list
 * Input Params: List
 * Returns: Removed data from the list OR NULL if no data.
 */
extern data_t mv_dcll_remove_back(p_mv_dcll_t plist);

/**
 * Function Name: mv_dcll_remove_front
 * Function Brief: This function will remove data from FRONT of the list
 * Input Params: List
 * Returns: Removed data from the list OR NULL if no data.
 */
extern data_t mv_dcll_remove_front(p_mv_dcll_t plist);

/**
 * Function Name: mv_dcll_remove_at
 * Function Brief: This function will remove data from list from a specific INDEX
 * Input Params: 1) List
 * 				 2) INDEX
 * Returns: Removed data from the list OR NULL if no data. 
 */
extern data_t mv_dcll_remove_at(p_mv_dcll_t plist, size_t index);

/**
 * Function Name: mv_dcll_remove_before
 * Function Brief: This function will remove data BEFORE an existing data
 * Input Params: 1) List
 * 				 2) Existing Data
 * 				 3) Compare Callback function pointer
 * Returns: Removed data form the list OR NULL if no data.
 */
extern data_t mv_dcll_remove_before(p_mv_dcll_t plist, data_t e_data, COMPAREDATAPROC pcomparedataproc);

/**
 * Function Name: mv_dcll_remove_after
 * Function Brief: This function will remove data AFTER an existing data
 * Input Params: 1) List
 * 				 2) Existing Data
 * 				 3) Compare Callback function pointer
 * Returns: Removed data from the list OR NULL is no data.
 */
extern data_t mv_dcll_remove_after(p_mv_dcll_t plist, data_t e_data, COMPAREDATAPROC pcomparedataproc);

//	List Data Getter Functions

/**
 * Function Name: mv_dcll_get_head
 * Function Brief: This function will return the head data of the list
 * Input Params: List
 * Returns: Data of head of the list if present else NULL.
 */
extern data_t mv_dcll_get_head(p_mv_dcll_t plist);

/**
 * Function Name: mv_dcll_get_tail
 * Function Brief: This function will return the tail of the list
 * Input Params: List
 * Returns: Data of tail of the list if present else NULL.
 */
extern data_t mv_dcll_get_tail(p_mv_dcll_t plist);

/**
 * Function Name: mv_dcll_get_size
 * Function Brief: This function will return the size(no of elements) of list
 * Input Params: List
 * Returns: Size(No of elements)
 */
extern size_t mv_dcll_get_size(p_mv_dcll_t plist);

/**
 * Function Name: mv_dcll_empty
 * Function Brief: This function will return if list is present or not
 * Input Params: List
 * Returns: TRUE is list present 
 * 			FALSE if list not present
 */
extern bool_t mv_dcll_empty(p_mv_dcll_t plist);

//	List Show Data Functions

/**
 * Function Name: mv_dcll_print_forward
 * Function Brief: This function will print the data in forward order
 * Input Params: 1) List
 * 				 2) Show Data Callback function pointer
 * Returns: Status of printing data
 */
extern ret_t mv_dcll_print_forward(p_mv_dcll_t plist, SHOWDATAPROC pshowdataproc);

/**
 * Function Name: mv_dcll_print_reverse
 * Function Brief: This function will print the data in reverse order
 * Input Params: 1) List
 * 				 2) Show Data Callback function pointer
 * Returns: Staus of printing data
 */
extern ret_t mv_dcll_print_reverse(p_mv_dcll_t plist, SHOWDATAPROC pshowdataproc);

/**
 * Function Name: mv_dcll_destroy
 * Function Brief: This function will destroy the passed list
 * Input Params: 1) Pointer to list
 * 				 2) Destroy Data Callback function pointer
 * Returns: Status of detroying the list
 */
extern ret_t mv_dcll_destroy(pp_mv_dcll_t pplist);

#endif /* _MV_DCLL_H */

