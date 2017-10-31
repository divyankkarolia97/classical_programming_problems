#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;cin >> t;
	while(t--){
		int n;cin >> n;

		vector<int> v(n);
		for(int i=0;i<n;i++){
			cin >> v[i];
		}

		vector<int> dp(n,1);

		for(int i=0;i<n;i++){
			
			for(int j=i-1;j>-1;j--){
				if(v[j]<v[i]){
					dp[i]=max(dp[i],1+dp[j]);
				}
			}

		}

		cout << dp[n-1]<<endl;


	}
	return 0;
}