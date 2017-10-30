#include <bits/stdc++.h>

using namespace std;

class Graph{
public:
	pair<int,pair<int,int> > *edgeList;
	int *v;

	Graph(int vert,int edges){
		edgeList = new pair<int,pair<int,int> >[edges];
		v = new int[vert]; 
		for(int i=0;i<vert;i++){
			v[i]=i;
		}
	}

	bool isNotCycle(int a,int b){
		int temp1=a;
		while(temp1!=v[temp1]){
			temp1 = v[temp1];
		}
		int temp2=b;
		while(temp2!=v[temp2]){
			temp2 = v[temp2];
		}

		if(temp1!=temp2){

			if(temp1<=temp2){
				v[temp2]=temp1;

			}else{
				v[temp1]=temp2;
			}
			
			return true;
		}
		else{
			return false;
		}
	}

};

int main(){

	int n,e;cin>> n >>e;

	Graph g(n,e);

	int u,v,weight;
	for(int i=0;i<e;i++){
		cin >> u >> v >>weight;
		g.edgeList[i].first=weight;
		g.edgeList[i].second.first=u;
		g.edgeList[i].second.second=v;
	}
	sort(g.edgeList,g.edgeList+e);
	
	// for(int i=0;i<e;i++){
	// 	cout << g.edgeList[i].second.first<<" "<<  g.edgeList[i].second.second << "---> "<< g.edgeList[i].first <<endl;
	// }

	int current =0;
	int edges=n-1;
	int minWeight=0;
	cout << "The chosen edges are : "<<endl;
	while(edges){
		int u = g.edgeList[current].second.first;
		int v = g.edgeList[current].second.second;

		if(g.isNotCycle(u,v)){	
			cout<<setw(10) << u <<","<< v << endl;
			minWeight+= g.edgeList[current].first;
			edges--;
		}else{
			current++;
		}

	}

	cout<<"Weight of MST is: " << minWeight<<endl;


	return 0;
}