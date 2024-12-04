# Imports the Stuff
import serial
import time
from tkinter import *



# Sets the Window Up
root = Tk()
root.title("MainMenu")
root.maxsize(height=200, width=400)
root.minsize(height=200, width=400)
root.configure(height=200, width=400)
root.configure(bg="lightgrey")



def write_read():

    x = userInput.get()
    arduino.write(bytes(x, 'utf-8'))
    time.sleep(0.05)
    data = arduino.readline()
    print("button pressed")

    return data

#while True:
#    num = input("Enter a number: ")
#    value = write_read(num)
#    print(value)

def test():
    print(userInput.get())
    print("Test - Normal Print Successful")
    

mainTitle = Label(root, text="Decimal to Binary Converter", bg="lightGrey", font=("Arial",17, "bold"))
mainTitle.place(x=45, y=5)

prompt = Label(root, text="Please Enter The Number You Wish To Convert (0 - 255)", bg="lightGrey", font=("Arial", 10))
prompt.place(x=40, y=40)

userInput = Entry(root, font=("Arial", 20))
userInput.place(x=50, y=75)

submitButton = Button(root, text="Convert", command=write_read)
submitButton.place(x=175, y=125)

# Joins With the arduino
arduino = serial.Serial(port='COM3', baudrate=9600, timeout=.1)

root.mainloop()


