from app.main import app
import os 

port = int(os.environ.get("PORT", 5000))
if __name__ == "__main__":
        app.run(host='/', port=port, debug=True)
