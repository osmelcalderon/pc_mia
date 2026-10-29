#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<math.h>
#define ENDL '\n'
#define MAXN 100501
using namespace std;
typedef long long ll;

vector<int>primes;
bool mark[MAXN];

inline void criba(){
	primes.push_back(2);
	for(int i=3; i<MAXN; i+=2){
		if(!mark[i]){
			mark[i]=true;
			primes.push_back(i);
			if(i<=sqrt(MAXN-1)+1)
			for(int j=i*i; j<MAXN; j+=i)
			mark[j]=true;
		}
	}
}

int main(){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		
		criba();
		
		int n, m;
		cin>>n>>m;
		
		int aux=0;
		vector<int>next_prime(MAXN);
		for(int i=1; i<MAXN; i++){
			for(int j=aux; j<primes.size(); j++){
				if(primes[j]>=i){
					aux=j;
					break;
				}
			}
			next_prime[i]=primes[aux];
		}
		
		int matrix[n][m];
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin>>matrix[i][j];
				matrix[i][j]=next_prime[matrix[i][j]]-matrix[i][j];
					//cout<<matrix[i][j]<<ENDL;
			}
		}
		
	//for(int i=1; i<=100; i++)cout<<next_prime[i]<<ENDL;
		
		
		int answer=INT_MAX;
		for(int j=0; j<m; j++){
			int sum=0;
			for(int i=0; i<n; i++){
				sum+=matrix[i][j];
			}
			answer=min(answer, sum);
		}
		
		for(int i=0; i<n; i++){
				int sum=0;
				for(int j=0; j<m; j++){
					sum+=matrix[i][j];
				}
				answer=min(answer, sum);
		}
		
		cout<<answer;
					
				
		
		return 0;
}