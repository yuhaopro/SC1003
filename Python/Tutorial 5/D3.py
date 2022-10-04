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

def symmetricString2(a_str):
    if len(a_str) == 1:
        return a_str + a_str
    
    else:
        resultStr = a_str[0] symmetricString2(a_str[1:]) + a_str[0]
    
    return resultStr
        
    
