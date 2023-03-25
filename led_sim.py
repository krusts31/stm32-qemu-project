import tkinter as tk
import time

"""
def toggle_led():
    if canvas.itemcget(led, "fill") == "red":
        canvas.itemconfig(led, fill="gray")
    else:
        canvas.itemconfig(led, fill="red")
    root.after(1000, toggle_led)
"""

root = tk.Tk()
root.title("LED Simulator")

canvas = tk.Canvas(root, width=1400, height=400)
canvas.pack()

led1 = canvas.create_oval(50, 150, 150, 250, fill="gray")
led2 = canvas.create_oval(200, 150, 300, 250, fill="gray")
led3 = canvas.create_oval(350, 150, 450, 250, fill="gray")
led4 = canvas.create_oval(500, 150, 600, 250, fill="gray")
led5 = canvas.create_oval(650, 150, 750, 250, fill="gray")
led6 = canvas.create_oval(800, 150, 900, 250, fill="gray")
led7 = canvas.create_oval(950, 150, 1050, 250, fill="gray")
led8 = canvas.create_oval(1100, 150, 1200, 250, fill="gray")
led9 = canvas.create_oval(1250, 150, 1350, 250, fill="gray")

#toggle_led(led1, led2)
root.mainloop()
