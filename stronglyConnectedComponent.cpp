#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

class DirectedGraph {
     int V; //NUmber of vertex in the graph
     vector<vector<int>> adjList;
     DirectedGraph transposeGraph();
     void fillOrder(int v, bool visited[], stack<int> &Stack);
     void DFS(int vertex, bool visited[]);
     
     public: 
     
     DirectedGraph(int size) : V(size) {
         adjList.resize(size);     
     } 
     
     void insertEdge(int x, int y);
     void SCCs();
};


/*
inseretEdge
Function to insert new edge into the directed graph. 
*/

void DirectedGraph::insertEdge(int x, int y){
 adjList[x].push_back(y);    
}


/*
transposeGraph
Use to transpose a graph i.e reverse the direction of each edge
*/
DirectedGraph DirectedGraph::transposeGraph(){
    DirectedGraph transposeGraph(V);
    for(int i=0; i<V; i++){
        for(vector<int>::iterator itr = adjList[i].begin(); itr!=adjList[i].end(); itr++){
            
            transposeGraph.adjList[*itr].push_back(i);
        }    
    }    
    return transposeGraph;
}

void DirectedGraph::fillOrder(int v, bool visited[], stack<int> &Stack) {
    visited[v] = true;
    for(vector<int>::iterator itr = adjList[v].begin(); itr!=adjList[v].end(); itr++){
            if(!visited[*itr]){
                fillOrder(*itr, visited, Stack);
            }            
    }    
    Stack.push(v);//If you place this in the begining, this won't work. 
}

/*
DFS: Traverse the graph depth first way. 
Paramters: 
vertex: The graph vertex to start the depth first search/traversal from. 
visited: list of visited nodes. Use to avoid looping infinitely if a cycle exists. 
*/
void DirectedGraph::DFS(int vertex, bool visited[]){
	visited[vertex] = true;
	cout << vertex << " ";
	for(int descendent : adjList[vertex])
	{
		if(!visited[descendent])
			DFS(descendent, visited);
	}	
}

/*
SCCs: Find all the strongly connected component of a directed graph. 
Strongly connected components divide a graph into groups where every vertex is reachable from every other vertex 
*/

void DirectedGraph::SCCs() {
	stack<int> nodeStack;
	
	bool *visited=new bool[V];
	for(int i = 0; i < V; i++) {
	   if(visited[i] == false) 
	    fillOrder(0, visited, nodeStack);	
	}
	
	DirectedGraph transposedGraph = transposeGraph();
	
	memset(visited, false, V);
	while(!nodeStack.empty()){
		int newVertex = nodeStack.top();
		nodeStack.pop();
		if(!visited[newVertex]){
			transposedGraph.DFS(newVertex, visited);
		}
		cout << endl;		
	}    
}

int main(){
    DirectedGraph g(7); 
    g.insertEdge(0, 1); 
    g.insertEdge(1, 2); 
    g.insertEdge(2, 3); 
    g.insertEdge(1, 4); 
    g.insertEdge(3, 0);
    g.insertEdge(4, 5);
    g.insertEdge(5, 6);
    g.insertEdge(6, 4); 
  
    cout << "Following are strongly connected components in the"
            "given graph \n"; 
    g.SCCs();
    return 0; 
}
