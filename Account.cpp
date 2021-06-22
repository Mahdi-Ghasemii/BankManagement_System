#pragma once

#include "Accounts.h"
#include <time.h>
#include "Header.h"


Accounts::Accounts() {
	Bank_ID = 0;
	Inventory = 1000000;
	Cvv2 = 0;
	Shomare_Hesab = 0;
	firstPassword = 0;
	SecondPassword = 0;
	account_Type = 0;
	Answer_of_BankManager = 0;
	Time_Create_Account = 0;
}


void Accounts::Make_Cvv2_Shomare(int id) {

	this->Cvv2 = 3264 + id;
	this->Shomare_Hesab = 5892101090621117 + id;
	int x;
	while (1) {
		cout << ANSI_COLOR_YELLOW << "\n  First Password : " << ANSI_COLOR_RESET;
		cin >> x;

		if (Check_Tedade_Argham(x, 4, 4) == true) {
			this->firstPassword = x;
			break;
		}

	}

	while (1) {
		cout << ANSI_COLOR_YELLOW << "\n  Second Password : " << ANSI_COLOR_RESET;
		cin >> x;

		if (Check_Tedade_Argham(x, 12, 6) == true) {
			this->SecondPassword = x;
			break;
		}

	}
}

void Accounts::Set_Account_Type() {


	cin >> account_Type;
}

void Accounts::Calculate_Inventory() {


	time_t time_now = time(NULL);

	int y = time_now - this->Time_Create_Account;

	if (y < 0) {
		return;
	}

	y /= 3600 * 24 * 30;

	int y2 = y;

	if (account_Type == 1) {
		y *= 10;
	}

	if (account_Type == 2) {
		y *= 30;
	}

	if (account_Type == 3) {
		y *= 50;
	}

	Inventory += (y * Inventory) / 100;

	this->Time_Create_Account += (y2 * 3600 * 24 * 30);

}


long long int Accounts::GetShomareHesab() {
	return Shomare_Hesab;
}

int Accounts::Get_Cvv2() {
	return Cvv2;
}
int Accounts::Get_SecondPassword() {
	return SecondPassword;
}

Date Accounts::Get_date() {
	return Foundation_Date;
}

int Accounts::Get_Account_Type() {
	return account_Type;
}

void Accounts::Set_Account_Type(int x) {

	this->account_Type = x;

}


void Accounts::Set_Answer_of_BankManager(int _Answer_of_BankManager) {

	Answer_of_BankManager = _Answer_of_BankManager;
}

int Accounts::Get_Answer_of_BankManager() {
	return Answer_of_BankManager;
}


int Accounts::Get_Time_Create_Account() {
	return Time_Create_Account;
}

void Accounts::Set_Time_Create_Account() {

	time_t _Time_Create_Account = time(NULL);
	Time_Create_Account = _Time_Create_Account;
}