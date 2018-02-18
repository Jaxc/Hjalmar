from tkinter import *

import cmd_handler as cmd



# Here, we are creating our class, Window, and inheriting from the Frame
# class. Frame is a class from the tkinter module. (see Lib/tkinter/__init__)
class Window(Frame):

    # Define settings upon initialization. Here you can specify
    def __init__(self, master=None):
        
        # parameters that you want to send through the Frame class. 
        Frame.__init__(self, master)   

        #reference to the master widget, which is the tk window                 
        self.master = master

        #with that, we want to then run init_window, which doesn't yet exist
        self.init_window()

    #Creation of init_window
    def init_window(self):

        # changing the title of our master widget      
        self.master.title("Hjalmar GUI")

        self.master.configure(background="#FFD800")

        # allowing the widget to take the full space of the root window
        #self.pack(fill=BOTH, expand=1)

        # creating a menu instance
        menu = Menu(self.master)
        self.master.config(menu=menu)

        # create the file object)
        file = Menu(menu)

        # adds a command to the menu option, calling it exit, and the
        # command it runs on event is client_exit
        file.add_command(label="Program", command=self.client_exit)
        file.add_command(label="Load", command=self.client_exit)
        file.add_command(label="Save", command=self.client_exit)
        file.add_command(label="Exit", command=self.client_exit)
		
		#added "file" to our menu
        menu.add_cascade(label="File", menu=file)

        # create the file object)
        edit = Menu(menu)

        # adds a command to the menu option, calling it exit, and the
        # command it runs on event is client_exit
        edit.add_command(label="Undo")

        #added "file" to our menu
        menu.add_cascade(label="Edit", menu=edit)

        Radiobutton(self.master, text="None", variable=v, value=1, bg="#FFD800", bd=0).grid(row=0, sticky=W)
        Radiobutton(self.master, text="Square", variable=v, value=2, bg="#FFD800", bd=0).grid(row=1, sticky=W)
        Radiobutton(self.master, text="Saw", variable=v, value=3, bg="#FFD800", bd=0).grid(row=2, sticky=W)
        Radiobutton(self.master, text="Pulse", variable=v, value=4, bg="#FFD800", bd=0).grid(row=3, sticky=W)
        Radiobutton(self.master, text="Triangle", variable=v, value=5, bg="#FFD800", bd=0).grid(row=4, sticky=W)
        Radiobutton(self.master, text="Inverted Triangle", variable=v, value=6, bg="#FFD800", bd=0).grid(row=5, sticky=W)
        Radiobutton(self.master, text="Double Saw", variable=v, value=7, bg="#FFD800", bd=0).grid(row=6, sticky=W)
        Radiobutton(self.master, text="Sine", variable=v, value=8, bg="#FFD800", bd=0).grid(row=7, sticky=W)

        Label(self.master, text="Attack", bg="#FFD800").grid(row=1, column=2, sticky=SW)
        Label(self.master, text="Decay", bg="#FFD800").grid(row=3, column=2, sticky=SW)
        Label(self.master, text="Sustain", bg="#FFD800").grid(row=5, column=2, sticky=SW)
        Label(self.master, text="Release", bg="#FFD800").grid(row=7, column=2, sticky=SW)

        Scale(self.master, from_=0, to=127, orient=HORIZONTAL, bg="#FFD800", command=cmd.attack_update).grid(row=0, column=1, rowspan=2, sticky=W)
        Scale(self.master, from_=0, to=127, orient=HORIZONTAL, bg="#FFD800", command=cmd.decay_update).grid(row=2, column=1, rowspan=2, sticky=W)
        Scale(self.master, from_=0, to=127, orient=HORIZONTAL, bg="#FFD800", command=cmd.sustain_update).grid(row=4, column=1, rowspan=2, sticky=W)
        Scale(self.master, from_=0, to=127, orient=HORIZONTAL, bg="#FFD800", command=cmd.release_update).grid(row=6, column=1, rowspan=2, sticky=W)

        Button(self.master, text="Program",command=cmd.program_action).grid(row=10, column=1)

        e1 = Entry(self)
        e2 = Entry(self)

        #e1.grid(row=0, column=1)
        #e2.grid(row=1, column=1)

    def client_exit(self):
        exit()

if __name__ == "__main__":
    # root window created. Here, that would be the only window, but
    # you can later have windows within windows.
    root = Tk()

#    root.geometry("400x300")

    v = IntVar()

    #creation of an instance
    app = Window(root)

    #mainloop 
    root.mainloop()