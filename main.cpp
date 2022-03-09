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

//include google test headers
#include<gtest/gtest.h>

using namespace std;






//needed variables
float height;
float lbs;
float bmi;


//bmi vals
float weightconversion=0.45;
float heightconversion=0.025;

float weight,weightconverted,heightconverted;


//classification vals
float normalupper=24.9;
float underweight=18.5;
float overweightupper=29.9;


int obese=30.0;




//functions for program

//get the values
float getinput(){
float input;
cin>>input;
return input;
}


float calculateBMI(){

//calculate to get BMI value

//1
//multiply weight to convert
weightconverted=lbs*weightconversion;
cout<<"\n Weight Converted:"<<weightconverted;
//2
//multiply height to convert
heightconverted=height*heightconversion;
cout<<"\n height Converted:"<<heightconverted;

//3
//square the answer from step 2
heightconverted=heightconverted*heightconverted;
cout<<"\n height Converted after square:"<<heightconverted;

//4
//divide the answer from step 1 by the answer from step 3

bmi=weightconverted/heightconverted;
cout<<endl;
cout<<bmi;
cout<<endl;
return bmi;
}

string classifyBMI(){

//classify BMI based on following:
//Underweight = <18.5; Normal weight = 18.5–24.9;  Overweight = 25–29.9; Obese = BMI of 30 or greater (s//ee formula linked in the Notes  & Resources section)
//bmi link:http://extoxnet.orst.edu/faqs/dietcancer/web2/twohowto.html

//underweight bmi
if(bmi<underweight){

string bmi="underweight";
return bmi;
}

//normal bmi
if(bmi>underweight && bmi<normalupper){
string bmi="normal";

return bmi;
}

//overweight
if(bmi>25.0 && bmi<29.9){
string bmi="overweight";

return bmi;

}

//obese
if(bmi >=30.0){
string bmi="obese";

return bmi;



}


}






TEST(BMITest, InvalidInput){

ASSERT_EQ(1,1);

}
TEST(BMITest, ErrorInCalculation){




}

TEST(BMITest, ErrorinClassification){


}



int main(int argc,char **argv){


//setup testing
testing::InitGoogleTest(&argc, argv);





//program main loop
while(true){

cout<<"\nInput height in feet and inches";
cout<<"\nHeight: >>";

//get height
height=getinput();
if(height<=0.0){
	cout<<"Error getting input";
	return -1;
}
//get weight
cout<<"Input weight in lbs";
cout<<"\nlbs: >>";
lbs=getinput();
if(lbs<=0.0){
	cout<<"Error getting input";
	return -1;
}

float bmi;
//calculate BMI
bmi=calculateBMI();
if(bmi<=0.0){
	cout<<"Error calculating BMI";
	return -1;
}


//classify BMI

string finalbmiclassification=classifyBMI();

if(finalbmiclassification=="\0"){
	cout<<"Error classifying BMI";
	return -1;
}

cout<<bmi;
if(finalbmiclassification=="underweight"){	
cout<<"\nYour BMI indicates that your underweight";
cout<<endl;
}
if(finalbmiclassification=="normal"){	
cout<<"\nYour BMI indicates that your normal";
cout<<endl;
}
if(finalbmiclassification=="overweight"){	
cout<<"\nYour BMI indicates that your overweight";
cout<<endl;
}
if(finalbmiclassification=="obese"){	
cout<<"\nYour BMI indicates that your obese";
cout<<endl;

}
//end of while loop
return RUN_ALL_TESTS();
return false;
}
	return 0;
	
}


