#Set pixels using a list of tuples
from time import sleep
r = (255,0,0)
y = (255,255,0)
b = (0,0,255)
g = (0,255,0)

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
        if image_pixels[i] == y:
            image_pixels[i] = g
        elif image_pixels[i] == g:
            image_pixels[i] = y
    #set rotation after finish alternating all colors
    #set_rotation(orientation[randint(0, len(orientation) - 1)])
    #sleep for 1 second
    sleep(1)
    print(image_pixels[0])

    
        
