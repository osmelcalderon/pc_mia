//!----LIBRERIAS---------------------------------------------------------------------------------------
#include <iostream>
//#include <vector>
#include <algorithm>
//#include <math.h>
//#include <memory.h>
#include <set>
//#include <map>
//#include <queue>
//#include <stack>
//#include <string>

//!----MACROS------------------------------------------------------------------------------------------
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rloop(k,a,b) for(int k=a;k>b;k--)
#define vvi vector<vector<int>>
#define vii vector<vector<pair<int,int>>>
#define vi vector <int>
#define ii pair <int,int>
#define pb(a) push_back(a)
#define mk(a,b) make_pair(a,b)
#define all(x) x.begin(),x.end()
#define sz(x) ((x).size())
#define sza(x) sizeof(x)/sizeof(x[0])
#define fi first
#define se second
#define mid (l+r)/2
#define left node*2,l,mid
#define right node*2+1,mid+1,r
#define mset(a,b) memset(a,b,sizeof(a))
#define IOS_B ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int mod = 1e9 + 7;


using namespace std;
//!----Globales----------------------------------------------------------------------------------------

bool vis[105];

//!----FUNCIONES---------------------------------------------------------------------------------------



//!----MAIN--------------------------------------------------------------------------------------------
int main(){
IOS_B;

	int n, c=0;
	cin>>n;
	multiset <ii> kit;
	
	int array[n+2];
	
	array[0] = array[n+1] = mod;
	
	loop(i,1,n+1){
		cin>>array[i];
	}
	
	sort(array+1,array+n+1);
	
	for(int i=1; i<=n; ++i){
			int a = min(abs(array[i]-array[i-1]),abs(array[i]-array[i+1]));
			kit.insert(mk(a,i));
	}
	
	while(!kit.empty()){
		ii y = *kit.rbegin();
		int x = y.se;
		kit.erase(kit.find(y));
		c++;
		while(!vis[x]){
			vis[x] = 1;
			if(abs(array[x-1] - array[x]) <= abs(array[x+1] - array[x])){
				x--;
				int a = min(abs(array[x-1] - array[x]),abs(array[x+1] - array[x]));
				if(vis[x] == 0)
					kit.erase(kit.find(mk(a,x)));
				}
			else{
				x++;
				int a = min(abs(array[x-1] - array[x]),abs(array[x+1] - array[x]));
					if(vis[x] == 0)
				kit.erase(kit.find(mk(a,x)));
				}	
			}
		}
		
		cout<<c<<"\n";

	return 0;
}