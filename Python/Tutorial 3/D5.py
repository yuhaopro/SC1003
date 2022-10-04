#Write a Python program, in the fewest number of lines possible, 
# which creates a list of all the square numbers: x2 (where 1<=x<=100) that are divisible by 3.

List1 = [x**2 for x in range(1, 101) if x % 3 == 0]
print(List1)
