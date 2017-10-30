#include <bits/stdc++.h>

using namespace std;

bool compareFunction(pair<int,int> a,pair<int,int> b){
	return (a.first/a.second)>(b.first/b.second);
}

int main(){
	int n;cin >> n;
	vector<pair<int,int> > v(n);
	for(int i=0;i<n;i++){
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(),v.end(),compareFunction);
	int weight;cin >>weight;
	int profit=0;
	int i=0;
	while(i<v.size()){
		if(weight==0){
			break;
		}
		if(weight>=v[i].second){
			weight-=v[i].second;
			profit+=v[i].first;
			i++;
		}else{
			profit+= (v[i].first/v[i].second)*weight;
			weight=0;
		}
	}

	cout<< "The maximum profit is :" << profit<<endl;

	return 0;
}