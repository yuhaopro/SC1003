#Set pixels using a list of tuples
from math import fabs
from signal import pause
from time import sleep
from time import perf_counter
from random import randint

#GETTING ACCELERATION VALUES FOR AXIS
#X AND Y DETERMINES THE ORIENTATION OF THE BOARD
#acceleration = sense.get_accelerometer_raw()
#      x = acceleration[‘x’] 
#      y = acceleration[‘y’]
#      z = acceleration[‘z’]

r = (255,0,0)
g = (0,255,0)
w = (255,255,255)
b = (0, 0, 0)

def SetRandomRotation(rotationlist):
    return rotationlist[randint(0, len(rotationlist) - 1)]

def OutofTime(previoustimevalue, duration):
    if perf_counter - previoustimevalue >= duration:
        return True
    return False

def SetColor(arrowlist, colortype):
    for i in range(len(arrowlist)):
            if arrowlist[i] == b:
                arrowlist[i] = colortype
    return arrowlist


orientation = [0, 90, 180, 270]
black_arrow =  [w, w, w, w, w, w, w, w,
                w, w, w, b, w, w, w, w,
                w, w, b, b, b, w, w, w,
                w, b, w, b, w, b, w, w,
                w, w, w, b, w, w, w, w,
                w, w, w, b, w, w, w, w,
                w, w, w, b, w, w, w, w, 
                w, w, w, w, w, w, w, w]

# Prepare for game start
# Countdown from 3 2 1
for i in range(3,0,-1):
    #sense.set_rotation(SetRandomRotation(orientation))
    #sense.display_message(str(i))
    sleep(1)
    pass
gameStart = True
timer = 0
timer_duration = 1.0
points = 0

while gameStart:
    rotated_angle = SetRandomRotation(orientation)
    #sense.set_rotation(rotated_angle)
    #sense.set_pixels(black_arrow)
    #start timer
    currentTime = perf_counter()
    if (OutofTime(currentTime, timer_duration)):
        red_arrow = SetColor(black_arrow, r)
        #sense.set_pixels(red_arrow)
        gameStart = False
        break
        #sense.display_message("GG")
    else:
        #Get acceleration values
        #acceleration = sense.get_accelerometer_raw()
        #x = acceleration['x']
        #y = acceleration['y']

        #x=round(x, 0)
        #y=round(y, 0)
        green_arrow = SetColor(black_arrow)
        #if x == -1 and rotated_angle == 180:
        #sense.set_pixels(green_arrow)
        points += 1
        #elif x == 1 and rotated_angle == 0:
        #sense.set_pixels(green_arrow)
        points += 1
        #elif y == -1 and rotated_angle == 90:
        #sense.set_pixels(green_arrow)
        points += 1
        #elif y == 1 and rotated_angle == 270:
        #sense.set_pixels(green_arrow)
        points += 1
        
        timer_duration -= 0.1
    
    
    

    
        
