from flask import Flask, request

app = Flask('IntelliGF')

# middleware included in > middleware.py
# use middleware to authenticate each request first

@app.route('/', methods=['GET', 'POST'])
def hello():
    return "Deployed on Heroku"