/*
	creates a graph of n nodes and adds q edges with edges between [1,n] and traverses the graph using bfs and dfs
*/

#include <bits/stdc++.h>

using namespace std;

class Graph{

	vector<vector<int> > v;
	int n;	
public:
	Graph(int n){
		this->n = n;
		v.resize(n+1);
	}

	void add_edge(int x,int y,bool bidir){

		v[x].push_back(y);
		if(bidir == true){
			v[y].push_back(x);
		}
	}

	void print_adj_graph(){

		for(int i=1;i<v.size();i++){

			cout << i << "-> ";
			for(vector<int> :: iterator it= v[i].begin();it != v[i].end();it++){
				cout << *it<<"  ";
			}
			cout << endl;
		}

	}	

	void bfs(int start){
		queue<int> q;
		bool visited[n+1];
		memset(visited,false,n+1);
		q.push(start);
		visited[start]=true;
		while(!q.empty()){
			int current = q.front();
			q.pop();
			cout << current <<" ";
			for(vector<int> :: iterator it = v[current].begin();it != v[current].end();it++){

				if(visited[*it]==false){
					q.push(*it);
					visited[*it]=true;
				}


			}

		}
		cout << endl;

	}

	void dfs(int start){
		stack<int> s;
		bool visited[n+1];
		memset(visited,false,n+1);
		s.push(start);
		visited[start]=true;

		while(!s.empty()){
			int current = s.top();
			s.pop();
			cout << current<< " ";
			for(vector<int>:: iterator it=v[current].begin();it !=v[current].end();it++){
				if(visited[*it]==false){
					s.push(*it);
					visited[*it]=true;
				}

			}
		}
		cout <<endl;



	}

};

int main(){
	int n; cin>>n;

	Graph g(n);
	int q; cin >> q;
	int source,dest;
	while(q--){
		cin >> source >> dest;
		g.add_edge(source,dest,true);
	}

	g.print_adj_graph();
	int start; cin >> start;
	g.bfs(start);
	g.dfs(start);

	return 0;
}