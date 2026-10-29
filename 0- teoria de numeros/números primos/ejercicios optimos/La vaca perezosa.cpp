// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define patkan 9
#define tisic 47
#define soclose 1e-9
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
#include <time.h>
// mylittlepony
using namespace std;

struct weed {
	int x,y,G;

	bool operator<(const weed &A) const {
		return x < A.x;}
	};

struct node {
	int z,k;
	int son[2];
	int mod,val;};

struct intervalac {
	vector<node> T;

	void constI(int akt) {
		node n =T[akt];
		if(n.z == n.k-1) return;
		for(int i =0; i < 2; i++) {
			if(i == 0) n.k =(n.k+n.z)/2;
			else {n.z =n.k; n.k =T[akt].k;}
			T[akt].son[i] =T.size();
			T.push_back(n);
			constI(T[akt].son[i]);}
		}

	intervalac(int N) {
		T.dibs(2*N);
		node n;
		n.son[0] =n.son[1] =-1;
		n.val =n.mod =0;
		n.z =0, n.k =N;
		T.push_back(n);
		constI(0);}

	void upd(int akt) {
		node n =T[akt];
		if(n.mod == 0) return;
		for(int i =0; i < 2; i++) if(n.son[i] != -1)
			T[n.son[i]].mod +=n.mod;
		T[akt].val +=n.mod;
		T[akt].mod =0;}

	void add(int akt, int zac, int kon, int val) {

		upd(akt);
		node n =T[akt];
		if(n.z >= kon || zac >= n.k) return;
		if(n.z == zac && n.k == kon) {
			T[akt].mod +=val;
			upd(akt);
			return;}
		add(n.son[0],zac,min(kon,T[n.son[0]].k),val);
		add(n.son[1],max(zac,T[n.son[1]].z),kon,val);
		upd(akt);
		T[akt].val =max(T[n.son[0]].val,T[n.son[1]].val);}

	int get() {
		upd(0);
		return T[0].val;}
	};

int main() {

	int N,K;
	scanf(" %d %d",&N,&K);
	vector<weed> A(N);
	for(int i =0; i < N; i++) {
		int x,y;
		scanf(" %d %d %d",&A[i].G,&x,&y);
		A[i].x =x+y;
		A[i].y =x-y+1000000;}
	sort(A.begin(),A.end());

	map<int,int> C;
	for(int i =0; i < N; i++) {
		C[A[i].y-K] =0;
		C[A[i].y+K] =0;}
	int a =0;
	for(map<int,int>::iterator it =C.begin(); it != C.end(); it++) it->ss =a++;

	intervalac I(a+tisic);
	int ans =0, b =0;

	for(int i =0; i < N; i++) {
		I.add(0,max(0,C[A[i].y-K]),min(a+patkan,C[A[i].y+K]+1),A[i].G);
		while(b < N && A[b].x < A[i].x-2*K) {
			I.add(0,max(0,C[A[b].y-K]),min(a+patkan,C[A[b].y+K]+1),-A[b].G);
			b++;}
		ans =max(ans,I.get());}
	printf("%d\n",ans);
	return 0;}