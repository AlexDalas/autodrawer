from pynput import keyboard
from pynput.keyboard import Key
import sys
def stop():
    listener.stop()
    sys.exit(0)
def on_press(key):
    if(key==Key.shift and sys.argv[1] == "start"):
        stop()
    elif(key==Key.ctrl and sys.argv[1] == "lock"):
        stop()
    elif(key==Key.alt and sys.argv[1] == "stop"):
        stop()
with keyboard.Listener(on_press=on_press) as listener:
    listener.join()