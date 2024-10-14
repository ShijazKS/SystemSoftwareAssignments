import re

email = "shijaz@gmail,com"\

class emailError(Exception):
    pass

def checkEmail(email):
    pattern =r'^[^@]+@[^@]+\.[A-Za-z]{2,}$'

    if not re.match(pattern, email):
        raise emailError("Invalid email format")
    
    return "Valid email!"


try:
    checkEmail(email)
except emailError as e:
    print(e)