#include<stdio.h>
#include<cstdint>
#include"vector"
#include"algorithm"
using namespace std;
#define int long long

int32_t main()
{
	int N,Val;
	scanf("%lld",&N);
	vector<int> Arr;
	for(int i=0;i<N;i++){
	   scanf("%lld",&Val) ;
	   Arr.push_back(Val);
	}
	Arr.push_back(1e9+2);
	 //   sort(Arr.begin(),Arr.end());
	    int sol=N,cont=1;
	    for(int i=0;i<N;i++){
	   //     printf("%d ",cont);
	        if(Arr[i]==Arr[i+1])cont++;
	        else{
	            sol+=(cont*(cont-1))/2;
	            cont=1;
	            }
	            
	    }
	            printf("%lld",sol);
	            
	        
	  return 0;  
}