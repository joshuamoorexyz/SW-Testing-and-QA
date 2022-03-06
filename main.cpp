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


int obese=30;


//functions for program

bool getinput(){
cout<<"\nInput height in feet and inches";
cout<<"\nHeight:";
cin>>height;


//check to see if input is in beilivable range for height
//
if(height>1000.00){

cout<<"Height input error,exiting ..";
return false;
}


cout<<"Input weight in lbs";
cout<<"\nlbs:";
cin>>lbs;


//check to see if input is in beilivable range for weight
//
if(weight>1000.00){

cout<<"weight input error,exiting ..";
return false;
}

return true;


	
}

bool calculateBMI(){

//calculate to get BMI value

//1
//multiply weight to convert
weightconverted=lbs*weightconversion;

//2
//multiply height to convert
heightconverted=height*heightconversion;

//3
//square the answer from step 2
heightconverted=heightconverted*heightconverted;

//4
//divide the answer from step 1 by the answer from step 3
bmi=weightconverted/heightconverted;


return true;
}

bool classifyBMI(){

//classify BMI based on following:
//Underweight = <18.5; Normal weight = 18.5–24.9;  Overweight = 25–29.9; Obese = BMI of 30 or greater (s//ee formula linked in the Notes  & Resources section)
//bmi link:http://extoxnet.orst.edu/faqs/dietcancer/web2/twohowto.html

//underweight bmi
if(bmi<underweight){

cout<<"\nYour BMI indicates that your underweight";
cout<<endl;
return true;
}

//normal bmi
if(bmi>underweight && bmi<normalupper){

cout<<"\nYour BMI indicates that your normal";
cout<<endl;
return true;
}

//overweight
if(bmi>25 && bmi<29.9){

cout<<"\nYour BMI indicates that your overweight";
cout<<endl;
return true;
}

//obese
if(bmi >=30){

cout<<"\nYour BMI indicates that your obese";
cout<<endl;
return true;

}

else{
	return false;
}


}




int main(){

//program main loop
while(true){




if(getinput()==false){
	cout<<"Error getting input";
	return -1;
}

if(calculateBMI()==false){
	cout<<"Error calculating BMI";
	return -1;
}

if(classifyBMI()==false){
	cout<<"Error classifyingBMI";
	return -1;
}




//end of while loop
else return false;
}





	return 0;
}


