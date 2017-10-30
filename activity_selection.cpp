#include <bits/stdc++.h>

using namespace std;

bool compareFunc(pair<int,pair<int,int> >  a,pair<int,pair<int,int> > b){
	return a.second.second < b.second.second;
}

int main(){

	int t;cin >>t;

	while(t--){

		int n;cin >> n;;

		vector<pair<int,pair<int,int> > > activities(n);

		for(int i=0;i<n;i++){
			cin >> activities[i].second.first;
			activities[i].first=i+1;
		}

		for(int i=0;i<n;i++){
			cin >> activities[i].second.second;
		}

		sort(activities.begin(),activities.end(),compareFunc);

		int end = activities[0].second.second;
		cout<< activities[0].first <<" ";

		int i=1;
		while(i<n){
			if(activities[i].second.first > end){
				cout<< activities[i].first <<" ";
				end = activities[i].second.second;
			}
			i++;
		}
		cout << endl;
	}
	return 0;
}