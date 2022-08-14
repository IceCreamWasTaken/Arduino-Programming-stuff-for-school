To create a virtual environment to host a server:
1. cd textToSpeech - this is to find the directory
2. python3 -m venv venv - creates a virtual environment, the second venv is the name of the environment
3. venv\Scripts\activate - activates the virtual environment where you can download stuff like flask and cool things

However, a more quicker way to run flask is to:
1. cd textToSpeech (cd means current directory)
2. venv\Scripts\activate to activate the virtual environment 
3. then you can run the flask run function to get a localhost server only you can see


This stuff is for UC

In particular this is the Assessment 3 work task, about Text to speech yay!

5:26pm @ Wed 25th May - Google's online tts sucks so i'm sticking with the offline one.

5:46pm @ Wed 25th May - Decided to rethink how to work around with python, but instead found out combining HTML, CSS and Javascript, you will be able to create a website styled TTS application and ITS WITHOUT PYTHON YAY. Problem is you got to Javascript!'

5:52pm @ Wed 25th May - HTML, CSS, Python instead of javascript (Server!)
learn how to build a web server (majority of learning python)
Library of tts 
Priortise Server Management 
Start for the next few weeks on setting up a web server 
Python Server
HTML, CSS content
Flask-Mega stuff! First 14 Chapters  (https://blog.miguelgrinberg.com/post/the-flask-mega-tutorial-part-i-hello-world)
https://flask.palletsprojects.com/en/2.1.x/)

6:42pm - getting to it, pretty hard to do!

6:06pm @ Wed 1st June - Got a working server with html elements! 

Wed 8th June - Added paragraph tags and added some sweet sweet styles!
  - Also read the first 10 chapters, I don't think I'll be needing a login system but as I'm progressing if I do have time, I can create one for people to access their past content (text to speech inputs and download files again)

Wed 15th June - Revisited Chapter 2 and added a template to be used later in chapter 11 (making the server website look smick!)
- Also added a div header just there, dunno what to do might add something fancy when I have time for it. (it does nothing)
- Don't think I will be using Bootstrap but I did install it just incase. When I have extra time i'll see if I can make the website nice. Functionality first!
- Flagging Chapter 11 to come back to, I would like to make my website look nice with that bit of server management but I need to focus on the TTS aspect first as it's a high priority
- Skim read Chapter 12, probably going to flag this as I want to put a clock interface somehow on the website. But again probably not going to be using it
- Stopped at Chapter 13, would be interesting trying to use different languages for TTS!

Wed 22nd June - Revisted Chapter 12 and decided to add my own footer not with bootstrap haha goodbye bootstrap you suck!
- Haven't worked on Chapter 13 yet
- Added a shape on the footer

Wed 27th of July - Stopped using flask don't think I will have enough time to implement some of the cool stuff on it probably when I have extra time
- Subscribed to an API that runs with python and flask to bring TTS to a web server. :) 

Wed 3rd of August 
- Continued to integrate flask + python into a robust TTS, replanned it so that there's something functional
- Ended up integrating ajax and js too, will look ajax later (seems a jquery language or something)
- To do list is DON'T FORGET TO CODE COMMENT AND REFERENCE BECAUSE YES
- Actually fiddled around with bootstrap! Don't know if it will work until I start debugging wooooo!
- Started editing the html file and changing the wacks and boons.
- Encountered an issue with the stupid requests module. This was solved by pip installing requests via the virtual environment 
- Left at the Error 404 with a funny Not Found requested URL not found in server, will troubleshoot this once everything is done before code comments and user documentations are worked on.

Wed 10th of August 
- Worked on getting the html part done so you can see the website!
- https://rapidapi.com/hivoicy-vxmKOG2vl/api/text-to-speech14/ 
- https://rapidapi.com/blog/text-to-speech-python-flask/#the-html-template-code-blocks !!!
- Completed the index.html file, working on an audio.html for playability of the audio files

Sun 14th of August
- Was bored so I decided to finish off the audio.html file and the database.py
- I then run database.py in the virtual environment which then creates a database.db file (where all the audio files will be stored as a query, i did download the sqlite 3 extension ready to "probe" the database lol)
- Tried testing it out, seems that the website works fine, however I wasn't able to get an actual audio file working, installed nor played, think I did something wrong; will look into this on Wed's class, will seek help from teacher for solutions, perhaps it's something to do with the API endpoints since I'm using a different one compared to the tutorial's (tutorial's api that I want doesn't exist) will look into.
- I need this working before I am able to code comment and create a presentation!!!!
