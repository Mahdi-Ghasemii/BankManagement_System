#pragma once

#include <string>

#include "Date.h"


#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/string.hpp>



#pragma warning(disable:4996)





class Accounts {


	friend class boost::serialization::access;


private:

	Date Foundation_Date;

	long long int Shomare_Hesab;
	int Cvv2;

	long long int firstPassword;
	int SecondPassword;


	int Bank_ID;
	int Inventory;

	int account_Type;

	int Answer_of_BankManager;

	int Time_Create_Account;

	template<class Archive>

	void serialize(Archive& ar, const unsigned int version) {

		ar& Foundation_Date;

		ar& Shomare_Hesab;
		ar& Cvv2;

		ar& firstPassword;
		ar& SecondPassword;


		ar& Bank_ID;
		ar& Inventory;

		ar& account_Type;

		ar& Answer_of_BankManager;

		ar& Time_Create_Account;
	}

public:


	//int Num_Accounts[10];
	Accounts();


	void Make_Cvv2_Shomare(int id);

	void Set_Account_Type();

	void Set_Account_Type(int x);

	void Calculate_Inventory();


	long long int GetShomareHesab();

	int Get_Cvv2();

	Date Get_date();

	int Get_SecondPassword();

	void Set_Date() {

		time_t now = time(NULL);

		tm* timePtr = localtime(&now);


		Foundation_Date.SetAll(timePtr->tm_year + 1900, timePtr->tm_mon, timePtr->tm_mday);
	}

	int Get_Account_Type();

	int& Get_Inventory() {
		return Inventory;
	}

	void Set_Answer_of_BankManager(int _Answer_of_BankManager);
	int Get_Answer_of_BankManager();

	int Get_Time_Create_Account();

	void Set_Time_Create_Account();
};