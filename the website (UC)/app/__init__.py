from flask import Flask
from flask_bootstrap import Bootstrap

app = Flask(__name__)

from app import routes
bootstreap = Bootstrap(app)