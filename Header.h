#pragma once
#include "Customers.h"
//#include "Banks.h"
#include <vector>
#include "System_Manager.h"


extern std::vector<Customers> All_Customers;

extern std::vector<BankManagers> All_BankManagers;

extern std::vector<Banks> All_Banks;

extern std::vector<System_Manager> SystemManagers;

//****************************



//**************************

void Main_Menu();



void log_in_Menu(void);

bool Check_Tedade_Argham(int adad, int Max, int Min);


