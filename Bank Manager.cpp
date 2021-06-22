#pragma once

#include "Bank Manager.h"
#include "Header.h"
#include <fstream>
#include <windows.h>
#pragma warning(disable:4996)

using namespace std;



BankManagers::BankManagers() {

	Name = "";
	LastName = "";
	Password = "";
	UserName = "";
	NationalCode = 0;
	Email = "";

	for (int i = 0; i < 10; i++)
		Customer_Applys[i] = 0;


}

BankManagers::BankManagers(string _Name, string _LastName, string _UserName, string _Password, string _Email, int _NationalCode, Date _BirthDate) {

	Name = _Name;
	LastName = _LastName;

	Password = _Password;
	UserName = _UserName;
	Email = _Email;

	BirthDate = _BirthDate;
	NationalCode = _NationalCode;

	for (int i = 0; i < 10; i++)
		Customer_Applys[i] = 0;



}

void BankManagers::Set_All(string _Name, string _LastName, string _UserName, string _Password, string _Email, int _NationalCode, Date _BirthDate) {

	Name = _Name;
	LastName = _LastName;

	Password = _Password;
	UserName = _UserName;
	Email = _Email;

	BirthDate = _BirthDate;
	NationalCode = _NationalCode;

	Banks::Write_on_File();

}


bool BankManagers::Sehat_Sanji(string _UserName, string _Password) {
	if (Password == _Password && UserName == _UserName) {
		return true;
	}

	return false;

}


void BankManagers::Menu_BankManager() {

	system("cls");


	cout << ANSI_COLOR_CYAN << "\n\n      ******************************************** MENU Bank Manager ********************************************\n\n\n\n\n";

	cout << ANSI_COLOR_RED << "$$$$$$$$$$ Hi  " << this->Name << " , Welcome to the management panel of " << All_Banks[index].Get_BankName() << " Bank";
	time_t k = time(NULL);
	cout << "\t\tExact Time :  " << asctime(localtime(&k)) << "\n\n";
	cout << ANSI_COLOR_YELLOW << "\n\n\t\t1. Check Loan Applys              \t            2. Check Create Account Applys";
	cout << "\n\n\n\t\t3. Show All Customers in the Bank \t      \t    4. Show Other BankManagers in the Bank \n\n\n\n";
	cout << "\t\t\t\t\t 5. Sign Out \n\n\n\n";
	cout << ANSI_COLOR_MAGNETA"Enter the number or the text to go to each part\n\n";
	cout << ANSI_COLOR_GREEN"input : ";

	int x;

	std::cin >> x;

	if (x == 1)
		this->Check_Loan_Applys();

	else if (x == 2)
		this->Check_CreateAccount_Applys();

	else if (x == 3)
		Show_All_Customers_In_the_Bank();

	else if (x == 4)
		Show_All_BankManagers_in_The_Bank();

	else if (x == 5)
		Main_Menu();



}

void BankManagers::Set_Customer_Applys(int _account_type) {

	Customer_Applys[0] = _account_type;

}

void BankManagers::Check_Loan_Applys() {

	int i, j;

	for (i = 0; i < All_Customers.size(); i++) {



		if (All_Customers[i].Get_Loan(index).Get_Answer_of_Apply_Loan() == 0) {

			cout << "UserName : " << All_Customers[i]._GetUserName() << endl;

			cout << "NationalCode : " << All_Customers[i].GetNationalCode() << endl;

			cout << "This Customer Has Applyed a Laon " << endl;

			cout << "Requested Amount : " << All_Customers[i].Get_Loan(index).Get_Amount() << endl;

			cout << "Number of Installments : " << All_Customers[i].Get_Loan(index).Get_NumGhests() << endl;

			printf(ANSI_COLOR_CYAN"\n\n 1. Accept\t\t 2. Reject\t\t 3. Next\n\n\n");

			printf(ANSI_COLOR_MAGNETA"\n");

			cout << "Enter Propriate Number : ";

			int x;

			cin >> x;

			if (x == 1) {




				All_Customers[i].Get_Loan(index).Set_Answer_of_Apply_Loan(1);

				All_Customers[i].Get_Loan(index).Set_Time_Apply_Loan();

				int y;

				for (y = 0; y < All_Customers[i].Get_Size_Accounts(index); y++) {

					if (All_Customers[i].Get_Accounts(index, y).Get_Account_Type() == Customer_Applys[i])
						break;
				}
				(All_Customers[i].Get_Accounts(index, y).Get_Inventory()) += All_Customers[i].Get_Loan(index).Get_Amount();
			}
			else if (x == 2) {
				All_Customers[i].Get_Loan(index).Set_Answer_of_Apply_Loan(-1);

				continue;
			}
			else if (x == 3) {
				All_Customers[i].Get_Loan(index).Set_Answer_of_Apply_Loan(0);

				continue;
			}


		}






	}

	Sleep(2000);

	Customers::Write_on_Files();


	Menu_BankManager();

}

