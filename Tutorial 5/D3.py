# Based on the reverser() function that we already know, 
# develop a function called symmetricString(a_str) 
# that  makes a symmetric string, in which a_str is its prefix.  

def reverser(myStr):
    if len(myStr) == 1:
        return myStr 
    else:
        temp = reverser(myStr[1:]) + myStr[0]
        return temp    

def symmetricString(myStr):
    return myStr + reverser(myStr)

print(symmetricString("Hello"))