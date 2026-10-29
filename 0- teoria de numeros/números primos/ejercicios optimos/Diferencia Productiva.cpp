#include<iostream>
#include<algorithm>
#define ENDL '\n'
using namespace std;

int n, k;
int arr[1000001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>k;
	
	for(int i=0; i<n; i++)cin>>arr[i];
	sort(arr, arr+n);
	
	int answer=1, j=0;
	for(int i=1; i<n; i++){
		while(arr[i]-arr[j]>k)j++;
		answer=max(answer, i-j+1);
	}
	
	cout<<answer;
	
	return 0;
}