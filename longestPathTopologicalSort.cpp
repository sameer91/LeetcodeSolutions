#include<bits/stdc++.h>
using namespace std;

struct adjNode{
	int u;
	int w;
	adjNode(int u,int w){
		this->u =u;
		this->w=w;
	}
};

class Graph{
	int V;
	list<adjNode> *adj;
	void tsUtil(int i, bool *visited, stack<int> &ts){
		visited[i]=true;
		list<adjNode>::iterator it;
		for(it=adj[i].begin();it!=adj[i].end();++i){
			if(!visited[it->u]){
				tsUtil(it->u,visited,ts);
			}
		}
		ts.push(i);
	}
public:
	Graph(int V){
		this->V=V;
		this->adj = new list<adjNode>[V];
	}
	void addEdge(int v,int u, int w){
		adj[v].push_back(adjNode(u,w));
	}
	stack<int> tSort(){
		bool visited[V];
		for(int i=0;i<V;++i){
			visited[i]=false;
		}
		stack<int> ts;
		for(int i=0;i<V;++i){
			if(!visited[i]){
				tsUtil(i,visited,ts);
			}
		}
		return ts;
	}
	vector<int> longestPath(int s){
		vector<int> distance(V,INT_MIN);
		distance[s]=0;
		stack<int> ts=tSort();

		while(!ts.empty()){
			int i=ts.top();
			ts.pop();
			if(distance[i]>INT_MIN){
				list<adjNode>::iterator it;
				for(it=adj[i].begin();it!=adj[i].end();++i){
					if(distance[it->u] < distance[i]+it->w)
						distance[it->u]=distance[i]+it->w;
				}
			}
		}

		return distance;
	}
};
