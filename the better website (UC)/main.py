import pyttsx3

def text_to_speech(text, gender):
    """
    Function to convert text to speech
    :param text: text
    :param gender: gender
    :return: None
    """
    voice_dict = {'Male': 0, 'Female': 1}
    code = voice_dict[gender]

    engine = pyttsx3.init()

    # Setting up voice rate
    engine.setProperty('rate', 125)

    # Setting volume level between 0 the minimum an 1 the max
    engine.setProperty('volume', 0.85)

    # Change voices: 0 for male and 1 for female (there's only gender voices)
    voices = engine.getProperty('voices')
    engine.setProperty('voice', voices[code].id)

    engine.say(text)
    engine.runAndWait()

text = "Hello! This is a test of text to speech!"
gender = 'Male' # The voice assistant, remember 0 for male, 1 for female drawn from the import
text_to_speech(text, gender)



