   from collection import deque
   def BFS(graph,u): 
        visited=set()
        queue = deque() 
        queue.append(u) 
        visited.add(u)
        while len(queue)!=0: 
            s = queue.popleft() 
            print (s, end = " ")  
            for i in graph[s]: 
                if i not in visited: 
                    queue.append(i) 
                    visited.add(i)
