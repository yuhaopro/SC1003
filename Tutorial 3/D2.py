#Password Strength of at least 8 characters long
#At least one Capital letter
#from ast import Pass


PASSWORD_LENGTH = 8
Password = input("Enter Password: ")

def SetPassword(password):
    if (len(password) >= PASSWORD_LENGTH):
        for character in password:
            if (ord(character) >= 65 and ord(character) <= 90):
                break
        else:
            print("Password needs at least one capitalized letter")
            return
        print("Password is valid")
    else:
        print("Password needs to be at least 8 characters long")

SetPassword(Password)