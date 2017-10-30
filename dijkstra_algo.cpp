#include <bits/stdc++.h>

using namespace std;

class Graph{
	int n;
	vector<vector<pair<int,int> > > g;

public:
	Graph(int e){
		this->n = e;
		g.resize(e);
	}

	void addEdge(int a,int b,int weight){
		g[a].push_back(make_pair(b,weight));
		g[b].push_back(make_pair(a,weight));
	}


	void bfs(){

		queue<int> q;
		bool visited[n]={};

		q.push(0);
		visited[0] = true;
		while(q.empty() == false){
			int current = q.front();
			cout << current <<" ";
			q.pop();
			for(vector<pair<int,int> > :: iterator it = g[current].begin();it!=g[current].end();it++){
				
				if(visited[it->first] == false){
					q.push(it->first);
					visited[it->first] = true;
				}
			}
		}
		cout <<endl;
		return;
	}

	void dijkstra(int source){
		bool visited[n]={};
		int dist[n];
		for(int i=0;i<n;i++){
			dist[i]=INT_MAX;
		}
		dist[source] = 0;
		
		while(checkAllIncluded(visited)){
			int current = findMinWhichIsNotIncluded(visited,dist);
			//iterate over the adjacent edges of the curent vertex and then update the value of weights
			for(vector<pair<int,int > > :: iterator it = g[current].begin();it!=g[current].end();it++){
				if(dist[current]+(it->second) < dist[it->first]){
					dist[it->first] = dist[current]+(it->second);
				}	
			}
			visited[current]=true;


		}

		for(int i=0;i<n;i++){
			cout<<setw(10) << i <<"--->" << setw(10)  << dist[i]<<endl;
		}
		cout << endl;
	}
	int findMinWhichIsNotIncluded(bool visited[],int dist[]){
		int min = INT_MAX;
		int index=-1;
		for(int i=0;i<n;i++){
			if(dist[i]<min && visited[i] == false){
				min = dist[i];
				index = i;
			}
		}
		return index;

	}

	bool checkAllIncluded(bool arr[]){
		for(int i=0;i<n;i++){
			if(arr[i] == false){
				return true;
			}
		}
		return false;
	}


};



int main(){

	Graph myGraph(9);

	myGraph.addEdge( 0, 1, 4);
    myGraph.addEdge( 0, 7, 8);
    myGraph.addEdge( 1, 2, 8);
    myGraph.addEdge( 1, 7, 11);
    myGraph.addEdge( 2, 3, 7);
    myGraph.addEdge(2, 8, 2);
    myGraph.addEdge( 2, 5, 4);
    myGraph.addEdge( 3, 4, 9);
    myGraph.addEdge( 3, 5, 14);
    myGraph.addEdge( 4, 5, 10);
    myGraph.addEdge( 5, 6, 2);
    myGraph.addEdge( 6, 7, 1);
    myGraph.addEdge( 6, 8, 6);
    myGraph.addEdge( 7, 8, 7);

    cout <<"The BFS traversal of the graph is: \n\n\t";
	myGraph.bfs();

	cout <<"\nThe dist of vertex from the source vertex are: \n";
	myGraph.dijkstra(0);

	return 0;
}