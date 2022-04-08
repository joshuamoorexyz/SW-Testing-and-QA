#classification vals
from sre_constants import FAILURE, SUCCESS
from functions import *
from flask import Flask, render_template, request


app = Flask(__name__)

@app.route('/',methods=['GET', 'POST'])
def main():
    bmi=''
    bmiclassification=""
    if request.method == 'POST' and 'weight' in request.form:
        height = float(request.form.get('height'))
        weight = float(request.form.get('weight'))

        bmi = float(calculateBMI(height,weight))
        bmiclassification=classifyBMI(bmi)
    return render_template("index.html",
	                        bmi=round(bmi),bmiclassification=bmiclassification)





if __name__ == "__main__":
    app.run(debug=True)



		
		
	
	




