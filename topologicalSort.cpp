#include<iostream>
#include<list>
#include<stack>
using namespace std;

class Graph{
  int V;
  list<int> *adj;
public:
  Graph(int V);
  void addEdge(int u,int w);
  void TSutil(int s,bool *visited, stack<int> &ans);
  void topologicalSort();
};

Graph::Graph(int V){
  this->V=V;
  adj=new list<int>[V];
}
void Graph::addEdge(int u, int w){
  adj[u].push_back(w);
}

void Graph::TSutil(int s, bool *visited, stack<int> &ans){
  visited[s]=true;
  list<int>::iterator i;
  for(i=adj[s].begin();i!=adj[s].end();++i){
    if(!visited[*i]){
      TSutil(*i,visited,ans);
    }
  }
  ans.push(s);
}

void Graph::topologicalSort(){
  bool visited[V];
  for (int i=0; i<V; ++i) {
    visited[i]=false;
  }
  stack<int> ans;
  for(int i=0;i<V;i++){
    if(!visited[i])
      TSutil(i,visited,ans);
  }
  while(!ans.empty()){
    cout<<ans.top()<<" ";
    ans.pop();
  }
  cout<<endl;
}

int main(){
  Graph g(6);
  g.addEdge(2, 3);
  g.addEdge(3, 1);
  g.addEdge(4, 0);
  g.addEdge(4, 1);
  g.addEdge(5, 0);
  g.addEdge(5, 2);

  g.topologicalSort();

}
