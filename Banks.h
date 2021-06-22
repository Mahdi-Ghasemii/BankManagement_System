#pragma once

class BankManagers;


#include "Customers.h"

#include "Bank Manager.h"

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>



class Banks {

	friend class boost::serialization::access;


private:


	string BankName;

	int FoundationYear;

	vector<BankManagers> Admin;

	template<class Archive>

	void serialize(Archive& ar, const unsigned int version) {

		ar& BankName;

		ar& FoundationYear;
		ar& ID;

		ar& Admin;

	}


public:

	int ID;


	Banks();

	Banks(char* _Name, int _FoundationYear, int _Num_Admins, BankManagers* _Admin);


	void Set_All(string _Name, int _FoundationYear, int _Num_Admins, BankManagers* _Admin);

	void Set_All_From_User();

	~Banks();

	BankManagers& Get_BankManagers(int id);

	int Get_Num_Admins();

	static int Get_Num_Banks;

	string Get_BankName();

	int Get_FoundationYear() {
		return FoundationYear;
	}

	static void Write_on_File();

	static void Read_Form_File();

	void Set_AdminsSize();
};