#include "Loan.h"

using namespace std;

Loan::Loan() {

	Amount = 0;
	Num_Ghests = 0;
	First_Dimension = 0;
	Second_Dimension = 0;

	Answer_of_Apply_Loan = 3;

	Time_Apply_Loan = 0;

}

void Loan::Set_All_From_User(int _Amount, int _Num_Ghests, int _First_Dimension, int _Second_Dimension) {



	Amount = _Amount;
	Num_Ghests = _Num_Ghests;
	First_Dimension = _First_Dimension;
	Second_Dimension = _Second_Dimension;

	Time_Apply_Loan = 0;

}

void Loan::Set_Answer_of_Apply_Loan(int _Answer_of_Apply_Loan) {

	Answer_of_Apply_Loan = _Answer_of_Apply_Loan;

}
