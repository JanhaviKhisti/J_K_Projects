
#include <iostream>
#include <string>

#include "patient.hpp"
#include "record_system.hpp"

using namespace std;

// Global Declaration;
record_system record_list;

int main()
{
	// Code
	int choice;
	unsigned int id;
	//record record_list;

	cout << "______________________________________________________________" << endl << endl;
	cout << "       *** Welcome to Hospital Patient Record System ***          " << endl << endl;
	cout << "   Choice Options: "<< endl << endl;
	cout << "\t1. Insert Patient Record\n";
	cout << "\t2. Search Record by Patient ID\n";
	cout << "\t3. Remove Recent Patient Record\n";
	cout << "\t4. Remove Record by Patient ID\n";
	cout << "\t5. Show All Patient Records\n";
	cout << "\t0. Exit. " << endl << endl;
	cout << "______________________________________________________________" << endl;
	 
	while(1)
	{
		cout << "\nEnter The Choice: ";
		cin >> choice;

		if(choice == 0)
		{
			record_list.prog_exit();
			break;
		}
		else if(choice == 1)
		{
			record_list.insert_record();
		}
		else if(choice == 2)
		{
			cout << "Enter Patient ID: ";
			cin >> id;
			record_list.search_record_by_id(id);
		}
		else if(choice == 3)
		{
			record_list.remove_recent_record();
		}
		else if(choice == 4)
		{
			cout << "Enter Patient ID: ";
			cin >> id;
			record_list.remove_record_by_id(id);
		}
		else if(choice == 5)
		{
			record_list.show_record();
		}
		else
		{
			cout << "-- Please enter valid choice." << endl;
		}
	}

	return(0);

}