void BankManagers::Check_CreateAccount_Applys() {


	int i, z;

	for (i = 0; i < All_Customers.size(); i++) {


		for (z = 0; z < All_Customers[i].Get_Size_Accounts(index); z++) {

			if (!(All_Customers[i].Get_Accounts(index, z).Get_Answer_of_BankManager() == 0)) {
				continue;
			}

			cout << ANSI_COLOR_YELLOW << "UserName : " << All_Customers[i]._GetUserName() << endl;

			cout << "NationalCode : " << All_Customers[i].GetNationalCode() << endl;

			cout << "This Customer Requsted to Create an Account" << endl;

			cout << ANSI_COLOR_CYAN"\n\n 1. Accept\t\t 2. Reject\t\t 3. Next\n\n\n";


			cout << ANSI_COLOR_MAGNETA << "Enter Propriate Number : ";

			int x;

			cin >> x;

			if (x == 1) {

				time_t now = time(NULL);
				All_Customers[i].Get_Accounts(index, z).Set_Answer_of_BankManager(1);

				All_Customers[i].Get_Accounts(index, z).Set_Time_Create_Account();

				All_Customers[i].Get_Accounts(index, z).Set_Date();
			}
			else if (x == 2) {

				All_Customers[i].Get_Accounts(index, z).Set_Answer_of_BankManager(-1);

				All_Customers[i].Delete_Account(index, z);

				continue;
			}
			else if (x == 3) {

				All_Customers[i].Get_Accounts(index, z).Set_Answer_of_BankManager(0);

				continue;
			}


		}





	}


	Sleep(2000);

	Customers::Write_on_Files();


	Menu_BankManager();

}


void BankManagers::Set_All_From_User() {

	cout << ANSI_COLOR_YELLOW << "\n\n Name : ";
	cin >> this->Name;


	cout << "\n\n Last Name : ";
	cin >> this->LastName;


	cout << "\n\n NationalCode : ";
	cin >> this->NationalCode;


	cout << "\n\n UserName : ";
	cin >> this->UserName;


	cout << "\n\n Password : ";
	cin >> this->Password;

	cout << "\n\n Email : ";
	cin >> this->Email;



	BirthDate.Set_All_From_User();

	Banks::Write_on_File();


}


void BankManagers::Show_All_Customers_In_the_Bank() {

	system("cls");

	cout << ANSI_COLOR_CYAN << "\n\n      ******************************************** Show Customers ********************************************\n\n\n\n\n";

	for (int i = 0; i < All_Customers.size(); i++) {

		if (All_Customers[i].Get_Size_Accounts(index) != 0) {


			cout << ANSI_COLOR_YELLOW << "\t\tUserName : " << All_Customers[i]._GetUserName() << " | Name : " << All_Customers[i].GetName() << " | NationalCode : "
				<< All_Customers[i].GetNationalCode() << " | Number of Accounts : " << All_Customers[i].Get_Size_Accounts(index) << " | Number of Loans : ";

			if (All_Customers[i].Get_Loan(index).Get_Amount() > 0) {
				cout << 1;
			}
			else cout << 0;

			cout << "\n\n";
		}
	}

	Sleep(5000);

	this->Menu_BankManager();


}

void BankManagers::Show_All_BankManagers_in_The_Bank() {

	system("cls");

	cout << ANSI_COLOR_CYAN << "\n\n      ************************************ Show BnankManagers List in the Bank ************************************      \n\n\n\n\n\n\n\n";

	for (int i = 0; i < All_Banks[index].Get_Num_Admins(); i++) {

		if (All_Banks[index].Get_BankManagers(i).UserName == this->UserName)
			cout << ANSI_COLOR_MAGNETA << "\t\t\tYou : \t\t";
		else cout << "\t\t\t\t\t";

		cout << ANSI_COLOR_YELLOW << "UserName : " << All_Banks[index].Get_BankManagers(i).UserName << " | Name : " << All_Banks[index].Get_BankManagers(i).Name << " | NationalCode : "
			<< All_Banks[index].Get_BankManagers(i).NationalCode << "\n\n";




	}

	Sleep(7000);

	this->Menu_BankManager();


}

