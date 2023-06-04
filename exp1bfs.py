from collections import deque

# Define the graph as a dictionary
graph = dict()

num= int(input("Enter number of nodes : "))

for i in range(num):
    print("Enter parent node: ")
    m=input()
    child= input("Enter child nodes of the node ").split()
    graph.update({m:child})

# Define the goal node
goal = []
#goal().split()
#found_goal=[]
n = int(input("Enter number of goals : "))
for i in range(0, n):
    g = str(input())
  
    goal.append(g)


# Implement BFS
def bfs(graph, start, goal):
    # Create an open list as a queue and add the start node
    open_list = deque([start])
    # Create a closed list to hold all the traversed nodes
    closed_list = []

    while open_list:
        # Get the first node from the open list
        current_node = open_list.popleft()
         
        # Add the current node to the closed list
        closed_list.append(current_node)
        
       # Check if the current node is the goal node
        if current_node in goal:
            print("Traversal Order: ", closed_list)
            return True

        # Add all the neighbors of the current node to the open list
        for neighbor in graph[current_node]:
            if neighbor not in closed_list and neighbor not in open_list:
                open_list.append(neighbor)

    # If the goal node is not found, return False
    return False

# Test the BFS function
start = input("Please enter starting node: ")

if bfs(graph, start, goal):
    print(f"{goal} found from {start} using BFS")
    #print(found_goal[0])
    #for i in closed_list
    
else:
    #for k in goal:
    print(f"{goal} not found from {start} using BFS")
