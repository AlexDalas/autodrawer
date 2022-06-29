This is the keybind software included with the C++ program.

# Why?

Keybinds in C++ are a total hassle cross-platform. I would rather have a binary that has the software in an easier language instead.

# How does it work?

The program takes in arguments at start. The program will close when the correct button is clicked, and sends a success code to the Autodrawer program. The AutoDrawer then knows to start drawing, or stop, or lock to the last position.

# Where is this downloaded?

When the Autodrawer is started at the first time, it will place the binary of this in the persistent storage.

On Linux, this is ~/.local/share/AutoDrawer/

On Windows, this is C:/Users/<USER>/AppData/Roaming/AutoDrawer/

On Mac, this is "~/Library/Application\ Support/AutoDrawer/

# How do I compile the application?

For whatever reason, if you need to compile it:

Install NodeJS and NPM.

Download the KeybindSoftware code, and make sure the source is not zipped.

Run "npm install" to install the dependencies.

Download nexe if you want to get a single binary.

In the KeybindSoftware directory, run "nexe main.js".

This would generate the build that is built in.

Place the file in the persistent storage from before.
