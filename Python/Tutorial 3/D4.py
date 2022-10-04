#Given two lists of grades (list of integers) from two classes
#write a Python program that will check which class 
# has the highest average score and the highest maximum score.
class_list_1 = [5,10,7,50]
class_list_2 = [6,20,3,41]

def Average(class_list_x):
    return sum(class_list_x) / len(class_list_x)

class_list_1_max = max(class_list_1)
class_list_2_max = max(class_list_2)
class_list_1_avg = Average(class_list_1)
class_list_2_avg = Average(class_list_2)

if (class_list_1_max > class_list_2_max):
    #class_list_1 has the highest max score
    print("class 1 has higher maximum score")
    if (class_list_1_avg > class_list_2_avg):
        #class_list_1 has the highest avg score
        print("class 1 has higher average score")

elif (class_list_1_max < class_list_2_max):
    print("class 2 has higher maximum score")
    if (class_list_1_avg < class_list_2_avg):
        print("class 2 has higher average score")