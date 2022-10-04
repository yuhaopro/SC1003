#Define 4 colours
#Display 4 random colours on all 4 corners of the screen
#Width of RPI screen = 0 - 7
#Height of RPI screen = 0 - 7
# Display at position 0-0, 0-7, 7-0, 7-7
from random import randint
_RPISCREENWIDTH = 8
_RPISCREENHEIGHT = 8
red = (255,0,0)
yellow = (255,255,0)
blue = (0,0,255)
green = (0,255,0)

colorList = [red, yellow, blue, green]

#sense.clear()
for i in range(_RPISCREENHEIGHT):
    for j in range(_RPISCREENWIDTH):
        if i == 0 and j == 0:
            print(i,j,colorList[randint(0, len(colorList) - 1)])
            #sense.set_pixel(i,j,colorList[randint(0, len(colorList) - 1)])
        if i == 0 and j == _RPISCREENWIDTH - 1:
            print(i,j,colorList[randint(0, len(colorList) - 1)])
            #sense.set_pixel(i,j,colorList[randint(0, len(colorList) - 1)])
        if i == _RPISCREENHEIGHT - 1 and j == 0:
            print(i,j,colorList[randint(0, len(colorList) - 1)])
            #sense.set_pixel(i,j,colorList[randint(0, len(colorList) - 1)])
        if i == _RPISCREENHEIGHT - 1 and j == _RPISCREENWIDTH - 1:
            print(i,j,colorList[randint(0, len(colorList) - 1)])
            #sense.set_pixel(i,j,colorList[randint(0, len(colorList) - 1)])

