# Based on the reverser() function that we already know, 
# develop a function called reverseAndOppositeCase(a_str) 
# that reverses the a_str string and changes each character to its opposite case.

# myStr = “AbCdE”
# str1 = reverseAndOppositeCase(myStr)

# print(str1)	# eDcBa

def reverseAndOppositeCase(myStr):
    if len(myStr) == 1:
        if (myStr.isupper()):
            return myStr.lower()
        else:
            return myStr.upper()
    else:
        if (myStr[0].isupper()):
            temp = reverseAndOppositeCase(myStr[1:]) + myStr[0].lower()
        else:
            temp = reverseAndOppositeCase(myStr[1:]) + myStr[0].upper()
        return temp

print(reverseAndOppositeCase("Helo"))