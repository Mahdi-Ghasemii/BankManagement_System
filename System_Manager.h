#pragma once

#include "Bank Manager.h"

class System_Manager :public BankManagers
{

public:


	void Menu_BankManager();

	void AddBankManager();

	void AddCustomer();

	void AddBank();

	void Check_All_Banks();

	void Show_All_Customers();

	void Show_All_BankManagers();
};

