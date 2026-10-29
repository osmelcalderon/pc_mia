// Ah shit,here we go again
// o_o

// --> Copyright DMOJ
// --> Alí
// --> IPVCE Federico Engels
// --> 10mo grado


#include "stdio.h"
#include "algorithm"
#include "cstring"
#include "vector"
#include "map"
#include "queue"
#include "set"
#include "stack"
#include "cmath"
#include "climits"
#include "array"
#include "iostream"
#include "bitset"
#include "set"
#include "stdlib.h"

using std::cin;    using std::queue;
using std::cout;   using std::stack;
using std::vector; using std::map;
using std::string; using std::set;
using std::sort;   using std::endl;
using std::ios;    using std::array;
using std::pair;   using std::priority_queue;

// ---------------------------------------------------------

/* // --- Atajos Basicos --- \\ */

#define fast() ios::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define ull unsigned long long
#define li long int
#define lli long long int
#define pi 3.14

/* // --- Atajos Contenedores --- \\ */

#define vec vector<int>
#define vec_vec vector<vector<int,int>>
#define vec_pr vector<pair<int,int>>
#define vec_mp vector<map<int,int>>
#define pr pair<int,int>
#define mp map<int,int>
#define qqe queue<pair<int,int>>
#define pqe priority_queue<pair<int,int>>

/* // --- Atajos STL --- \\ */

#define pb push_back
#define eb emplace_back
#define sz size
#define szf sizeof
#define mst memset
#define vec_order(x) sort(x.begin(),x.end())
#define arr_order(x,n) sort(x,x+n)
#define all(x) (x.begin(),x.end())

/* // --- Atajos Entradas/Salidas --- \\ */

#define isf(x) scanf("%d",&x)
#define isff(x,y) scanf("%d%d",&x,&y)
#define sf(x) scanf("%s",&x)
#define cf(x) scanf("%c",&x)
#define pf(x) printf("%d",&x)

// ---------------------------------------------------------

const int mxn = 1e5 + 10;
const int mod = 1e9 + 7;

int arr[mxn],dist[mxn],n,m,c,a,b; bool mk[mxn];

mp values[5];

bool cmp(int a,int b){
	int ans = 0;
	
	for(int i=0;i<5;i++){
		ans += values[i][a] < values[i][b];
	}
	
	return ans > 2;
}

int main(){
	fast();
	
	int n; cin>>n;
	
	for(int i=0;i<5;i++){
		for(int j=0;j<n;j++){
			int x; cin>>x;
			
			values[i][x] = j;
			arr[j] = x;
		}
	}
	
	sort(arr,arr + n,cmp);
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<'\n';
	}
}