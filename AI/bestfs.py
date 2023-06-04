tree = {}
heu = {}
root = 0
goal = []

print('Implementing BestFS\n')
def add():
    val = input('Enter the node : ')
    tree[val] = []
    hval = int(input('Enter the heuristic value of the node : '))
    heu[val] = hval
    num = int(input('Enter the number of child nodes: '))
    for n in range(num):
        temp = input('Enter the child nodes: ')
        tree[val].append(temp)
        
def initialize():
    global root
    root = input('Enter the value of initial node : ')
    numg = int(input('Enter the number of goal node : '))
    for i in range(numg):
        goal.append(input('Enter the goal node : '))
        
def goaltest(g):
    if g in goal:
        return True
    else:
        return False

def display():
    print(tree)
    print(heu)
    
def BestFS():
    initialize()
    opens = []
    closes = []
    
    
    pt = root
    opens.append([pt, None, heu[pt]])
    
    while len(opens) > 0:
        opens = sorted(opens, key=lambda x: x[2])
        # print(opens) IF YOU WANT TO SEE THE LIST
        pt = opens[0][0]
        closes.append(opens[0][0])
        opens.pop(0)
        
        child = tree[pt]
        for n in range(len(child)):
            if (child[n] not in closes) and (child[n] not in opens): # TO CHECK THAT IT ISN'T ALREADY VISITED
                opens.append([child[n], pt, heu[child[n]]])
        child.clear()
        
        res = goaltest(pt)
        if res:
            print('\nGoal node found')
            print(closes)
            exit()
            
        if len(opens) == 0:
            print('Goal node not found')
            exit()
    

    
while 1:
    print('1.Add node and children')
    print('Note: Use this option until you have entered heuristics for all child nodes')
    print('2.Perform BestFS')
    print('3.Display')
    print('4.Exit')
    ch = int(input())
    
    if ch == 1:
        add()
    elif ch == 2:
        BestFS()
    elif ch == 3:
        display()
    elif ch == 4:
        exit()
