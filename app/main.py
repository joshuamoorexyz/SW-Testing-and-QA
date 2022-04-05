#classification vals
from sre_constants import FAILURE, SUCCESS
from functions import *
from flask import Flask, render_template, request
import os 

port = int(os.environ.get("PORT", 5000))

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
	                        bmi=bmi,bmiclassification=bmiclassification)




if __name__ == "__main__":
        app.run(host='0.0.0.0', port=port, debug=True)





		
		
	
	




