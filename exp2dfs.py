n = int(input('Enter total number of nodes '))
graph = dict()
nodes = 0
while nodes < n:
    print(nodes + 1, 'Enter node')
    i = input()
    children = input("Enter child nodes of the node ").split()
    print("Children of:", i, 'are', children)
    graph.update({i: children})
    nodes += 1
print('Hence the given graph is')
print(graph.items())

# say given graph is g
def bfs(g, start, goal):
    visited = []
    if start in goal:
       print('root node', start, 'itself is goal')
       return visited
    queue = [start]
    # keep looping until there are nodes still to be checked
    while queue:
    # pop first node from queue
        node = queue.pop(0)
        if node in goal:
            print('\nGoal Found:', node)
            visited.insert(0, node)
            visited.reverse()
            print('TRAVERSAL ORDER: ', visited)
            return "Success"
        if node not in visited:
    # add explored node to end of list of checked nodes ie visited
            visited.insert(0, node)
            neighbours = g[node]
    # add neighbours of node to queue
            for neighbour in neighbours:
                queue.insert(0, neighbour)
                
    print('\nGoal Not Found')
    visited.reverse()
    print('TRAVERSAL ORDER: ', visited)
    return visited

    goal1 = []
    print('List of zero goal nodes is already created')
    g2 = input('Enter node for single goal node case ')
    goal2 = [g2]
    print('Your single goal node list has the node:', goal2)
    print('Enter nodes for multiple goal node case')
    goal3 = input().split()
    print('The multiple goal nodes are ', goal3)
    print("Zero Goal Nodes case:")
    bfs(graph, 'A', goal1)
    print("Single Goal Node case:")
    bfs(graph, 'A', goal2)
    print("Multiple Goal Nodes case:")
    bfs(graph, 'A', goal3)
