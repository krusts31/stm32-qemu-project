import serial
import tkinter as tk

# Configure the serial port
ser = serial.Serial('/dev/pts/XX', 9600)  # Replace XX with the correct number for your serial port

# Create the Tkinter window
root = tk.Tk()
root.title("LED State")

canvas = tk.Canvas(root, width=100, height=100)
canvas.pack()

led = canvas.create_oval(25, 25, 75, 75, fill="red")

def update_led_state():
    # Read a byte from the serial port
    led_state = ser.read(1)

    # Update the LED color based on the received byte
    if led_state == b'1':
        canvas.itemconfig(led, fill="green")
    else:
        canvas.itemconfig(led, fill="red")

    # Schedule the next update
    root.after(100, update_led_state)

update_led_state()
root.mainloop()

# Close the serial port
ser.close()
