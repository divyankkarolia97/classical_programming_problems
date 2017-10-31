//Provide the number of testcases 't' and for evry test case
// input 'n' size of the array and then the n array elements

#include <bits/stdc++.h>

using namespace std;

int longestIncreasingSubsequence(vector<int> v,vector<int> &dp,int index){
	if(index == 0){
		return dp[0]=1;
	}
	if(dp[index]!=-1){
		return dp[index];
	}

	int maxSeq=1;

	for(int i=index-1;i>-1;i--){
		if(v[i]<v[index])
			maxSeq = max(maxSeq,1+longestIncreasingSubsequence(v,dp,i));
	}
	return dp[index]=maxSeq;


}


int main(){
	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		vector<int> v(n);

		for(int i=0;i<n;i++){
			cin >> v[i];
		}
		vector<int> dp(n,-1);

		//again and again so called so that LIS is found for every element in the input array
		for(int i=n-1;i>-1;i--){
			if(dp[i]==-1){
				longestIncreasingSubsequence(v,dp,i);
			}
		}
		
		//finally finding the length of LIS
		int max=-1;
		for(int i=0;i<n;i++){
			if(max<dp[i])
				max= dp[i];
		}

		cout<< max <<endl;
	}
	return 0;
}