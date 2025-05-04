
#pragma once

#include <iostream>
#include <string>

#include "patient.hpp"
#include "mv_dcll.hpp"

using namespace std;

// Typedef
typedef	int ret_t;

MV_DCLL<patient*>* plist = new MV_DCLL<patient*>();

class record_system
{
private:
	// Data Members

	// Member Functions
	
public:
	// Constructor
	record_system()
	{
		// Code
	}

	// Member Functions
	ret_t insert_record()
	{
		// Code
		plist->InsertBack(new patient());
		return(SUCCESS);	
	}

	ret_t search_record_by_id(unsigned int id)
	{
		// Code
		// Loop Initialization
		auto itr = plist->begin();
		while(itr != plist->end())
		{
			// Code
			if(((*itr)->get_patient_id()) == id)
			{
				(*itr)->display_patient();
				return(SUCCESS);
			}
			++itr; 
		}	
		cout << "No Patient Record..." << endl;
		return(FAILURE);
	}

	ret_t remove_recent_record()
	{
		// Code
		if(plist->Size() == 0)
		{
			cout << "No Patient Records..." << endl;
			return(FAILURE);
		}

		plist->RemoveBack();
		
		cout << "Recent Patient Record Deleted..." << endl;
		
		return(SUCCESS);
	}

	ret_t remove_record_by_id(unsigned int id)
	{
		// Code
		for(int le = 0; le < plist->Size(); le++)
		{
			if(((*plist)[le])->get_patient_id() == id)
			{
				plist->RemoveAt(le);
				cout << "Deleted Patient Record by ID..." << endl;
				return(SUCCESS);
			}
		}
		cout << "No Patient Record..." << endl;
		return(FAILURE);
	}

	ret_t show_record()
	{
		//Code
		// Loop Initialization
		auto itr = plist->begin();
		while(itr != plist->end())
		{
			// Code
			(*itr)->display_patient();
			++itr; 
		}
		return(SUCCESS);
	}

	ret_t prog_exit()
	{
		// Code
		auto itr = plist->begin();
		while(itr != plist->end())
		{
			// Code
			delete(*itr);
			++itr; 
		}
		delete(plist);
		plist = NULL;
		cout << "Exit..." << endl;
		return(SUCCESS);
	}

};

