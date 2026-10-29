#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include<string>
#include<algorithm>

string s;
ll k;

int main()
{
	fr
	cin>>s>>k;
	ll len = s.length();
	if(k == 0)
	{
		cout<<s<<endl;	return 0;
	}
	for(ll i=0;i<len&&k!=0;i++)
	{
		ll ind = i;
		for(ll j=i;j<=min(i+k, len-1); j++)
			if(s[j] > s[ind])
				ind = j;
		for(ll j=ind;j>i;j--)
		{
			swap(s[j], s[j-1]);
			k--;	
		}		
	}
	cout<<s<<endl;
	return 0;
}
