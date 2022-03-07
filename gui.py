import tkinter as tk
from tkinter import ttk

root = tk.Tk();
root.title("GUI")

# labels
name_label = ttk.Label(root, text= "Enter Your Name ")
name_label.grid(row = 0, column=0, sticky=tk.W);
#  entry box
# how to stores its data inside any variable

#hii
nameVar = tk.StringVar();

name_entrybox = ttk.Entry(root, width=16, textvariable=nameVar)
name_entrybox.grid(row = 0 , column= 1)
name_entrybox.focus()

age_label  = ttk.Label(root, text = "Enter Your Age ")
age_label.grid(row = 1, column=0, sticky=tk.W);

ageVar = tk.StringVar()

age_entrybox = ttk.Entry(root, width=16, textvariable= ageVar);
age_entrybox.grid(row = 1, column=1)


email_label = ttk.Label(root, text = "Enter Your Mail ")
email_label.grid(row=2, column=0, sticky=tk.W);

emailVar = tk.StringVar()

email_entrybox = ttk.Entry(root, width=16, textvariable=emailVar)
email_entrybox.grid(row=2, column=1)

# combobox
gender_label = ttk.Label(root, text="Enter your gender : ");
gender_label.grid(row=3, column=0);
genderVar = tk.StringVar();
gender_combobox = ttk.Combobox(root, width=14, textvariable=genderVar, state='readonly')
gender_combobox['values'] = ('Male', 'Female', 'Others');
gender_combobox.current(0)
gender_combobox.grid(row=3, column=1);


# radio button
usertypeVar = tk.StringVar();
radiobtn1 = ttk.Radiobutton(root, text = 'student', value='student', variable=usertypeVar);
radiobtn1.grid(row = 4, column=0, sticky= tk.W);

radiobtn2 = ttk.Radiobutton(root, text='teacher', value='teacher', variable=usertypeVar);
radiobtn2.grid(row=4, column=1);



# checkbutton
checkbtnVar = tk.IntVar();
chkbtn = ttk.Checkbutton(root, text="Do you want to get latest news from us?", variable=checkbtnVar)
chkbtn.grid(row = 5, columnspan=3)



# button
def action():
    username = nameVar.get();
    userage = ageVar.get();
    usermail = emailVar.get();
    usergender = genderVar.get()
    if checkbtnVar.get() == 0:
        subscribed = "No";
    else:
        subscribed = "Yes";
    print("user name : ",username)
    print("User age : ", userage);
    print("User email : ", usermail);
    print("User gender : ", usergender);
    print("User subscribed : ", subscribed);



submit_button = ttk.Button(root, text="Submit", command=action);
submit_button.grid(row = 6, column= 0);


root.mainloop();

