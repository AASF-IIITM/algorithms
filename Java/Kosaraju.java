import java.io.*; 
import java.util.*; 
import java.util.LinkedList; 


class Graph 
{ 
	private int V; // No. of vertices 
	private LinkedList<Integer> adj[]; //Adjacency List 

	
	Graph(int v) 
	{ 
		V = v; 
		adj = new LinkedList[v]; 
		for (int i=0; i<v; ++i) 
			adj[i] = new LinkedList(); 
	} 

	
	void addEdge(int v, int w) { adj[v].add(w); } 

	
	void DFSUtil(int v,boolean visited[]) 
	{ 
		
		visited[v] = true; 
		System.out.print(v + " "); 

		int n; 

		
		Iterator<Integer> i =adj[v].iterator(); 
		while (i.hasNext()) 
		{ 
			n = i.next(); 
			if (!visited[n]) 
				DFSUtil(n,visited); 
		} 
	} 

	
	Graph getTranspose() 
	{ 
		Graph g = new Graph(V); 
		for (int v = 0; v < V; v++) 
		{ 
			
			Iterator<Integer> i =adj[v].listIterator(); 
			while(i.hasNext()) 
				g.adj[i.next()].add(v); 
		} 
		return g; 
	} 

	void fillOrder(int v, boolean visited[], Stack stack) 
	{ 
		
		visited[v] = true; 

		
		Iterator<Integer> i = adj[v].iterator(); 
		while (i.hasNext()) 
		{ 
			int n = i.next(); 
			if(!visited[n]) 
				fillOrder(n, visited, stack); 
		} 

		
		stack.push(new Integer(v)); 
	} 


	void printSCCs() 
	{ 
		Stack stack = new Stack(); 

		
		boolean visited[] = new boolean[V]; 
		for(int i = 0; i < V; i++) 
			visited[i] = false; 

		
		for (int i = 0; i < V; i++) 
			if (visited[i] == false) 
				fillOrder(i, visited, stack); 

		Graph gr = getTranspose(); 

		for (int i = 0; i < V; i++) 
			visited[i] = false; 

		
		while (stack.empty() == false) 
		{ 
			
			int v = (int)stack.pop(); 

		
			if (visited[v] == false) 
			{ 
				gr.DFSUtil(v, visited); 
				System.out.println(); 
			} 
		} 
	} 


	public static void main(String args[]) 
	{ 
		// Create a graph given in the above diagram 
		Graph g = new Graph(5); 
		g.addEdge(1, 0); 
		g.addEdge(0, 2); 
		g.addEdge(2, 1); 
		g.addEdge(0, 3); 
		g.addEdge(3, 4); 

		System.out.println("Following are strongly connected components "+ 
						"in given graph "); 
		g.printSCCs(); 
	} 
}
