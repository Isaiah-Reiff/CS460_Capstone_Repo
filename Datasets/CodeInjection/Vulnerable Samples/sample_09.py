from flask import Flask, request
app = Flask(__name__)

@app.route("/eval", methods=["POST"])
def run():
    user_code = request.form.get("code", "")
    compiled = compile(user_code, "<user>", "exec")
    exec(compiled)                                 
    return "done"
