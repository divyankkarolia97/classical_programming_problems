#include <bits/stdc++.h>

using namespace std;

int minCoinChange(vector<int> &v,vector<int> &dp,int value){
	if(value==0) return 0;
	if(dp[value]!=-1) return dp[value];

	int result = 100000;

	for(int i=0;i<v.size();i++){
		if(value-v[i]>=0){
			result = min(result,1+minCoinChange(v,dp,value-v[i]));
		}
	}
	return dp[value] = result;


}


int main(){
	int t;cin >> t;

	while(t--){
		int n;cin >> n;
		vector<int> v(n);

		for(int i=0;i<n;i++){
			cin >> v[i];
		}

		int value;cin >> value;
		
		vector<int> dp(value+1,-1);
		cout << minCoinChange(v,dp,value)<<endl;

	}
	return 0;
}