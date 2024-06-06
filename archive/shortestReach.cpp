#include<iostream>
#include<list>
using namespace std;

struct G{
  int V;
  list<long long> *adj;
  long long *dist;
  G(int V){
    this->V=V;
    adj=new list<long long>[V];
    dist=new long long[V];
  }
  void addEdge(int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  void bfs(int s){
    bool visited[V];
    for(int i=0;i<V;i++){
      visited[i]=false;
      dist[i]=-1;
    }
    list<long long> queue;
    visited[s]=true;
    queue.push_back(s);
    long long len=0;
    while(!queue.empty()){
      list<long long> temp;
      while(!queue.empty()){
        long long f=queue.front();
        queue.pop_front();
        dist[f]=len;
        for(auto i=adj[f].begin();i!=adj[f].end();++i){
          if(!visited[*i]){
            visited[*i]=true;
            temp.push_back(*i);
          }
        }
      }
      len+=6;
      queue=temp;
    }
    for(int i=0;i<V;i++){
      if(i!=s){
        cout<<dist[i]<<' ';
      }
    }
    cout<<endl;
  }
};


int main(){
  int q;
  cin>>q;
  while(q--){
    int N;
    long long E;
    cin>>N>>E;
    G g(N);
    for(long long i=0;i<E;i++){
      int u,v;
      cin>>u>>v;
      g.addEdge(u-1,v-1);
    }
    int s;
    cin>>s;
    g.bfs(s-1);
  }
  return 0;
}
