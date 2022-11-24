from flask import Flask, request,redirect

app = Flask('IntelliGF')

# middleware included in > middleware.py
# use middleware to authenticate each request first

curr_material = None

@app.route('/', methods=['GET', 'POST'])
def hello():
    return "Deployed on Heroku"

@app.route('/edit', methods = ['POST'])
def edit_material(material):
    global curr_material
    curr_material = material
    return redirect("/")

@app.route('/material', methods=['GET'])
def get_material():
    return curr_material


    