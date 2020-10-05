import random
def checkValid(guess,guessedcity):
            validLetters="abcdefghijklmnopqrstuvwxyz"
            if guess in validLetters:
                if guess not in guessedcity:
                    guessedcity=guessedcity+guess
                    return guessedcity
            
            
            return guessedcity
                
                

def hangman():
    cities=random.choice(['mumbai','lucknow','delhi','kolkata','bangalore','hyderabad','chennai','jaipur','dehradun','bhopal'])
    turns=10
    guessedcity=""
    validLetters="abcdefghijklmnopqrstuvwxyz"
    # main=""
    while(len(cities)>0):
        main=""
        for letter in cities:
            if letter in guessedcity:
                main=main+letter
            else:
                main=main+"_"+" "
       
        if(main==cities):
            print("Name of city: ",cities.upper())
            print("HURREY!!  YOU WON!!")
            print("You saved a LIFE...<3")
            print("***********")
            print("    \O/    ")
            print("     |     ")
            print("    / \    ")
            break
        
        print("Guess the name of city: ",main)
        guess=input() 
        
        
        
                
        guessedcity=str(checkValid(guess,guessedcity))
                
        if guess not in cities:
            turns=turns-1
            if(turns==9):
                print("9 turns left")
                print("***********")
            elif(turns==8):
                print("8 turns left")
                print("***********")
                print("     O     ")
            elif(turns==7):
                print("7 turns left")
                print("***********")
                print("     O     ")
                print("     |     ")
            elif(turns==6):
                print("6 turns left")
                print("***********")
                print("     O     ")
                print("     |     ")
                print("    /      ")
            elif(turns==5):
                print("5 turns left")
                print("***********")
                print("     O     ")
                print("     |     ")
                print("    / \    ")
            elif(turns==4):
                print("4 turns left")
                print("***********")
                print("    \O     ")
                print("     |     ")
                print("    / \    ")
            elif(turns==3):
                print("3 turns left")
                print("***********")
                print("    \O/    ")
                print("     |     ")
                print("    / \    ")
            elif(turns==2):
                print("2 turns left")
                print("***********")
                print("    \O/ |  ")
                print("     |     ")
                print("    / \    ")
            elif(turns==1):
                print("1 turn left")
                print("***********")
                print("    \O/_|  ")
                print("     |     ")
                print("    / \    ")
                print("BEWARE!! Last Chance to Save a Man..\n")
            elif(turns==0):
                print("***********")
                print("     O_|   ")
                print("    /|\    ")
                print("    / \    ")
                print("YOU LOSE..!! You cannot let a man die...")
                print("Correct Answer: ",cities.upper())
                break
            
name=input("Enter your name: ")
print("Welcome ",name," !!\n")
print("=======================================================================\n")
print("Try to guess the name of city in less than 10 attempts...\n")
print("*Hint: One of the state capital among the top 10 states of India*")
hangman()
print("Thank you for staying with US!!")




