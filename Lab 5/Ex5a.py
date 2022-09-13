# from sense_hat import SenseHat
# sense = SenseHat()
# sense.set_rotation(180)

def get_color(color):
    keep_looping = True
    no_of_try  = 1
    while keep_looping:
        color_str = input("Enter the value of the " + color + \
                        " color for message (0 to 255):")
        try:
            color_int = int(color_str)
            if color_int < 0 or color_int > 255:
                no_of_try += 1
                print("Invalid value!")
            else:
                return color_int
        except:
            print("Invalid value!")
            no_of_try += 1
        if no_of_try > 3:
            break
    return 0



        
