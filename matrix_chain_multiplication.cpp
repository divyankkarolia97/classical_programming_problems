#include <bits/stdc++.h>

using namespace std;

int minChainMultiplication(vector<int> v,vector<vector<int> > & dp,int l,int r){
	if(l+1==r){
		return 0;
	}
	if(dp[l][r]!=-1){
		return dp[l][r];
	}
	int result = INT_MAX;
	for(int i=l+1;i<r;i++){
		int tempRes = v[l]*v[i]*v[r]+minChainMultiplication(v,dp,l,i)+minChainMultiplication(v,dp,i,r);
		if(tempRes<result){
			result=tempRes;
		}
	}
	return dp[l][r] = result;
}


int main(){

	int t;cin >>t;
	while(t--){
		int n;cin >> n;
		n--;
		vector<int> v(n+1);

		for(int i=0;i<n+1;i++){
			cin >> v[i];
		}
		vector<vector<int> > dp(n+1,vector<int>(n+1,-1));

		cout << minChainMultiplication(v,dp,0,n)<<endl;
	}
	return 0;
}