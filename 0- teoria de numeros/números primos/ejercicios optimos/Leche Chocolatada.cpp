#include <bits/stdc++.h>

	using namespace std;
	 
	int n, in[100000], out[100000], nxt[100000];
	 
	int main() {
	//ifstream fin("chocmilk.in");
	    cin >> n;
	    for (int i = 1; i < n; i++) {
	        int a, b;
	        cin >> a >> b;
	        nxt[a-1] = b-1;
	        out[a-1]++;
	        in[b-1]++;
	    }
	    //fin.close();
	 
	    // find the first main joint
	    int s = -1;
	    for (int i = 0, val = -1; i < n; i++) {
	            // if the current node is the highest reachable node upto now
	            //   and the main joint is not initialized or it is a merging joint,
	            //     keep it as a candidate for the first main joint
	            if (val == i && (s < 0 || in[i] > 1)) s=i;
	 
	            // if the node splitting joint or a tank, finish searching
	            if (out[i] != 1) break;
	 
	            // update the highest reachable node upto now
	            val = max (val, nxt[i]);
	    }
	 
	    //ofstream fout("chocmilk.out");
	    for (int i = s; i < n; i = nxt[i]) {
	            cout << i+1 << "\n";
	            if (out[i] !=1 ) break;
	    }
	    //fout.close ();
	}