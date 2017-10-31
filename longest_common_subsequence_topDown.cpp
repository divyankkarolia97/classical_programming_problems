#include <bits/stdc++.h>

using namespace std;

int longestCommonSubsequence(string s1,string s2,vector<vector<int> > &dp,int index1,int index2){
	if(index1<0 || index2<0) return 0;
	if(dp[index1][index2]!=-1) return dp[index1][index2];

	if(s1[index1]==s2[index2]){
		return dp[index1][index2]= 1+longestCommonSubsequence(s1,s2,dp,index1-1,index2-1);
	}
	else{
		return dp[index1][index2] = max(longestCommonSubsequence(s1,s2,dp,index1-1,index2),longestCommonSubsequence(s1,s2,dp,index1,index2-1));
	}	

}
void printLongestCommonSubsequence(string s1,string s2,vector<vector<int> > dp,int l1,int l2){
	stack<char> s;
	while(l1>-1 && l2>-1){
		if(s1[l1]==s2[l2]){
			s.push(s1[l1]);
			l1--;l2--;
		}else{
			if(dp[l1-1][l2]>dp[l1][l2-1]){
				l1--;
			}else{
				l2--;
			}

		}

	}
	while(s.empty()==false){
		cout << s.top();s.pop();
	}
	cout <<endl;

}


int main(){
	string s1,s2;cin >> s1 >> s2;
	int l1=s1.size(),l2=s2.size();
	vector<vector<int> > dp(l1,vector<int>(l2,-1)); 
	cout << longestCommonSubsequence(s1,s2,dp,l1-1,l2-1)<<endl;
	printLongestCommonSubsequence(s1,s2,dp,l1-1,l2-1);
	return 0;
}
