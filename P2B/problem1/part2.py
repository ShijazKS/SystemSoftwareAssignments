import re

num = '9745586781'

class lengthError(Exception):
    pass

def checkNumber(num):
    pattern = r'^[0-9]{10}$'

    if not re.match(pattern,num):
        if len(num)!=10:
            raise lengthError("Invalid phone format")
        else:
            raise ValueError('Non-number detect')
    else:
        print("correct")

try:
    checkNumber(num)
except lengthError as e:
    print(e)
except ValueError as e:
    print(e)
