#pragma once

#include <iostream>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/string.hpp>









class Loan {

	friend class boost::serialization::access;

private:

	int Amount;
	int Num_Ghests;
	int First_Dimension;
	int Second_Dimension;
	int Answer_of_Apply_Loan;
	int Time_Apply_Loan;

	template<class Archive>

	void serialize(Archive& ar, const unsigned int version) {

		ar& Amount;
		ar& Num_Ghests;
		ar& First_Dimension;
		ar& Second_Dimension;
		ar& Answer_of_Apply_Loan;

		ar& Time_Apply_Loan;

	}

public:

	Loan();

	void Set_All_From_User(int _Amount, int _num_Ghests, int _First_Dimension, int _Second_Dimension);

	void Set_Answer_of_Apply_Loan(int _Answer_of_Apply_Loan);

	int Get_Amount() {
		return Amount;
	}
	int Get_NumGhests() {
		return Num_Ghests;
	}
	int Get_Answer_of_Apply_Loan() {
		return Answer_of_Apply_Loan;
	}

	void Set_Time_Apply_Loan() {

		time_t now = time(NULL);

		Time_Apply_Loan = now;
	}
	int Get_Time_Apply_Loan() {

		return Time_Apply_Loan;
	}

	int Calculate_Loans_Ghests() {

		time_t now = time(NULL);
		int x = now - Time_Apply_Loan;

		time_t time_now = time(NULL);

		int y = time_now - this->Time_Apply_Loan;

		y /= 3600 * 24 * 30;


		this->Time_Apply_Loan += (y * 3600 * 24 * 30);

		return (y * Amount) / Num_Ghests;



	}

};



