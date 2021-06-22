#pragma once


#include "Customers.h"
#include <time.h>
#include <ctime>

#include <stdlib.h>
#include "Header.h"
#include <stdlib.h>
#include <windows.h>
#include <fstream>

#pragma warning(disable:4996)

//using namespace std;

int Customers::Num_All_Hesabs_in_world = 0;





Customers::Customers() {


	NationalCode = 0;




	Debt.resize(All_Banks.size());

	Name = "";
	LastName = "";
	Password = "";
	UserName = "";
	Email = "";


	account.resize(All_Banks.size());
}

void Customers::Set_All(string _Name, string _LastName, string _UserName, string _Password, string _Email, int _Nationalcode) {


	Name = _Name;
	LastName = _LastName;
	UserName = _UserName;
	Password = _Password;
	Email = _Email;
	NationalCode = _Nationalcode;


	Customers::Write_on_Files();

}

Loan& Customers::Get_Loan(int i) {

	return Debt[i];

}

void Customers::Make_Customer() {

	system("cls");

	cout << ANSI_COLOR_CYAN << "\n\n      ******************************************** MENU Customer ********************************************\n\n\n\n\n";
	cout << ANSI_COLOR_RED << " $$$$$$$$$$  Hi  " << this->Name;
	time_t k = time(NULL);
	cout << "\t\t\t\t\t\t\t      Exact Time :  " << asctime(localtime(&k)) << "\n\n\n" << ANSI_COLOR_GREEN;


	cout << "\n\n Name : ";
	cin >> this->Name;


	cout << "\n\n Last Name : ";
	cin >> this->LastName;


	cout << "\n\n NationalCode : ";
	cin >> this->NationalCode;

Start:
	while (1) {
		cout << "\n\n UserName : ";
		cin >> this->UserName;

		int i;

		for (i = 0; i < All_Customers.size() - 1; i++) {

			if (this->UserName == All_Customers[i].UserName) {
				cout << ANSI_COLOR_RED << "This UserName is not available";
				goto Start;
			}
		}
		break;

	}
	cout << ANSI_COLOR_GREEN << "\n\n Password : ";
	cin >> this->Password;

	cout << ANSI_COLOR_GREEN << "\n\n Email : ";
	cin >> this->Email;

	BirthDate.Set_All_From_User();



	account.resize(All_Banks.size());
	Debt.resize(All_Banks.size());


	cout << ANSI_COLOR_RESET << "\n\n\n\t\t\t\t\tRegistering Information";
	Sleep(2000);


	Customers::Write_on_Files();


	return;
}

int Customers::GetNationalCode() {
	return NationalCode;
}

void Customers::Add_Account() {


	system("cls");

	printf(ANSI_COLOR_CYAN"\n\n      ******************************************** Add Account ********************************************\n\n\n\n\n");

	cout << ANSI_COLOR_MAGNETA"$$$$$$$$$$$  Please Fill in the blanks  to Add Account ";

	cout << ANSI_COLOR_YELLOW;
	string temp;
	cout << "\n\n\n" << "  The Name of the Bank : " << ANSI_COLOR_RESET;

	cin >> temp;
	int i;
	for (i = 0; i < All_Banks.size(); i++) {

		if (temp == All_Banks[i].Get_BankName()) {

			break;
		}
	}
	if (i == All_Banks.size()) {

		cout << ANSI_COLOR_RED << "\n\n\n\t\t\t\t Sorry , No Bank Was Founded With this Name ";
		Sleep(3000);
		Menu_Customer();
	}
	cout << ANSI_COLOR_YELLOW << "\n\n Type of Account( Short time : 1 |  Long time : 2 | Special Code : 3)\n\n input : " << ANSI_COLOR_RESET;


	int x;
	cin >> x;

	/*
	for (j = 0; j < account[i].size(); j++) {

		if (account[i][j].Get_Account_Type() == x) {
			cout << ANSI_COLOR_RED << "\n\n\n\tSorry , You Have an account wit this type in this Bank";
			Sleep(3000);
			Menu_Customer();
		}
	}
	*/
	account[i].resize(account[i].size() + 1);

	account[i][account[i].size() - 1].Set_Account_Type(x);

	x = account[i].size() - 1;







	this->account[i][x].Make_Cvv2_Shomare(Num_All_Hesabs_in_world);





	//this->account[i][x].Calculate_Inventory(this->Time_Create_Account[i][x]);



	Num_All_Hesabs_in_world++;


	cout << ANSI_COLOR_RESET << "\n\n\t\t\t Your Require Registered on Bank Succesfully , Wait untill the answer";
	Sleep(3000);

	Customers::Write_on_Files();


	this->Menu_Customer();
}

