#Allow the user to input the score a student with id and groupname into the database.
#Database contains a list of Dictionaries, where each group is a dictionary, and the id is the key.

from re import T

_INT = 1
_FLOAT = 2

#D1 Question
def InputRecord(dataBase, group, id, score):
    #group is a str
    #id is a int
    #score is a float
    dataBase[group + ":" + str(id)] = score

#D2 Question
def query(dataBase, group, id):
    try:
        return dataBase[group + ":" + str(id)]
    except:
        print("No such group or id")


#D3 Question
def listGrades(dataBase, group):
    _templist = []
    for i in range(1, len(dataBase) + 1):
        _templist.append(query(dataBase, group, i))
    return _templist

#D4 Question
#max grade
def maxGrade(dataBase, group):
    list1 = listGrades(dataBase, group)
    return max(list1)

def inputValidation(inputstring, typevalue):
    try:
        if (typevalue == _INT):
            return int(inputstring)
        elif typevalue == _FLOAT:
            return float(inputstring)
    except:
        print("Enter a valid number!")

#D5 Question
#Interface
database1 = {}
_OptionList = ["input record", "query a student", "list grades in a group", "get max grade in a group", "list all group names", "exit"]
TryAgain = True
while TryAgain:
    for i in range(len(_OptionList)):
        print(f"{i + 1}: {_OptionList[i]}")
    _inputvalue = input("option: ")
    match _inputvalue:
        case '1':
            _Group = input("Please Input the Group Name: ")
            _Id = inputValidation(input("Please Input the ID: "), _INT)
            _Score = inputValidation(input("Please Input the Score: "), _FLOAT)
            InputRecord(database1, _Group, _Id, _Score)
            print("Successful!")
        case '2':
            _Group = input("Please Input the Group Name: ")
            _Id = inputValidation(input("Please Input the ID: "), _INT)
            print(query(database1, _Group, _Id))
        case '3':
            _Group = input("Please Input the Group Name: ")
            print(listGrades(database1, _Group))
        case '4':
            _Group = input("Please Input the Group Name: ")
            print(maxGrade(database1, _Group))
        case '5':
            newList = []
            for key in database1.keys():
                newList.append(key.split(":")[0])
            setList = set(newList) 
            print(setList)
        case _:
            print("Enter a valid option!")
    _TryAgainvalue = input("Do you want to try again?(Y/N): ")
    if (_TryAgainvalue.upper() == "Y"):
        TryAgain = True
    else:
        TryAgain = False

    


#Testing


