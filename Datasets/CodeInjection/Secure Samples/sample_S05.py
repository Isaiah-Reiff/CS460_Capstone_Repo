from flask import Flask, request, jsonify

app = Flask(__name__)

# Define a small whitelist of allowed "commands"
# (Replace with whatever functionality your application actually needs)
ALLOWED_ACTIONS = {
    "ping": lambda: "pong",
    "hello": lambda: "world",
    "add": lambda x, y: x + y
}

@app.route("/eval", methods=["POST"])
def run():
    action = request.form.get("action", "")
    params = request.form.get("params", "")

    if action not in ALLOWED_ACTIONS:
        return jsonify({"error": "Invalid or unauthorized action"}), 400

    try:
        # Parse params safely (expecting JSON list or simple string)
        import json
        parsed = json.loads(params) if params else []

        # Ensure params is a list
        if not isinstance(parsed, list):
            return jsonify({"error": "Parameters must be a list"}), 400

        # Execute only the whitelisted function
        result = ALLOWED_ACTIONS[action](*parsed)

        return jsonify({"result": result})

    except Exception as ex:
        return jsonify({"error": "Execution failed", "details": str(ex)}), 400


if __name__ == "__main__":
    app.run()