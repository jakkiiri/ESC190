API_KEY = "xfCxmGkTpQHv1r4I7dBz"
from notopenai import NotOpenAI 
import json 
# Input the API key obtained for the lab  
CLIENT = NotOpenAI(api_key=API_KEY) 
def get_response(prompt): 
    chat_completion = CLIENT.chat.completions.create(
        messages=[ 
            { 
            "role": "user", 
            "content": prompt, 
            } 
        ], 
        model="gpt-3.5-turbo",
    )
    response_str = chat_completion.choices[0].message.content 
    return response_str
def check_result(generated_code, test_cases):
    for test_case in test_cases:
        input_val = test_case["intput"]
        expected_output = test_case["expected_output"]
        result = factorial(input_val)
        print(f"Input: {input_val}, Expected Output: {expected_output}, Result: {result}, Match: {result == expected_output}")
    return True

test_cases = [{"intput": 3, "expected_output": 6}, {"intput": 4, "expected_output": 24}]
generated_code = get_response("Generate a Python function that outputs the factorial of the input n.  The header of the function should be def factorial(n):.  Do not generate any test cases, only the function code.")
exec(generated_code)
check_result(generated_code, test_cases)

# Question 5
s = '''Date,Character,Age,HeightCm,AppleCount,MoodRating 
2025-01-15,Snow White,14,157.5,1,8.5 
Doc,200,91.4,3,7.2 
2025-01-16,Grumpy,199,89.0,0,3.4 
2025-01-16,202,94.0,2,9.7 
2025-01-17,Sleepy,202,90.2,1,6.3 
Bashful,198,88.5,1,5.8 
2025-01-18,Sneezy,197,92.3,2,7.4 
2025-01-18,Dopey,195,87.1,4,8.9 
2025-01-19,,42,175.6,0,2.1 
Prince,25,185.3,2,9.5 
2025-01-20,Huntsman,38,178.4,1,6.7 
2025-01-20,250,92.0,3,7.3 
2025-01-21,Forest Animals,5,30.5,4,9.2'''

def check_result_1(generated_code, test_cases):
    # Execute the generated code in a separate local scope
    local_scope = {}
    try:
        exec(generated_code, globals(), local_scope)
    except Exception as e:
        print(f"Error while executing generated code: {e}")
        return False

    if 'parse_csv' not in local_scope:
        print("Generated code did not define a 'parse_csv' function.")
        return False

    parse_csv = local_scope['parse_csv']
    for desc, csv_input, expected in test_cases:
        result = parse_csv(csv_input)
        print(f"Test: {desc}")
        print("Result:")
        print(result)
        print("Expected:")
        print(expected)
        print("Match:", result == expected, "\n")
    return True

expected_output = {
    1: {'Date': '2025-01-15', 'Character': 'Snow White', 'Age': '14', 'HeightCm': '157.5', 'AppleCount': '1', 'MoodRating': '8.5'},
    2: {'Date': '2025-01-15', 'Character': 'Doc', 'Age': '200', 'HeightCm': '91.4', 'AppleCount': '3', 'MoodRating': '7.2'},
    3: {'Date': '2025-01-16', 'Character': 'Grumpy', 'Age': '199', 'HeightCm': '89.0', 'AppleCount': '0', 'MoodRating': '3.4'},
    4: {'Date': '2025-01-16', 'Character': 'Grumpy', 'Age': '202', 'HeightCm': '94.0', 'AppleCount': '2', 'MoodRating': '9.7'},
    5: {'Date': '2025-01-17', 'Character': 'Sleepy', 'Age': '202', 'HeightCm': '90.2', 'AppleCount': '1', 'MoodRating': '6.3'},
    6: {'Date': '2025-01-17', 'Character': 'Bashful', 'Age': '198', 'HeightCm': '88.5', 'AppleCount': '1', 'MoodRating': '5.8'},
    7: {'Date': '2025-01-18', 'Character': 'Sneezy', 'Age': '197', 'HeightCm': '92.3', 'AppleCount': '2', 'MoodRating': '7.4'},
    8: {'Date': '2025-01-18', 'Character': 'Dopey', 'Age': '195', 'HeightCm': '87.1', 'AppleCount': '4', 'MoodRating': '8.9'},
    9: {'Date': '2025-01-19', 'Character': 'Dopey', 'Age': '42', 'HeightCm': '175.6', 'AppleCount': '0', 'MoodRating': '2.1'},
    10: {'Date': '2025-01-19', 'Character': 'Prince', 'Age': '25', 'HeightCm': '185.3', 'AppleCount': '2', 'MoodRating': '9.5'},
    11: {'Date': '2025-01-20', 'Character': 'Huntsman', 'Age': '38', 'HeightCm': '178.4', 'AppleCount': '1', 'MoodRating': '6.7'},
    12: {'Date': '2025-01-20', 'Character': 'Huntsman', 'Age': '250', 'HeightCm': '92.0', 'AppleCount': '3', 'MoodRating': '7.3'},
    13: {'Date': '2025-01-21', 'Character': 'Forest Animals', 'Age': '5', 'HeightCm': '30.5', 'AppleCount': '4', 'MoodRating': '9.2'},
}

test_cases = [
    ("CSV Parsing Test", s, expected_output)
]

prompt = (
    "Write a Python function called parse_csv(s) that takes a CSV string with headers "
    "'Date,Character,Age,HeightCm,AppleCount,MoodRating'. Some rows might be missing a Date or "
    "a Character value, and some rows may have missing fields (i.e., fewer columns than the header line). "
    "For missing Date or Character, use the last valid value from the previous row. For rows with missing "
    "fields, pad the missing entries with empty strings so that every row has the same number of columns as "
    "the header row. The function should return a dictionary of dictionaries where each key is the row number "
    "(starting at 1) and the value is a dictionary mapping header names to string values. "
    "Output only the raw Python code, with no markdown formatting, code fences, or additional text."
)

generated_code = get_response(prompt)
print("Generated Code:\n", generated_code)

check_result_1(generated_code, test_cases)