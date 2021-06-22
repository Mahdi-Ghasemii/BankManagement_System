#pragma once

#include "Date.h"
#include "Accounts.h"
#include "Loan.h"
#include <string.h>

#include "Banks.h"

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>




class Customers {

	friend class boost::serialization::access;

private:

	string Name;
	string LastName;

	string UserName;
	string Password;

	int NationalCode;

	string Email;


	Date BirthDate;

	vector<vector<Accounts>> account;


	vector<Loan> Debt;


	static int Num_All_Hesabs_in_world;

	template<class Archive>

	void serialize(Archive& ar, const unsigned int version) {

		ar& Name;
		ar& LastName;

		ar& UserName;
		ar& Password;

		ar& Email;

		ar& NationalCode;

		ar& BirthDate;

		ar& account;

		ar& Debt;

		ar& Num_All_Hesabs_in_world;

	}
public:


	Customers();


	void Set_All(string _Name, string _LastName, string _UserName, string _Password, string _Email, int _Nationalcode);

	void Make_Customer();

	int GetNationalCode();

	int Get_Size_Accounts(int i);


	string _GetUserName() {
		return UserName;
	}

	/*void Set_Last_Bank_Answer(string x) {
		Last_Bank_Answer = x;
	}*/

	void Add_Account();

	void PrintStar(int Num) {

		cout << endl;
		for (int i = 0; i < Num; i++) {

			cout << ANSI_COLOR_RED << "\t\t    *\t\t\t\t\t\t\t\t\t*" << endl;

		}

	}

	void Check_Card_or_Continue(int* a) {


		if (*a == -1) {

			Check_Accounts(1);

		}

	}

	bool Sehat_Sanji(string _Password, string _UserName);

	string GetName() {
		return Name;
	}

	void Menu_Customer();

	void Check_Accounts(int WhichFunction);

	void PrintCard(int i, int j);

	void Apply_Loan();

	Accounts& Get_Accounts(int i, int j);

	Loan& Get_Loan(int i);

	void Check_Loans_Situation();

	void Money_Transfer();

	//*********



	static void Resize_All(int NewSize);

	void Resize_Accounts_va_Debts(int NewSize);

	void Delete_Account(int i, int j);

	void Calculate_SoodeHesabvaVam();

	static void Read_Form_File();

	static void Write_on_Files();
};