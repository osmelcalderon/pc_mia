#include<stdio.h>
#include<algorithm>
using namespace std;
 
#define mod 1000000009;

const int mxn = 100005; 
 
int A[mxn],tree[mxn];
int P, psums[mxn];
 
inline int search(int val){
    return lower_bound (psums, psums + P, val) - psums;
}
 
inline int query(int x){
    int sum = 0;
 
    for (int i=x+1;i>0;i-=i&-i){
    	sum=(sum + tree[i]) % mod;
	}
    return sum;
}
 
inline void update (int x, int val){
    for(int i=x+1;i<=P;i+=i&-i){
    	tree[i]=(tree[i]+val)%mod;	
	}
}
 
int main (){
	
	int n; scanf ("%d", &n); psums[0]=0;
 
    for(int i=0;i<n;i++){
        scanf("%d",A+i); psums[i+1]=psums[i]+A[i];
    }
    P=n+1; sort(psums,psums+P);
    
    P=unique(psums,psums+P)-psums; update(search(0),1);
    int dp, sum=0;
 
    for(int i=0;i<n;i++){
        sum+=A[i];
        dp=query(search(sum)); update(search(sum),dp);
    }
    
    printf ("%d\n", dp);
    
}