import pyttsx3
# imports a text-to-speech library in Python. There are several APIs that are able to take user generated text
# into an audio file that is playable such as pyttsx3 (the one that's being used), google text-to-speech (able to
# translate a variety of languages, also known as gTTS) and Amazon Polly all of which are three different APIs 
# however, they do the same function. The reason why I chose pyttsx is because of real world applications being able to 
# work offline and is compatiable for those who still use python 2.

def text_to_speech(text, gender): # Creates a definition of what's to be included in the program. 
    """
    Function to convert text to speech
    :param text: text
    :param gender: gender
    :return: None
    """
    voice_dict = {'Male': 0, 'Female': 1} # What voices will be available to use.
    code = voice_dict[gender] # Defines the number is based on the gender of what the TTS program will read on.

    engine = pyttsx3.init() # Sets the engine of the TTS API. Initialises it to flask server. 

    # Setting up voice rate. How many words will the API speaks per minute. The higher the number, the faster it
    # gets. The lower the number, the slower it gets. 
    engine.setProperty('rate', 125)

    # Setting volume level between 0 the minimum an 1 the max. Higher the decimal, the louder it is. 
    engine.setProperty('volume', 0.85) # Fixed volume level (stays as 0.85 until changed via the code itself)

    # Change voices: 0 for male and 1 for female (there's only gender voices), basically pulls 
    # the voices needed in TTS library to use for the website.
    voices = engine.getProperty('voices')
    engine.setProperty('voice', voices[code].id)

    # When setting up flask these two commands will run to test if it works. These will run in command prompt/terminal
    engine.say(text) 
    engine.runAndWait()

text = "Hello! This is a test of text to speech! Thanks." # the text that's being played when running flask server
gender = 'Male' # The voice assistant, remember 0 for male, 1 for female drawn from the import
text_to_speech(text, gender) # runs a script from a definition from above. 



