 		#include <bits/stdc++.h>

		using namespace std;

		bool compareFunction(pair<int,int>  a,pair<int,int> b){
			return a.second>b.second;
		}

		int main(){
			int t;cin >> t;
			while(t--){

				int n; cin >> n;

				vector<pair<int,int> > activities(n);
				int inp;
				for(int i=0;i<n;i++){
					cin>> inp >> activities[i].first  >> activities[i].second;
				}

				sort(activities.begin(),activities.end(),compareFunction);
				bool slotFilled[n]={};
				int act=0;
				long long int profit=0;
				int i=0;
				cout << "\nActivities chosen are:\n";
				for(int i=0;i<activities.size();i++){
					for(int j= min(activities[i].first,n)-1;j>-1;j--){
						if(slotFilled[j]==false){
							slotFilled[j]=true;
							act++;
							cout << setw(5)<<activities[i].first<<","<<activities[i].second<<endl;
							profit+=activities[i].second;
							break;
						}	
					}
				}

				cout<<"Maximum no of activities are: "<< act <<"\nMaximum profit is: "<< profit<<endl;

			}


			return 0;
		}