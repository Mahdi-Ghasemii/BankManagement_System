#pragma once

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN     "\x1b[32m"
#define ANSI_COLOR_YELLOW     "\x1b[33m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_MAGNETA     "\x1b[35m"
#define ANSI_COLOR_CYAN     "\x1b[36m"
#define ANSI_COLOR_RESET     "\x1b[0m"


#include <iostream>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/string.hpp>

using namespace std;

class Date {


	friend class boost::serialization::access;

private:

	int Year;
	int Month;
	int Day;

	template<class Archive>

	void serialize(Archive& ar, const unsigned int version) {

		ar& Year;
		ar& Month;
		ar& Day;

	}

public:

	Date() {
		Year = 0;
		Month = 0;
		Day = 0;
	}

	Date(int _Year, int _Month, int _Day) {
		Year = _Year;
		Month = _Month;
		Day = _Day;
	}

	void SetAll(int _Year, int _Month, int _Day) {
		Year = _Year;
		Month = _Month;
		Day = _Day;
	}

	void Set_All_From_User() {

		cout << "\n\n Birth Year : ";
		cin >> this->Year;

		cout << "\n\n Birth Month (int) : ";
		cin >> this->Month;

		cout << "\n\n Birth Day (int) : ";
		cin >> this->Day;


	}

	void PrintAll() {

		cout << this->Year << "/" << this->Month << "/" << this->Day;
	}

};
