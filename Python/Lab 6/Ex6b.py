from sense_hat import SenseHat
from time import sleep

# This function checks the pitch value and the x coordinate  
# to determine whether to move the marble in the x-direction.
# Similarly, it checks the roll value and y coordinate to
# determine whether to move the marble in the y-direction.
def move_marble(pitch,roll,x,y): 
    new_x = x    #assume no change to start with
    new_y = y    #assume no change to start with
    if 1 < pitch < 179 and x != 0: 
        new_x -= 1    # move left
    elif 359 > pitch > 179 and x != 7: 
        new_x += 1    # move right
    if 1 < roll < 179 and y != 7: 
        new_y += 1    # move up
    elif 359 > roll > 179 and y != 0: 
        new_y -= 1    # move down

    return new_x, new_y

sense = SenseHat()
sense.clear()
x = 2
y = 2
b = [0,0,0]
w = [255,255,255]
#2d array
board = [[b,b,b,b,b,b,b,b], 
         [b,b,b,b,b,b,b,b],
         [b,b,b,b,b,b,b,b],
         [b,b,b,b,b,b,b,b],
         [b,b,b,b,b,b,b,b],
         [b,b,b,b,b,b,b,b],
         [b,b,b,b,b,b,b,b], 
         [b,b,b,b,b,b,b,b]]
board_1D=sum(board,[])        # convert to 1-dimension list
print(board_1D)               # for code debugging
sense.set_pixels(board_1D)    # display it

while True:
    pitch = sense.get_orientation()['pitch'] 
    roll = sense.get_orientation()['roll'] 
    pitch = round(pitch, 0)
    roll = round(roll, 0)
    x,y = move_marble(pitch,roll,x,y)
    board[y][x] = w
    sense.set_pixels(sum(board,[])) 
    sleep(0.05)
