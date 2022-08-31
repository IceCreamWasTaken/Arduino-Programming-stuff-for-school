# Imports libraries neccessary for the website to operate with flask
from flask_cors import cross_origin # exposes all routes, origins and methods or Cross Origin Resource Sharing (CORS)
from flask import Flask, render_template, request
from main import text_to_speech # pulls a definition from main.py to be able to run TTS on a web server

app = Flask(__name__) # Just a passing argument of the Flask class. Basically it's a filler that gets replaced of 
# "the name of the application package".
# You pass the function as the __name__ is varied depending on what you call the .py file name (e.g. main.py and app.py)
from app import app 
# Quickstart. First app is the name of the package and the second app is the imported object from the same package

@app.route('/', methods=['POST', 'GET']) # maps the specific URL managing the logic for that URL. 
# POST and GET are both python requests usually when HTML interacts with python implementation. GET is request data while
# POST is submit data to be processed to the server in which is what Flask sets up.
@cross_origin() # resource sharing
def thewebsite(): # creates a definition 
    if request.method == 'POST': # If the button was clicked, sends a POST request
        text = request.form['speech'] # Turns the text into a file that can be readable via a TTS API
        gender = request.form['voices'] # Based off from the user input, the voice will be based off from what gender was
        # selected
        text_to_speech(text, gender) # message and who spoke it
        return render_template('frontend.html') # generates an output (the text that gets played)  
    else:
        return render_template('frontend.html') # generates an output (the text that gets played)

# Flask stuff, sets up the server and connect it to a port and generates a link (a localhost) to view
if __name__ == "__main__":
    app.run(port=5000, debug=True)