bool Customers::Sehat_Sanji(string _UserName, string _Password) {


	if (Password == _Password && UserName == _UserName) {
		return true;
	}

	return false;

}

void Customers::Menu_Customer() {


	this->Calculate_SoodeHesabvaVam();

	system("cls");


	cout << ANSI_COLOR_CYAN"\n\n      ******************************************** Customers Menu ********************************************\n\n\n\n\n";
	cout << ANSI_COLOR_RED" $$$$$$$$$$  Hi  " << this->Name;
	time_t k = time(NULL);
	cout << ANSI_COLOR_RED"\t\t\t\t\t\t\t      Exact Time :  " << asctime(localtime(&k)) << "\n\n";
	cout << ANSI_COLOR_YELLOW"\n\n\t\t1. Add Account                         \t\t2. Check All Accounts";
	cout << "\n\n\t\t3. Apply for loan                 \t\t4. Check Loans Situation ";
	cout << "\n\n\t\t5. Money transfer                 \t\t6. Sign Out";
	cout << ANSI_COLOR_MAGNETA"\n\n\nEnter the number or the text to go to each part\n\n";
	cout << ANSI_COLOR_GREEN"input : ";

	int voroodi;

	cin >> voroodi;

	if (voroodi == 1) {
		this->Add_Account();
	}
	if (voroodi == 2) {
		Check_Accounts(0);
	}

	if (voroodi == 3) {
		Apply_Loan();
	}

	if (voroodi == 4) {
		Check_Loans_Situation();
	}

	if (voroodi == 5) {
		Money_Transfer();
	}

	if (voroodi == 6) {

		cout << ANSI_COLOR_RESET << "\n\n\n\t\t\t\t\t\tWait for Sign Out";
		Sleep(1000);
		Main_Menu();
	}


}

void Customers::PrintCard(int i, int j) {



	if (!(account[i][j].Get_Answer_of_BankManager() == 1))
		return;


	cout << ANSI_COLOR_RED << "\t\t    *********************************************************************\n" << ANSI_COLOR_RED;
	cout << "\t\t    *" << ANSI_COLOR_RESET << "\t\t\t\t Bank " << All_Banks[i].Get_BankName() << "\t\t\t\t" << ANSI_COLOR_RED << "*";
	PrintStar(4);

	cout << "\t\t    *" << ANSI_COLOR_RESET << "\t\t\tAccount Number  :  " << account[i][j].GetShomareHesab() << "\t\t" << ANSI_COLOR_RED << "*";
	PrintStar(1);


	cout << "\t\t    *" << ANSI_COLOR_RESET << "\t" << "\t\t" << "      Inventory : " << account[i][j].Get_Inventory() << "\t\t\t" << ANSI_COLOR_RED"*";
	PrintStar(1);

	cout << "\t\t    *" << ANSI_COLOR_RESET << "    \tCVV2: " << account[i][j].Get_Cvv2() << "\t\t";

	cout << "Account Opening Date : ";
	account[i][j].Get_date().PrintAll();
	cout << ANSI_COLOR_RED << "\t*\n\t\t    *********************************************************************\n\n\n";




}

void Customers::Check_Accounts(int WhichFunction) {


	int i, j;
	bool x = 0;
	for (i = 0; i < All_Banks.size(); i++) {

		for (j = 0; j < account[i].size(); j++) {

			PrintCard(i, j);
			x = 1;

		}



	}
	if (x == 0) {
		cout << ANSI_COLOR_RED << "\n\n\n\t\t\t\t\tYou Have No Account at all !\n\n";
	}

	cout << ANSI_COLOR_RESET << "\n\n\n\t\t\t\t\tLoading Menu Page...";
	Sleep(5000);


	if (WhichFunction == 0)
		this->Menu_Customer();

	if (WhichFunction == 1);
	//this->Apply_Loan();
}

