#include <bits/stdc++.h>

using namespace std;
int cou=0;
//function to check if the queen can be placed at visited[row][column]
bool check(bool visited[][8],int row,int column){

	//row check
		for(int i=0;i<8;i++){
			if(visited[i][column] == true){
				return false;
			}
		}

	//column check

		for(int i=0;i<8;i++){
			if(visited[row][i] == true){
				return false;
			}
		}
	//diagonal check
	
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				if(column-row == j-i){
					if(visited[i][j]==true)
						return false;
				}
				if(column+row == j+i)
					if(visited[i][j]==true)
						return false;
			}
		}	
		return true;
}

bool recursion(bool visited[][8],int row){
	
	//base case if all the 8 queens are placed
	if(row == 8){
		cou++;	 
		cout << cou << endl;
		//print the current board configuration and continue
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				cout << visited[i][j]<<" ";
			}
			cout << endl;
		}
		cout <<endl;
		return false;
	}

			for(int column=0;column<8;column++){
			
			if(check(visited,row,column)){
				//mark the current row column as true
				visited[row][column]=true;
				
				bool flag =recursion(visited,row+1);
				
				//couldnt place anywhere in the next row hence returns false
				if(flag == false){
					visited[row][column]=false;
				}
			}
			

		}
		return false;
}

int main(){
	bool visited[8][8]={};
	bool result = recursion(visited,0);
	
	return 0;
}