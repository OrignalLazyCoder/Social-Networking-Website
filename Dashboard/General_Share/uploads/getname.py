global name
global score

def getname():
    global name
    global score
    print("Enter your name:")
    name=str(input())
    file=open("names.txt","w")
    file.write("file created")
    file.close()
    file.open("names.txt","a")
    file.write("",name)
    file.close()

getname()
