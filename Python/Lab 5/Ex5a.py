from sense_hat import SenseHat
sense = SenseHat()
sense.set_rotation(180)

def get_color(color):
    keep_looping = True
    no_of_try  = 1
    while keep_looping:
        if no_of_try > 3:
            break
        color_str = input("Enter the value of the " + color + \
                        " color for message (0 to 255):")
        try:
            color_int = int(color_str)
            if color_int < 0 or color_int > 255:
                no_of_try += 1
                print("Invalid value!")
                continue
            
            return color_int    
        except:
            print("Invalid value!")
            no_of_try += 1
            
    return 0
#---------------------------------------------------------
# r_int = get_color("red")
# g_int = get_color("green")
# b_int = get_color("blue")
# msg_color = (r_int, g_int, b_int)
# sense.show_message("I got it!", text_colour = msg_color)


        
