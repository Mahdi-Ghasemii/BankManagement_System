#include "System_Manager.h"
#include "Header.h"
#include <windows.h>

extern std::vector<BankManagers> All_BankManagers;


extern std::vector<Banks> All_Banks;


void System_Manager::Menu_BankManager() {

	system("cls");


	cout << ANSI_COLOR_CYAN << "\n\n      ******************************************** General Manager ********************************************\n\n\n\n\n";
	cout << ANSI_COLOR_RED << " $$$$$$$$$$  Hi  " << this->Name;
	time_t k = time(NULL);
	cout << "\t\t\t\t\t      Exact Time :  " << asctime(localtime(&k)) << "\n\n";
	cout << ANSI_COLOR_YELLOW << "\n\n\t\t 1. Add Bank   \t\t\t     \t\t\t2. Add BankManager";

	cout << "\n\n\t\t 3. Add Customer \t\t\t\t\t4. Check All Banks ";
	cout << "\n\n\t\t 5. Show All Customers    \t\t\t\t6. Show All BankManagers";
	cout << "\n\n\n\t\t\t\t\t\t 7. Sign Out\n\n\n\n";
	cout << ANSI_COLOR_MAGNETA" Enter the number or the text to go to each part\n\n";
	cout << ANSI_COLOR_GREEN"input : ";

	int x;

	cin >> x;

	if (x == 1)
		this->AddBank();

	else if (x == 2)
		this->AddBankManager();

	else if (x == 3)
		this->AddCustomer();

	else if (x == 4)
		this->Check_All_Banks();

	else if (x == 5)
		Show_All_Customers();

	else if (x == 6)
		Show_All_BankManagers();

	else if (x == 7)
		Main_Menu();






}

void System_Manager::AddBankManager() {

	system("cls");


	cout << ANSI_COLOR_CYAN << "\n\n      ******************************************** Create Bank Manager ********************************************\n\n\n\n\n";
	cout << ANSI_COLOR_RED << " $$$$$$$$$$  Hi  " << this->Name;
	time_t k = time(NULL);
	cout << "\t\t\t\t\t\t\t      Exact Time :  " << asctime(localtime(&k)) << "\n\n";

	cout << ANSI_COLOR_MAGNETA"\n\n\n$$$$$$$$$$$  Please Fill in the blanks  to Create Bank Manager \n\n\n\n";



	string x;

	cout << ANSI_COLOR_YELLOW << " Bank Name : ";
	cin >> x;

	int i;
	for (i = 0; i < All_Banks.size(); i++) {

		if (All_Banks[i].Get_BankName() == x) {

			All_Banks[i].Set_AdminsSize();
			All_Banks[i].Get_BankManagers(All_Banks[i].Get_Num_Admins() - 1).Set_All_From_User();
			All_Banks[i].Get_BankManagers(All_Banks[i].Get_Num_Admins() - 1).index = All_Banks[i].ID;

			cout << ANSI_COLOR_RESET << "\n\n\n\t\t\t\t\t\tRegistring Information";

			All_Banks[i].Get_BankManagers(All_Banks[i].Get_Num_Admins() - 1).index = All_Banks[i].ID;

			Sleep(2000);

			Menu_BankManager();

		}
	}

	cout << ANSI_COLOR_RED << "\n\n\n\n\t\t\t\t\t\tBank Name Is Wrong";

	Sleep(2000);

	Menu_BankManager();
}

void System_Manager::AddBank() {

	system("cls");

	cout << ANSI_COLOR_CYAN << "\n\n      ******************************************** Create Bank ********************************************\n\n\n\n\n";
	cout << ANSI_COLOR_RED << " $$$$$$$$$$  Hi  " << this->Name;
	time_t k = time(NULL);
	cout << "\t\t\t\t\t      Exact Time :  " << asctime(localtime(&k)) << "\n\n";

	cout << ANSI_COLOR_MAGNETA"\n\n\n$$$$$$$$$$$  Please Fill in the blanks  to Create Bank \n\n\n" << ANSI_COLOR_YELLOW;


	All_Banks.resize(All_Banks.size() + 1);

	All_Banks[All_Banks.size() - 1].Set_All_From_User();

	All_Banks[All_Banks.size() - 1].ID = All_Banks.size() - 1;

	cout << ANSI_COLOR_RESET << "\n\n\n\t\t\t\t\t\tRegistering Information";

	Sleep(2000);

	Menu_BankManager();

}

