from flask import Flask, request,redirect

app = Flask('IntelliGF')

# middleware included in > middleware.py
# use middleware to authenticate each request first

curr_material = 'metal'

@app.route('/', methods=['GET', 'POST'])
def hello():
    global curr_material
    return curr_material

@app.route('/edit/<material>', methods = ['GET','POST'])
def edit_material(material):
    global curr_material
    curr_material = material
    return f"material changed to: {curr_material}"

@app.route('/material', methods=['GET'])
def get_material():
    global curr_material
    return curr_material