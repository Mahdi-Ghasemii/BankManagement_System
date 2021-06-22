#pragma once

#include "Banks.h"
#include "Bank Manager.h"
#include <iostream>
#include <fstream>
#include <filesystem>


extern std::vector<Banks> All_Banks;

extern std::vector<Customers> All_Customers;

using namespace std;


	Banks::Banks() {

		BankName = "";

		FoundationYear = 0;

		//ID = (this - &All_Banks[0]) / sizeof(Banks);

		

		Customers::Resize_All(All_Banks.size() + 1);
		
	}

	Banks::Banks(char* _Name, int _FoundationYear, int _Num_Admins, BankManagers* _Admin) {

		Admin.resize(_Num_Admins);

		All_Banks.resize(All_Banks.size() + 1);

		BankName = "";

		FoundationYear = _FoundationYear;
		ID = (this - &All_Banks[0]) / sizeof(Banks);

		for (int i = 0; i < _Num_Admins; i++) {
			Admin[i] = _Admin[i];
			Admin[i].index = ID;
		}
		
		Customers::Resize_All(All_Banks.size() + 1);

		Banks::Write_on_File();
	}


	void Banks::Set_All(string _Name, int _FoundationYear, int _Num_Admins, BankManagers* _Admin) {

		Admin.resize(_Num_Admins);


		BankName = "";

		FoundationYear = _FoundationYear;

		ID = (this - &All_Banks[0]) / sizeof(Banks);
		Admin.resize(_Num_Admins);

		for (int i = 0; i < _Num_Admins; i++) {
			Admin[i] = _Admin[i];
			Admin[i].index = ID;
		}
		


		this->BankName = _Name;
		
		Customers::Resize_All(All_Banks.size());

		Banks::Write_on_File();

	}

	BankManagers& Banks::Get_BankManagers(int id) {

		return Admin[id];


	}

	int Banks::Get_Num_Admins() {
		return Admin.size();
	}


	Banks::~Banks() {
		/*
		int a;

		ofstream file;

		file.open("Bank.txt", ios::out);

		boost::archive::text_oarchive Write_On_Files(file);
		for (a = 0; a < Num_All_Banks; a++) {

			Write_On_Files << All_Banks[a];
		}


		file.close();
		*/
		//delete[]Admin;
	}


	string Banks::Get_BankName() {
		return this->BankName;
	}


	void Banks::Set_All_From_User() {


		cout << " Bank Name :";
		cin >> this->BankName;

		cout << "\n\n Foundation Year :";
		cin >> this->FoundationYear;

		Customers::Resize_All(All_Banks.size() + 1);

		Banks::Write_on_File();

	}

	void Banks::Write_on_File() {


		ofstream file;

		file.open("Bank.txt", ios::out);

		boost::archive::text_oarchive os(file);

		for (int i = 0; i < All_Banks.size(); i++) {

			os << All_Banks[i];

		}

		file.close();



	}

	void Banks::Read_Form_File() {


		int a;

		std::ifstream file;

		file.open("Bank.txt", ios::in);

		

		if (file.peek() == std::ifstream::traits_type::eof())
		{
			Banks::Write_on_File();
			file.open("Bank.txt", ios::in);
		}



		boost::archive::text_iarchive os(file);
		for (a = 0; file.good(); a++) {

			All_Banks.resize(All_Banks.size() + 1);

			os >> All_Banks[a];

			for (int i = 0; i < All_Banks[a].Admin.size(); i++)
				All_Banks[a].Admin[i].index = a;
		}


		file.close();
	}

	void Banks::Set_AdminsSize() {

		Admin.resize(Admin.size() + 1);

	}