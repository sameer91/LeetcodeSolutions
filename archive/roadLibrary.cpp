#include<iostream>
#include<list>
using namespace std;
class Graph{
  int V;
  int cl;
  int cr;
  list<int> *adj;
public:
  Graph(int V,int l,int c){
    this->V=V;
    this->cl=l;
    this->cr=c;
    adj = new list<int>[V];
  }
  void addEdge(int u,int v);
long long  int dfsUtil(int v, bool visited[]);
long long  int dfs();
};
void Graph::addEdge(int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

long long int Graph::dfsUtil(int v,bool visited[]){
long long  int city=1;
  visited[v]=true;
  for(auto i=adj[v].begin();i!=adj[v].end();++i){
    if(!visited[*i]){
      city+=dfsUtil(*i,visited);
    }
  }
  return city;
}

long long int Graph::dfs(){
  bool visited[V];
  long long int cost=0;
  for(int i=0;i<V;i++){
    visited[i]=false;
  }
  for(int i=0;i<V;i++){
    if(!visited[i]){
      cost+=cl;
      cost+=(dfsUtil(i, visited)-1)*cr;
    }
  }
  // cout<<road<<' '<<lib<<endl;
  return cost;
}


int main(){
  int q;
  cin>>q;
  while(q--){
    int N,M;
    cin>>N>>M;
    int cLib,cRoad;
    cin>>cLib>>cRoad;

    Graph g(N,cLib,cRoad);
    int u,v;
    for(int i=0;i<M;i++){
      cin>>u>>v;
      g.addEdge(u-1, v-1);
    }
    if(cLib < cRoad){
      cout<<N*cLib<<endl;
    }
    else
      cout<<g.dfs()<<endl;
  }
  return 0;
}
