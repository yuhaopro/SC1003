_userinput = int(input("Please enter pattern width: "))
for i in range(_userinput):
    for j in range(i + 1):
        print("*", end = "")
    print("\n")
for p in range(_userinput - 1, 0, -1):
    for q in range(p):
        print("*", end = "")
    print("\n")