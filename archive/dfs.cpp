#include<iostream>
#include<list>

using namespace std;

class Graph{
  int V;
  list<int> *adj;
public:
  Graph(int V);
  void addEdge(int u,int w);
  void DFShelper(int s,bool visited[]);
  void DFS(int s);
};

Graph::Graph(int V){
  this->V=V;
  adj = new list<int>[V];
}
void Graph::addEdge(int u, int w){
  adj[u].push_back(w);
}
void Graph::DFShelper(int s, bool *visited){
  cout<<s<<" ";

  list<int>::iterator i;

  for(i=adj[s].begin();i!=adj[s].end();++i){
	if(!visited[*i]){
	  visited[*i]=true;
	  DFShelper(*i,visited);
	}
  }
}

void Graph::DFS(int s){
  bool *visited = new bool[V];
  for (int i =0 ; i < V; ++i) {
	visited[i]=false;
  }
  visited[s]=true;
  DFShelper(s, visited);
}

int main(){
  Graph g(4);
  g.addEdge(0,1);
  g.addEdge(0,2);
  g.addEdge(1,2);
  g.addEdge(2,0);
  g.addEdge(2,3);
  g.addEdge(3,3);
  g.DFS(2);

  return 0;
}