void Customers::Apply_Loan() {



	system("cls");

	cout << ANSI_COLOR_CYAN"\n\n      ******************************************** Apply Loan Menu ********************************************\n\n\n\n\n";
	cout << ANSI_COLOR_RED" $$$$$$$$$$  Hi  " << this->Name;
	time_t k = time(NULL);
	cout << ANSI_COLOR_RED"\t\t\t\t\t\t\t      Exact Time :  " << asctime(localtime(&k)) << "\n\n";

	cout << ANSI_COLOR_MAGNETA"\n\n\n$$$$$$$$$$$  Please Fill in the blanks  to Apply Loan";

	cout << "\n\n####### Enter -1 everywhere to see your Cards Information";
	string str;

	int x[4];

	long long int y;



	while (1) {
		cout << ANSI_COLOR_YELLOW << "\n\n\n Name of Bank : ";
		cin >> str;

		if (str == "-1") {
			Check_Accounts(1);
			continue;
		}
		else break;
	}

	while (1) {
		cout << "\n\n Account Number : ";
		cin >> y;

		if (y == -1) {
			Check_Accounts(1);
			continue;
		}
		else break;
	}

	while (1) {
		cout << "\n\n Second Password : ";
		cin >> x[0];

		if (x[0] == -1) {
			Check_Accounts(1);
			continue;
		}
		else break;
	}

	while (1) {
		cout << "\n\n CVV2 : ";
		cin >> x[1];

		if (x[1] == -1) {
			Check_Accounts(1);
			continue;
		}
		else break;
	}

	while (1) {
		cout << "\n\n Enter Your Inventory : ";
		cin >> x[2];

		if (x[2] == -1) {
			Check_Accounts(1);
			continue;
		}
		else break;
	}

	while (1) {
		cout << "\n\n Number of Installments : ";
		cin >> x[3];

		if (x[3] == -1) {
			Check_Accounts(1);
			continue;
		}
		else break;
	}
	int i, j, z;

	for (i = 0; i < All_Banks.size(); i++) {
		if (All_Banks[i].Get_BankName() == str) {

			if (Debt[i].Get_Amount() > 0) {

				cout << ANSI_COLOR_RED << "\n\n\n\n\t\t\t\tSorry , You can not get more than one loan from the same bank";

				Sleep(2000);
				Menu_Customer();
			}

			for (j = 0; j < account[i].size(); j++) {

				if ((account[i][j].GetShomareHesab() == y) && (account[i][j].Get_Cvv2() == x[1]) && (account[i][j].Get_SecondPassword() == x[0])) {


					cout << ANSI_COLOR_RESET << "\n\n Your Require Registered on Bank Succesfully , Wait untill the answer";

					for (z = 0; z < All_Banks[i].Get_Num_Admins(); z++) {

						All_Banks[i].Get_BankManagers(z).Set_Customer_Applys(this->account[i][j].Get_Account_Type());

						this->Debt[i].Set_Answer_of_Apply_Loan(0);
					}

					Debt[i].Set_All_From_User(x[2], x[3], i, j);

					goto Out_Of_Loop;

				}


			}
		}
	}

Out_Of_Loop:

	if (i == All_Banks.size()) {
		cout << ANSI_COLOR_RED << "No Account Founded with these identitites:((";
	}


	Sleep(5000);

	this->Menu_Customer();
}

Accounts& Customers::Get_Accounts(int i, int j) {

	return account[i][j];


}

