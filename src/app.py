#classification vals
from sre_constants import FAILURE, SUCCESS
from functions import *
from flask import Flask

#app = Flask(__name__)

normalupper = 24.9
underweight = 18.5
overweightupper = 29.9
obese = 30.0



#@app.route("/")
#def hello():




print("Input height in feet and inches")
    #get height
height=float(input())
if (height <= 0.0):
	print("Error getting input")
	exit(FAILURE)
	#get weight
print("Input weight in lbs")
lbs=float(input())
if (lbs <= 0.0):
	print("Error getting input")
	exit(FAILURE)
		
bmi=0.0



	#calculate BMI
bmi = calculateBMI(height, lbs)
if (bmi <= 0.0):
	print("Error calculating BMI")
	exit(FAILURE)
		


	#classify BMI

finalbmiclassification = classifyBMI(bmi)

if (finalbmiclassification == "\0"):
		print("Error classifying BMI")
elif (finalbmiclassification == "underweight"): 
	    print("\nYour BMI indicates that your underweight\n")
elif (finalbmiclassification == "normal"): 
	    print("\nYour BMI indicates that your normal\n")	
elif (finalbmiclassification == "overweight"):
	    print("\nYour BMI indicates that your overweight")
elif (finalbmiclassification == "obese"):
	    print("\nYour BMI indicates that your obese")
else:
    print("Could not calculate BMI")

		
		
	
	




