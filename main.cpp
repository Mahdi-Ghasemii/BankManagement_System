#pragma once


#include <iostream>
#include "Banks.h"
#include "Bank Manager.h"
#include "Accounts.h"
#include <windows.h>
#include "Header.h"
#include "System_Manager.h"
#include <math.h>

using namespace std;






std::vector<Customers> All_Customers;

std::vector<BankManagers> All_BankManagers;

std::vector<Banks> All_Banks;

std::vector<System_Manager> SystemManagers;





int main(void) {




	system("cls");


	Date obj1(1350, 3, 14);
	/*
	All_Customers.resize(All_Customers.size() + 1);
	All_Customers[All_Customers.size() - 1].Set_All("1", "1", "1", "1", 1);*/

	Banks::Read_Form_File();

	Customers::Read_Form_File();



	if (All_BankManagers.size() == 0) {
		All_BankManagers.resize(1);
	}
	SystemManagers.resize(1);

	All_BankManagers[0].Set_All("Masood", "Maghadami", "Masooti", "123456789", "Masood123@gmail.com", 112346578, obj1);

	if (All_Banks.size() == 0) {
		All_Banks.resize(1);
	}
	All_Banks[0].Set_All("Saderat", 1300, 1, &All_BankManagers[0]);

	SystemManagers[0].Set_All("Abdolnaser", "Hemati", "Abdol", "192837", "AbdolNaserMafia@gmail.com", 12345678, obj1);







	//BankManagers::Read_From_files();

	Main_Menu();

	return 0;
}

void Main_Menu() {

	system("cls");

	cout << ANSI_COLOR_RED"\n\n\t      **************************************** Main Page ****************************************\n\n\n";


	cout << ANSI_COLOR_CYAN << "$$$$$$$$$$ Welcome to the BEST Bank System in the World \n\n\n";


	cout << ANSI_COLOR_YELLOW"\t1. Login to the Account\t\t\t\t\t 2. Create Customer Account\n\n";

	cout << ANSI_COLOR_GREEN << "\n\n\t Input : ";

	int voroodi;
	cin >> voroodi;

	if (voroodi == 1) {

		log_in_Menu();
	}
	if (voroodi == 2) {
		All_Customers.resize(All_Customers.size() + 1);
		All_Customers[All_Customers.size() - 1].Make_Customer();
		Main_Menu();
	}

}


void log_in_Menu(void)
{


	system("cls");

	cout << ANSI_COLOR_CYAN"\n\n          **************************************** Log in to the Acount ****************************************\n\n\n";
	cout << ANSI_COLOR_MAGNETA"\n\n\n$$$$$$$$$$$  Please Fill in the blanks  to go to your page ";
	time_t k = time(NULL);
	cout << ANSI_COLOR_RED" \t\t Exact Time :  " << asctime(localtime(&k)) << endl << endl << endl;


	string usernamevoroodi, passwordvroodi;
	cout << ANSI_COLOR_GREEN"  Username  :  ";

	cin >> usernamevoroodi;
	cout << endl;


	cout << "  Password  :  ";
	cin >> passwordvroodi;
	cout << endl;

	int i;

	cout << ANSI_COLOR_RESET << "\n\n\n\t\t\t\t\t      Checking Information ...";

	Sleep(2000);

	for (i = 0; i < All_Customers.size(); i++) {

		if (All_Customers[i].Sehat_Sanji(usernamevoroodi, passwordvroodi) == true) {
			All_Customers[i].Menu_Customer();
			exit(0);

		}


	}





	int  j;
	for (i = 0; i < All_Banks.size(); i++) {


		for (j = 0; j < All_Banks[i].Get_Num_Admins(); j++) {

			if (All_Banks[i].Get_BankManagers(j).Sehat_Sanji(usernamevoroodi, passwordvroodi) == true) {

				All_Banks[i].Get_BankManagers(j).Menu_BankManager();

			}

		}


	}

	if (SystemManagers[0].Sehat_Sanji(usernamevoroodi, passwordvroodi) == true) {

		SystemManagers[0].Menu_BankManager();
	}


	cout << ANSI_COLOR_RED << "\n\n\n\t\t\t\t\tWrong UserName or Password :)";

	Sleep(1000);
	Main_Menu();

}




void Delay1(string str, int Seconds) {

	cout << ANSI_COLOR_RESET << str;

	Sleep(Seconds);


}

bool Check_Tedade_Argham(int adad, int Max, int Min) {

	int x = 0;

	int temp = pow(10, Min - 1);
	if ((adad / temp) < 1) {
		cout << ANSI_COLOR_RED << "\nYou Should Enter at least " << Min << " digits\n" << ANSI_COLOR_RESET;
		x++;
	}
	temp = pow(10, Max);
	if (adad / temp >= 1) {
		cout << ANSI_COLOR_RED << "\nYou Should Enter at Max " << Max << " digits\n" << ANSI_COLOR_RESET;
		x++;
	}

	return !x;


}
