
#functions for program

normalupper = 24.9
underweight = 18.5
overweightupper = 29.9
obese = 30.0



def calculateBMI(x, y):
	#calculate to get BMI value
	bmi = (y / pow(x, 2)) * 703
	return bmi


def classifyBMI(x):
#classify BMI based on following:
#Underweight = <18.5; Normal weight = 18.5–24.9;  Overweight = 25–29.9; Obese = BMI of 30 or greater (#ee formula linked in the Notes  & Resources section)
#bmi link:http#extoxnet.orst.edu/faqs/dietcancer/web2/twohowto.html
#underweight bmi
	if (x < underweight): 
		bmi = "underweight"
		return bmi
	

#normal bmi
	if (x > underweight) and (x < normalupper):
		bmi = "normal"
		return bmi
	

#overweight
	if (x > 25.0)and (x < 29.9):
		bmi = "overweight"
		return bmi

	

#obese
	if (x >= 30.0):
		bmi = "obese"
		return bmi