void Customers::Check_Loans_Situation() {



	int i;

	for (i = 0; i < Debt.size(); i++) {

		if (!(Debt[i].Get_Amount() > 0))
			continue;

		cout << ANSI_COLOR_GREEN << "\t\tAmount : " << Debt[i].Get_Amount() << " | Number of Installments : " << Debt[i].Get_NumGhests() << " | Situiation : ";

		if (Debt[i].Get_Answer_of_Apply_Loan() == 1) {
			cout << ANSI_COLOR_RESET << "Accepted :))";
		}
		if (Debt[i].Get_Answer_of_Apply_Loan() == 0) {
			cout << ANSI_COLOR_YELLOW << "Not Checked";
		}
		if (Debt[i].Get_Answer_of_Apply_Loan() == -1) {
			cout << ANSI_COLOR_RED << "Rejected :((";
		}

		cout << endl << endl;

	}

	cout << ANSI_COLOR_RESET << "\t\t\t\tLoading Menu Page";

	Sleep(3000);

	Menu_Customer();
}

int Customers::Get_Size_Accounts(int i) {

	return account[i].size();


}

void Customers::Money_Transfer() {


	int _Inventory;

	long long int Shomare_Karte_Mabdae;

	long long int Shomare_Karte_Maghsad;


	system("cls");

	cout << ANSI_COLOR_CYAN << "\n\n      ******************************************** Money Transfer Page ********************************************\n\n\n\n\n";
	cout << ANSI_COLOR_RED << " $$$$$$$$$$  Hi  " << this->Name;
	time_t k = time(NULL);
	cout << "\t\t\t\t\t\t\t      Exact Time :  " << asctime(localtime(&k)) << "\n\n";

	cout << ANSI_COLOR_MAGNETA"\n\n\n$$$$$$$$$$$  Please Fill in the blanks  to Transfer Money";

	cout << "\n\n####### Enter -1 everywhere to Show your Cards Information";

	while (1) {
		cout << ANSI_COLOR_YELLOW << "\n\n\n Source Card Number : ";
		cin >> Shomare_Karte_Mabdae;

		if (Shomare_Karte_Mabdae == -1) {
			Check_Accounts(1);
			continue;
		}
		else break;
	}

	while (1) {
		cout << "\n\n Destination Card Number : ";
		cin >> Shomare_Karte_Maghsad;

		if (Shomare_Karte_Maghsad == -1) {
			Check_Accounts(1);
			continue;
		}
		else break;
	}

	if (Shomare_Karte_Mabdae == Shomare_Karte_Maghsad && Shomare_Karte_Maghsad != -1) {
		cout << ANSI_COLOR_RED << "\n\n\n\t\t\t Sorry , Source card and destination card could not be same";
		Sleep(3000);
		Menu_Customer();
	}

	while (1) {

		cout << "\n\n Inventory : ";
		cin >> _Inventory;

		if (_Inventory == -1) {

			Check_Accounts(1);
			continue;
		}
		else break;
	}

	int i1, j1;

	int boolean1 = 0, boolean2 = 0;

	for (i1 = 0; i1 < All_Banks.size(); i1++) {

		for (j1 = 0; j1 < this->account[i1].size(); j1++) {

			if (this->account[i1][j1].GetShomareHesab() == Shomare_Karte_Mabdae) {
				boolean1 = 1;
				break;
			}

		}
		if (boolean1 == 1) {
			break;
		}
	}
	int x, y, z;

	for (x = 0; x < All_Customers.size(); x++) {


		for (y = 0; y < All_Customers[x].account.size(); y++) {

			for (z = 0; z < All_Customers[y].account[y].size(); z++) {

				if (All_Customers[x].account[y][z].GetShomareHesab() == Shomare_Karte_Maghsad) {
					boolean2 = 1;
					break;
				}

			}
			if (boolean2 == 1) {
				break;
			}
		}
		if (boolean2 == 1) {
			break;
		}


	}

	if (boolean1 == 1 && boolean2 == 1) {

		cout << ANSI_COLOR_RESET << "\n\n\n\t\t\t Checking Information ...";


		Sleep(2000);

		system("cls");

		cout << ANSI_COLOR_CYAN << "\n\n      ******************************************** Money Transfer Page ********************************************\n\n\n\n\n";
		cout << ANSI_COLOR_RED << " $$$$$$$$$$  Hi  " << this->Name;
		time_t k = time(NULL);
		cout << "\t\t\t\t\t\t\t      Exact Time :  " << asctime(localtime(&k)) << "\n\n";
		cout << "\n\n####### Enter -1 everywhere to Show your Cards Information";

		cout << ANSI_COLOR_RESET << "\n\n\n\t\t\t\t\t\tThe Card is belong to " << All_Customers[y].GetName() << " " << All_Customers[y].GetName() << "\n\n";

		cout << ANSI_COLOR_GREEN << "Enter 1 to continue or 2 to back ";
		int w;
		cin >> w;
		switch (w)
		{
		case 1:break;

		case 2: this->Menu_Customer();

		case -1:Check_Accounts(1);

		default:break;
		}


		int _CVV2;
		int _Password;

		while (1) {
			cout << "\n\n CVV2 : ";
			cin >> _CVV2;

			if (_CVV2 == -1) {
				Check_Accounts(1);
				continue;
			}
			break;
		}

		while (1) {
			cout << "\n\n Password : ";
			cin >> _Password;
			if (_Password == -1) {
				Check_Accounts(1);
				continue;
			}
			break;
		}


		if (this->account[i1][j1].Get_Cvv2() == _CVV2 && this->account[i1][j1].Get_SecondPassword() == _Password) {


			if (_Inventory > account[i1][j1].Get_Inventory()) {
				cout << ANSI_COLOR_RED << "\n\n\n\t\t\t Sorry , Inventory is not enough :))";
				Sleep(3000);
				Menu_Customer();
			}

			else {
				cout << ANSI_COLOR_RESET << "\n\n\n\n\t\t\t\tCongratulation ! Transfer Completed Successfully\n\n";

				this->account[i1][j1].Get_Inventory() -= _Inventory;

				All_Customers[x].account[y][z].Get_Inventory() += _Inventory;

				Sleep(5000);

				this->Menu_Customer();
			}

		}
		else {
			cout << ANSI_COLOR_RED << "\n\n\t\t\t\tWrong Information";
			Sleep(2000);
			Menu_Customer();
		}
	}
	else if (boolean1 != 1) {
		cout << ANSI_COLOR_RED << "\n\n\t\t\t\tYou Have not Account with this identities";
		Sleep(2000);
		Menu_Customer();
	}
	else if (boolean2 != 1) {
		cout << ANSI_COLOR_RED << "\n\n\t\t\t\t  Wrong Account Number";
		Sleep(2000);
		Menu_Customer();
	}





}

