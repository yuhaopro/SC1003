#Set pixels using a list of tuples
from time import sleep
from random import randint
r = (255,0,0)
y = (255,255,0)
b = (0,0,255)
g = (0,255,0)

def random_color_swap(listofcolours):
    return listofcolours[randint(0, len(orientation) - 1)]

Colour_list = [r, y, b, g]
orientation = [0, 90, 180, 270]
image_pixels = [y, b, b, b, b, b, b, b,
                b, b, b, y, b, b, b, b,
                b, b, y, y, y, b, b, b,
                b, y, b, y, b, y, b, b,
                b, b, b, y, b, b, b, b,
                b, b, g, g, g, b, b, b,
                b, b, b, g, b, b, b, b, 
                b, b, b, b, b, b, b, g]
#set_pixels(image_pixel)
checking = 0
while checking < 100:
    #Alternate pixel color
    for i in range(len(image_pixels)):
        #If equals to a randomly selected colour, then change it to another randomly selected colour
        if image_pixels[i] == random_color_swap(Colour_list):
            image_pixels[i] = random_color_swap(Colour_list)
        sleep(0.2)
    #set rotation after finish alternating all colors
    #set_rotation(orientation[randint(0, len(orientation) - 1)])
    #sleep for 1 second
    sleep(1)

    
        
