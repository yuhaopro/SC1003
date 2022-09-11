# Discussion 1
# Based on the reverser() function that we already know, 
# develop a function called reverseAndRepeat(a_str, num) that reverses the a_str string and repeats each character in a_str for num times. 

# myStr = “ABC”
# str1 = reverseAndRepeat(myStr, 2)
# str2 = reverseAndRepeat(myStr, 3)

# print(str1)	# CCBBAA
# print(str2)	# CCCBBBAAA


def reverseAndRepeat(myStr, number):
    if len(myStr) == 1:
        return myStr * number
    else:
        temp = reverseAndRepeat(myStr[1:], number) + myStr[0] * number
        return temp

print(reverseAndRepeat("Helo", 3))