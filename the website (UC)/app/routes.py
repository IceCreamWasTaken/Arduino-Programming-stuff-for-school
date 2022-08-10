from flask import Flask, redirect, url_for, request, render_template, flash
import requests, string, random # YOU MUST INSTALL THE REQUESTS MODULE VIA PIP INSTALL
import sqlite3 as sql
import pathlib
import sys
app = Flask(__name__)
from app import app

@app.route('/')
def default():
    return render_template('index.html')

@app.route('/index')
def index():
    return render_template('index.html')

@app.route('/tts/create', methods = ['POST', 'GET'])
def create():
    if request.method == 'POST':
        user = request.form['nm']
        url = "https://text-to-speech14.p.rapidapi.com/api/tts"

        payload = "tech=deep&text=hello%20world.&language=en"
        headers = {
            "content-type": "application/x-www-form-urlencoded",
            "X-RapidAPI-Key": "01ad157ec2mshc9e9740c98d2789p11da3cjsnde11de23bce0",
            "X-RapidAPI-Host": "text-to-speech14.p.rapidapi.com"
        }
        try:
            response = requests.request("POST", url, data=payload, headers=headers)
            if response.status.code == 200:
                rand = get_random_string(5)
                try:
                    with sql.connect("database.db") as con:
                        cur = con.cursor()
                        cur.execute("INSERT INTO TTSRecords (text,audio) VALUES (?,?)",(user,rand,))
                        con.commit()
                        print("Record successfully added")
                except:
                    con.rollback()
                    print(sys.exc_info()[0])
                wav_file = open(str(pathlib.Path(__file__).parent)+"/static"+rand+"wav", "wb")
                wav_file.write(response.content)
                return render_template("index.html")
            else:
                return response.status_code+" Error"
        except requests.exceptions.ConnectionError as errc:
            return str(errc)

@app.route('/tts/list')
def list():
    con = sql.connect("database.db")
    con.row_factory = sql.Row

    cur = con.cursor()
    cur.execute("select * from TTSRecords")

    rows = cur.fetchall()
    if len(rows) > 0:
        return render_template("index.html",rows = rows)
    else:
        return "No Entries Found!"

@app.route('/tts/<ID>')
def openfile(ID):
    print(ID)
    con = sql.connect("database.db")
    con.row_factory = sql.Row
    
    cur = con.cursor()
    cur.execute("select * from TTSRecords where id=?",(ID,))
    lst = cur.fetchall()
    return render_template("audio.html",name=lst[0]['audio'])

def get_random_string(length):
    letters = string.ascii_lowercase
    result_str = ''.join(random.choice(letters) for i in range(length))
    return result_str

if __name__ == '__main__':
    app.run(debug = True)
