i=0
def towerOfHanoi(disks, source, auxiliary, target):
    global i
    if disks == 1:
        print("Move disk 1 from tower {} to tower {}.".format(source, target))
        i+=1
        return
 
    towerOfHanoi(disks - 1, source, target, auxiliary)
    print("Move disk {} from tower {} to tower {}.".format(disks, source, target))
    i+=1
    towerOfHanoi(disks - 1, auxiliary, source, target)
 

disks = int(input('Enter number of disks: \n'))
towerOfHanoi(disks, 'A', 'B', 'C')
print("Total number of steps required are {}".format(i))