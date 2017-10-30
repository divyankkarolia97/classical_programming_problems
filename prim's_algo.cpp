#include <bits/stdc++.h>

using namespace std;

class Graph{
public:
	int v;
	vector<pair<int,int> > *adjList;

	Graph(int vert){
		v = vert;
		adjList = new vector<pair<int,int> >[v];
	}
	void addEdge(int a,int b,int weight){
		adjList[a].push_back(make_pair(b,weight));
		adjList[b].push_back(make_pair(a,weight));
	}

	void printGraph(){
		for(int i=0;i<v;i++){
			cout << i <<"-> ";
			for(vector<pair<int,int> > ::iterator it = adjList[i].begin();it!=adjList[i].end();it++){
				cout << it->first<<" ";
			}
			cout <<endl;
		}
	}

	int primsAlgo(int source){
		int visited[v]={};
		priority_queue<pair<int,int>,vector<pair<int,int> > , greater<pair<int,int> > > pq;

		pq.push(make_pair(0,0));

		int weight=0;
		while(pq.empty()==false){
			pair<int,int> current = pq.top();
			pq.pop();
			if(visited[current.second]){
				continue;
			}else{
				weight+=current.first;
				visited[current.second]=true;
			}	

			for(vector<pair<int,int> > :: iterator it = adjList[current.second].begin();it!=adjList[current.second].end();it++){
				if(visited[it->first]==false){
					//it->second is the weight associated with the edge
					//it->first is the edge in consideration
					pq.push(make_pair(it->second,it->first));
				}
			}

		}

		return weight;
	} 


};

int main(){
	int n,e;cin >> n >> e;
	Graph g(n);
	int u,v,weight;
	while(e--){
		cin >> u >> v >> weight;
		g.addEdge(u,v,weight);
	}
	cout <<endl;
	g.printGraph();
	cout <<"\nThe minimum weight of spanning tree is:  "<< g.primsAlgo(0)<<endl;
	return 0;
}