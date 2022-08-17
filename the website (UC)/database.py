import sqlite3

conn = sqlite3.connect('database.db')
print("Opened database successfully!")

conn.execute("CREATE TABLE TTSRecords (id INTEGER PRIMARY KEY AUTOINCREMENT, text TEXT, audio TEXT)")
print("Table created successfully")
conn.close()