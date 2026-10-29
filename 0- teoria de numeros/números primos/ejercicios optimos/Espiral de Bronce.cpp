#include<bits/stdc++.h>
using namespace std;

int main(){
	
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	cout.setf(ios::fixed);cout.precision(0);
 
	int n;
	
	cin>>n;
	

	int mat[n + 1][n + 1], cont = 1;	
	
	int f_arr = 1, f_abaj = n, c_izq = 1, c_der = n;
	
		while(cont <= n * n && c_izq <= c_der && f_arr <= f_abaj){
		
			
		
			for(int i = c_izq; i <= c_der; i++){
				mat[f_arr][i] = cont++;
			}
			f_arr++;
			
			if(cont > n * n) break;
			
			for(int i = f_arr; i <= f_abaj; i++){
				mat[i][c_der] = cont++;
			}
			c_der--;
			
			if(cont > n * n) break;
			
			for(int i = c_der; i >= c_izq; i--){
				mat[f_abaj][i] = cont++;
			}
			f_abaj--;
			
			if(cont > n * n) break;
			
			for(int i = f_abaj; i >= f_arr; i--){
				mat[i][c_izq] = cont++;
			}
			c_izq++;
		}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout<<mat[i][j]<<' ';
		}
		cout<<'\n';
	}
}