void Customers::Resize_All(int NewSize) {


	for (int i = 0; i < All_Customers.size(); i++) {


		All_Customers[i].Resize_Accounts_va_Debts(NewSize);


	}

}

void Customers::Resize_Accounts_va_Debts(int NewSize) {


	Debt.resize(NewSize);

	account.resize(NewSize);


}

void Customers::Read_Form_File() {



	int a;

	ifstream file;

	file.open("Customers.txt", ios::in);

	if (!(file.good())) {
		Customers::Write_on_Files();
		return;
	}

	boost::archive::text_iarchive Read_From_File(file);
	for (a = 0; file.good(); a++) {

		All_Customers.resize(All_Customers.size() + 1);

		Read_From_File >> All_Customers[a];
	}


	file.close();




}

void Customers::Write_on_Files() {


	ofstream file;

	file.open("Customers.txt", ios::out);

	boost::archive::text_oarchive os(file);

	for (int i = 0; i < All_Customers.size(); i++) {

		os << All_Customers[i];

	}

	file.close();

}

void Customers::Delete_Account(int i, int j) {

	account[i].erase(account[i].begin() + j);



}

void Customers::Calculate_SoodeHesabvaVam() {


	int i, j;
	int x = 0;
	for (i = 0; i < account.size(); i++) {

		for (j = 0; j < account[i].size(); j++) {

			if (account[i][j].Get_Answer_of_BankManager() == 1) {
				account[i][j].Calculate_Inventory();
				x = 1;
			}

			if (Debt[i].Get_Answer_of_Apply_Loan() == 1) {
				account[i][j].Get_Inventory() -= Debt[i].Calculate_Loans_Ghests();
				x = 1;

			}
		}
	}
	if (x == 1) {
		Customers::Write_on_Files();
	}


}

