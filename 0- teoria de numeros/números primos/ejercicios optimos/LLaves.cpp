#include <bits/stdc++.h>
using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int l,k;
	string s;
	cin>>l>>k>>s;
	int pos=0;
	while(k){
		int p,num=-1;
		for(int i=pos;i<=pos+k&&num!=9;i++){
			if(s[i]-'0'>num){num=s[i]-'0';p=i;}
		}
		cout<<s[p];
		k-=p-pos;
		pos=p+1;
	}
	for(int i=pos;i<l;i++)cout<<s[i];
	return 0;
}