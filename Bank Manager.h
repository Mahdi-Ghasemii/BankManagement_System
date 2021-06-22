#pragma once

#include "Date.h"
#include <string.h>
#include<string>
#include "Customers.h"

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/string.hpp>

#pragma warning(disable:4996)

using namespace std;

class BankManagers {

	friend class boost::serialization::access;



protected:

	string Name;
	string LastName;

	string Password;
	string UserName;
	string BankName;
	string Email;


	int NationalCode;
	int Customer_Applys[10];


	Date BirthDate;


	template<class Archive>

	void serialize(Archive& ar, const unsigned int version) {


		ar& Name;
		ar& LastName;

		ar& Password;
		ar& UserName;
		ar& BankName;
		ar& Email;

		ar& NationalCode;
		ar& Customer_Applys;
		ar& index;

		ar& BirthDate;
	}

public:

	int index;


	BankManagers();

	BankManagers(string _Name, string _LastName, string _UserName, string _Password, string _Email, int _NationalCode, Date _BirthDate);

	bool Sehat_Sanji(string _Password, string _UserName);

	void Menu_BankManager();

	void Set_All(string _Name, string _LastName, string _UserName, string _Password, string _Email, int _NationalCode, Date _BirthDate);

	void Set_Customer_Applys(int _account_type);

	void Check_Loan_Applys();

	void Check_CreateAccount_Applys();

	void Set_All_From_User();

	void Show_All_Customers_In_the_Bank();

	void Show_All_BankManagers_in_The_Bank();


	string GetName() {
		return Name;
	}
	string _GetUserName() {
		return UserName;
	}
	int GetNationalCode() {
		return NationalCode;
	}
	
};
