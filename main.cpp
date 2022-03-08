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


using namespace std;

class BMI{


private:



public:
//needed variables
float height;
float lbs;
float bmi;
float finalbmi;

//bmi vals
float weightconversion=0.45;
float heightconversion=0.025;

float weight,weightconverted,heightconverted;


//classification vals
float normalupper=24.9;
float underweight=18.5;
float overweightupper=29.9;


int obese=30;

//functions for program

//get the values
float getinput(){
float input;
std::cin>>input;
return input;
}


float calculateBMI(BMI O){

//calculate to get BMI value

//1
//multiply weight to convert
O.weightconverted=lbs*O.weightconversion;

//2
//multiply height to convert
O.heightconverted=O.height*O.heightconversion;

//3
//square the answer from step 2
O.heightconverted=O.heightconverted*O.heightconverted;

//4
//divide the answer from step 1 by the answer from step 3
O.bmi=O.weightconverted/O.heightconverted;


return O.bmi;
}

string classifyBMI(BMI b){

//classify BMI based on following:
//Underweight = <18.5; Normal weight = 18.5–24.9;  Overweight = 25–29.9; Obese = BMI of 30 or greater (s//ee formula linked in the Notes  & Resources section)
//bmi link:http://extoxnet.orst.edu/faqs/dietcancer/web2/twohowto.html

//underweight bmi
if(b.bmi<b.underweight){

string bmi="underweight";
return bmi;
}

//normal bmi
if(b.bmi>b.underweight && b.bmi<b.normalupper){
string bmi="normal";

return bmi;
}

//overweight
if(bmi>25 && bmi<29.9){
string bmi="overweight";

return bmi;

}

//obese
if(bmi >=30){
string bmi="obese";

return bmi;



}


}



};


int main(){

//object for class
BMI object;


//program main loop
while(true){

cout<<"\nInput height in feet and inches";
cout<<"\nHeight: >>";

//get height
object.height=object.getinput();
if(object.height<=0.0){
	cout<<"Error getting input";
	return -1;
}
//get weight
cout<<"Input weight in lbs";
cout<<"\nlbs: >>";
object.lbs=object.getinput();
if(object.lbs<=0.0){
	cout<<"Error getting input";
	return -1;
}

float bmi;
//calculate BMI
bmi=object.calculateBMI(object);
if(bmi<=0.0){
	cout<<"Error calculating BMI";
	return -1;
}


//classify BMI

string finalbmiclassification=object.classifyBMI(object);

if(finalbmiclassification=="\0"){
	cout<<"Error classifying BMI";
	return -1;
}


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
return false;
}

	return 0;
}


