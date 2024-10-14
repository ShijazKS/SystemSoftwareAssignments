
fruit_dict = {1: "Apple", 2: "Banana", 3: "Orange", 4: "Peach"}

def get_fruit_by_key():
    try:

        key_input = input("Enter a key (integer): ")
        
        if not key_input.isdigit():
            raise ValueError("The key must be an integer.")

        key = int(key_input)

        if key in fruit_dict:
            print(f"The value for key {key} is: {fruit_dict[key]}")
        else:
            raise KeyError(f"Key {key} does not exist in the dictionary.")

    except ValueError as ve:
        print(f"ValueError: {ve}")
    
    except KeyError as ke:
        print(f"KeyError: {ke}")
    
    finally:
        print("Current dictionary:", fruit_dict)

get_fruit_by_key()