void System_Manager::AddCustomer() {


	system("cls");

	cout << ANSI_COLOR_CYAN << "\n\n      ******************************************** Add Customer ********************************************\n\n\n\n\n";
	cout << ANSI_COLOR_RED << " $$$$$$$$$$  Hi  " << this->Name;
	time_t k = time(NULL);
	cout << "\t\t\t\t\t\t\t      Exact Time :  \n\n" << asctime(localtime(&k));

	cout << ANSI_COLOR_MAGNETA"\n\n\n$$$$$$$$$$$  Please Fill in the blanks to Add Customer ";



	All_Customers.resize(All_Customers.size() + 1);

	All_Customers[All_Customers.size() - 1].Make_Customer();





	Sleep(2000);

	Menu_BankManager();




}

void System_Manager::Check_All_Banks() {

	system("cls");

	cout << ANSI_COLOR_RED << "\n\n\t\t****************************************Check All Banks ****************************************\n\n\n\n\n";

	cout << ANSI_COLOR_YELLOW;

	int i;

	for (i = 0; i < All_Banks.size(); i++) {

		cout << "\t\t\t\t" << i + 1 << ". " << " Name : " << All_Banks[i].Get_BankName() << "\t\t" << "Foundation Year : " << All_Banks[i].Get_FoundationYear() << "\n\n";

	}


	Sleep(7000);

	Menu_BankManager();







}

void System_Manager::Show_All_Customers() {

	system("cls");

	cout << ANSI_COLOR_CYAN << "\n\n      ******************************************** Show All Customers ********************************************\n\n\n\n\n";

	int Num_All_Loans;
	int Num_All_Accounts;

	int i, j;
	for (i = 0; i < All_Customers.size(); i++) {

		Num_All_Accounts = 0;
		Num_All_Loans = 0;

		for (j = 0; j < All_Banks.size(); j++) {
			if (All_Customers[i].Get_Loan(j).Get_Amount() > 0)
				Num_All_Loans++;
		}
		for (j = 0; j < All_Banks.size(); j++) {
			Num_All_Accounts += All_Customers[i].Get_Size_Accounts(j);
		}

		cout << ANSI_COLOR_YELLOW << "\t\tUserName : " << All_Customers[i]._GetUserName() << " | Name : " << All_Customers[i].GetName() << " | NationalCode : " << All_Customers[i].GetNationalCode()
			<< " | Number of All Accounts : " << Num_All_Accounts << " | Number of All Loans : " << Num_All_Loans << "\n\n";


	}

	Sleep(7000);

	this->Menu_BankManager();
}

void System_Manager::Show_All_BankManagers() {


	system("cls");

	cout << ANSI_COLOR_CYAN << "\n\n      ************************************ Show All BnankManagers ************************************      \n\n\n\n\n\n\n\n";

	int i, j;

	for (i = 0; i < All_Banks.size(); i++) {

		for (j = 0; j < All_Banks[i].Get_Num_Admins(); j++) {

			cout << ANSI_COLOR_YELLOW << "\tWork in Bank " << All_Banks[i].Get_BankName() << " | UserName : " << All_Banks[i].Get_BankManagers(j)._GetUserName() << " | Name : " << All_Banks[i].Get_BankManagers(j).GetName() << " | NationalCode : "
				<< All_Banks[i].Get_BankManagers(j).GetNationalCode() << "\n\n";

		}
	}
	Sleep(7000);

	this->Menu_BankManager();

}