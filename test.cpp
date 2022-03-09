#include "pch.h"

//Author: Joshua Moore
//NetId:jjm702
//Program Description: a command line app that prompts the user to enter the input height,weight,and returns BMI


/*Assignment details Objective

Apply test-driven development (TDD) to implement a set of software requirements. Write unit  tests to provide adequate coverage
of a code-base using your chosen unit testing framework and  test runner.

Scenario

You are to create an application that allows the user to select and run each function and receive  a correct response from the program.
 The new development manager requires that you code the  application using a test-driven development approach. We define a unit as a function
 or method  in a class with a single responsibility. The project should be developed and maintained using a

GitHub repository.

Requirements

Command Line Interface - Develop a command line app that prompts the user to enter the input  (although a GUI is not required, you can
create one if you want). For now, the app must have  the following functionality.

1. Body Mass Index - Input height in feet and inches. Input weight in pounds. Return  BMI value and category: Underweight = <18.5; Normal
weight = 18.5–24.9;  Overweight = 25–29.9; Obese = BMI of 30 or greater (see formula linked in the Notes  & Resources section).   */

#include<iostream>
#include<math.h>
#include<iomanip>
//include google test headers
#include<gtest/gtest.h>

using namespace std;

//classification vals
float normalupper = 24.9;
float underweight = 18.5;
float overweightupper = 29.9;


int obese = 30.0;




//functions for program




float calculateBMI(float x, float y) {
	float bmi;
	//calculate to get BMI value
	bmi = (y / pow(x, 2)) * 703;


	return bmi;
}

string classifyBMI(float x) {

	//classify BMI based on following:
	//Underweight = <18.5; Normal weight = 18.5–24.9;  Overweight = 25–29.9; Obese = BMI of 30 or greater (s//ee formula linked in the Notes  & Resources section)
	//bmi link:http://extoxnet.orst.edu/faqs/dietcancer/web2/twohowto.html

	cout << fixed << showpoint << setprecision(2);
	//underweight bmi
	if (x < underweight) {

		string bmi = "underweight";
		return bmi;
	}

	//normal bmi
	if (x > underweight && x < normalupper) {
		string bmi = "normal";

		return bmi;
	}

	//overweight
	if (x > 25.0 && x < 29.9) {
		string bmi = "overweight";

		return bmi;

	}

	//obese
	if (x >= 30.0) {
		string bmi = "obese";

		return bmi;



	}


}









TEST(BMITest, Greaterthan0Lessthan100) {
	float bmi = calculateBMI(56, 119);

	EXPECT_TRUE(bmi > 0.0 && bmi < 100.0);


}

TEST(BMITest, classifyBMIUnderweight) {

	string classify = classifyBMI(18.4);

	EXPECT_EQ(classify, "underweight");
}

TEST(BMITest, classifyBMINoraml) {
	string classify = classifyBMI(18.6);

	EXPECT_EQ(classify, "normal");

}
TEST(BMITest, classifyBMIOverweight) {
	string classify = classifyBMI(25.1);

	EXPECT_EQ(classify, "overweight");

}
TEST(BMITest, classifyBMIObese) {
	string classify = classifyBMI(31.0);

	EXPECT_EQ(classify, "obese");

}


int main(int argc, char** argv) {
	//needed variables
	float height;
	float lbs;
	float bmi;

	//setup testing
	testing::InitGoogleTest(&argc, argv);





	//program main loop
	while (true) {

		cout << "\nInput height in feet and inches";
		cout << "\nHeight: >>";

		//get height
		cin >> height;
		if (height <= 0.0) {
			cout << "Error getting input";
			return -1;
		}
		//get weight
		cout << "Input weight in lbs";
		cout << "\nlbs: >>";
		cin >> lbs;
		if (lbs <= 0.0) {
			cout << "Error getting input";
			return -1;
		}

		float bmi;
		//calculate BMI
		bmi = calculateBMI(height, lbs);
		if (bmi <= 0.0) {
			cout << "Error calculating BMI";
			return -1;
		}


		//classify BMI

		string finalbmiclassification = classifyBMI(bmi);

		if (finalbmiclassification == "\0") {
			cout << "Error classifying BMI";
			return -1;
		}


		if (finalbmiclassification == "underweight") {
			cout << "\nYour BMI indicates that your underweight";
			cout << endl;
		}
		if (finalbmiclassification == "normal") {
			cout << "\nYour BMI indicates that your normal";
			cout << endl;
		}
		if (finalbmiclassification == "overweight") {
			cout << "\nYour BMI indicates that your overweight";
			cout << endl;
		}
		if (finalbmiclassification == "obese") {
			cout << "\nYour BMI indicates that your obese";
			cout << endl;

		}
		cout << system("pause");
		//end of while loop
		return RUN_ALL_TESTS();
		
		return false;
	}
	return 0;

}


