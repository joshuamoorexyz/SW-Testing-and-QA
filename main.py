#classification vals
from sre_constants import FAILURE, SUCCESS





normalupper = 24.9
underweight = 18.5
overweightupper = 29.9
obese = 30.0




#functions for program

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



	












# TEST(BMITest, Greaterthan0Lessthan100) {
# 	float bmi = calculateBMI(56, 119);

# 	EXPECT_TRUE(bmi > 0.0 && bmi < 100.0);


# }

# TEST(BMITest, classifyBMIUnderweight) {

# 	string classify = classifyBMI(18.4);

# 	EXPECT_EQ(classify, "underweight");
# }

# TEST(BMITest, classifyBMINoraml) {
# 	string classify = classifyBMI(18.6);

# 	EXPECT_EQ(classify, "normal");

# }
# TEST(BMITest, classifyBMIOverweight) {
# 	string classify = classifyBMI(25.1);

# 	EXPECT_EQ(classify, "overweight");

# }
# TEST(BMITest, classifyBMIObese) {
# 	string classify = classifyBMI(31.0);

# 	EXPECT_EQ(classify, "obese");

# }



#needed variables

#setup testing
#	testing::InitGoogleTest(&argc, argv);
#program main loop


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

		
		
	#end of while loop
		#return RUN_ALL_TESTS();
		
		#return false;
	
	




