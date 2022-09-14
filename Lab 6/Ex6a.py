from sense_hat import SenseHat
from time import sleep

sense = SenseHat()

while True:
    pitch = sense.get_orientation()['pitch'] 
    roll = sense.get_orientation()['roll'] 
    pitch = round(pitch, 0)
    roll = round(roll, 0)
    x,y = move_marbla(pitch,roll,x,y)
    board[y][x] = w

    #print("pitch {0} roll {1}".format(round(pitch,0), round(roll,0))
    print('pitch: ',pitch, 'roll: ', roll)
    sleep(0.05)
