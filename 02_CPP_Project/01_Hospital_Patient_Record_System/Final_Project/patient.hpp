
#pragma once 

#include <iostream>
#include <string>
using namespace std;

#ifndef	SUCCESS
#define	SUCCESS	0
#endif

#ifndef	FAILURE
#define	FAILURE	1
#endif

typedef int ret_t;

class patient
{
private:
	// Data Members
	string p_first_name;
	string p_last_name;
	unsigned int p_age;
	unsigned int p_id;
	unsigned long long p_contact;
	string p_disease;

public:
	// Data Member

	// Default Constructor
	patient() : p_first_name(""), p_last_name(""), p_age(0), p_id(0), p_contact(0), p_disease("")
	{
		// Code
		this->set_patient_first_name();
		this->set_patient_last_name();
		this->set_patient_age();
		this->set_patient_id();
		this->set_patient_contact();
		this->set_patient_disease();	
	}

	// Parameterized Constructor
	patient(string pfnm, string plnm, unsigned int page, unsigned int pid, unsigned long long pcon, string pdis) : 
	p_first_name(pfnm), p_last_name(plnm), p_age(page), p_id(pid), p_contact(pcon), p_disease(pdis)
	{		}

	// Setter functions
	void set_patient_first_name()
	{
		// Code
		cout << "Enter patient first name: ";
		cin >> p_first_name;
	}

	void set_patient_last_name()
	{
		// Code
		cout << "Enter patient last name: ";
		cin >> p_last_name;
	}

	void set_patient_age()
	{
		// Code
		cout << "Enter patient age: ";
		cin >> p_age;
		if(p_age == 0)
		{
			cout << "-- Please enter valid age of patient.\nAgain enter patient age: ";
			cin >> p_age;
		}
	}

	void set_patient_id()
	{
		// Code
		cout << "Enter patient id: ";
		cin >> p_id;
		if(p_id == 0)
		{
			cout << "-- Please enter valid patient id.\nAgain enter patient id: ";
			cin >> p_id;
		}
	}

	void set_patient_contact()
	{
		// Code
		cout << "Enter patient contact: ";
		cin >> p_contact;
		if(p_contact == 0 || p_contact > 9999999999)
		{
			cout << "-- Please enter valid contact number of patient.\nAgain enter patient contact: ";
			cin >> p_contact;
		}
	}

	void set_patient_disease()
	{
		// Code
		cout << "Enter patient disease: ";
		cin >> p_disease;
	}

	// Getter functions
	string get_patient_first_name()
	{
		// Code	
		return(p_first_name);
	}

	string get_patient_last_name()
	{
		// Code	
		return(p_last_name);
	}

	unsigned int get_patient_age()
	{
		// Code	
		return(p_age);
	}

	unsigned int get_patient_id()
	{
		// Code	
		return(p_id);
	}

	unsigned long get_patient_contact()
	{
		// Code	
		return(p_contact);
	}

	string get_patient_disease()
	{
		// Code	
		return(p_disease);
	}
	

	ret_t display_patient()
	{
		// Code
		cout << "{" << endl;
		cout << "\tFirst Name: " << this->get_patient_first_name() << endl;
		cout << "\tLast  Name: " << this->get_patient_last_name() << endl;
		cout << "\tAge: " << this->get_patient_age() << endl;
		cout << "\tID: " << this->get_patient_id() << endl;
		cout << "\tContact: " << this->get_patient_contact() << endl;
		cout << "\tDisease: " << this->get_patient_disease() << endl;
		cout << " }->" << endl;

		return(SUCCESS);
	}

};
