#include <bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
	
	ios;
	
	int n;
	cin>>n;
	string mat[n];
	
	for(int i=0;i<n;i++)cin>>mat[i];
	
	int ch=0;
	int cv=0;
	int cd=0;
	
	bool res=0;
	
	for(int i=0;i<n&&!res;i++){
		ch=0;
		for(int j=0;j<6;j++){
			if(mat[i][j]=='#')ch++;
		}
		if(ch>=4)res=1;
		for(int j=6;j<n&&!res;j++){
			if(mat[i][j]=='#')ch++;
			if(mat[i][j-6]=='#')ch--;
			if(ch>=4)res=1;
		}
	}
	
	for(int i=0;i<n&&!res;i++){
		cv=0;
		for(int j=0;j<6;j++){
			if(mat[j][i]=='#')cv++;
		}
		if(cv>=4)res=1;
		for(int j=6;j<n&&!res;j++){
			if(mat[j][i]=='#')cv++;
			if(mat[j-6][i]=='#')cv--;
			if(cv>=4)res=1;
		}
	}
	
	for(int i=5;i<n&&!res;i++){
		cd=0;
		
		for(int j=0;j<6;j++)if(mat[i-j][j]=='#')cd++;
		if(cd>=4)res=1;
		for(int j=6;j<=i&&!res;j++){
  			if(mat[i-j][j]=='#')cd++;
			if(mat[i-j+6][j-6]=='#')cd--;
			if(cd>=4)res=1;
		}
	}
	
	for(int i=1;i<=n-6&&!res;i++){
		cd=0;
		
		for(int j=0;j<6;j++){
			if(mat[i+j][n-1-j]=='#')cd++;
		}
		if(cd>=4)res=1;
		for(int j=6;j<n-i&&!res;j++){
  			if(mat[i+j][n-1-j]=='#')cd++;
			if(mat[i+j-6][n-1-j+6]=='#')cd--;
			if(cd>=4)res=1;
		}
	}
	
	for(int i=5;i<n&&!res;i++){
		cd=0;
		
		for(int j=0;j<6;j++){
			if(mat[i-j][i-j+(n-i-1)]=='#')cd++;
		}
		if(cd>=4)res=1;
		for(int j=6;j<=i&&!res;j++){
  			if(mat[i-j][i-j+(n-i-1)]=='#')cd++;
			if(mat[i-j+6][i-j+(n-i-1)+6]=='#')cd--;
			if(cd>=4)res=1;
		}
	}
	
	if(res==1)cout<<"Yes";
	else cout<<"No";
	
	return 0;
}