#Consider a system for storing anonymous grades of each lab class. 
# Define a data structure, which can identify individuals in each lab group by an ID number 1-40 (inclusive). 
# To identify the person in the entire class you would also need the group name, e,g., ‘FE2’. 
# Each corresponding person should have a number between 1-100 (inclusive) to define grade.
Lab_Groups = ["FE", "SQ", "DG"]
ID_List = [x for x in range(1,41)]
Grade_List = [x for x in range(1,101)]

Dict1 = {}
for group in Lab_Groups:
    for ID_value in ID_List:
        for grade in Grade_List:
            Dict1[str(group) + str(ID_value)] = grade
            Grade_List.remove(grade)
            break

print(Dict1)
