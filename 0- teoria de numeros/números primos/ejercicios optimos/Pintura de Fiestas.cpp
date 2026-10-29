#include "stdio.h"

const int MAXR = 50005, MAXC = 17, MAXN = 4 * MAXR + 10;

int R, C, Q;
int am0[MAXC][MAXR];
char grid[MAXR][MAXC];

bool mark[MAXN];
int am[MAXN][MAXC];
int change[MAXN][MAXC];

inline void split(int at, int l, int r){
    mark[at] = false;
    for(int i = 1; i <= C; ++i){
        if(change[at][i] < 2){
            int got = am0[i][r] - am0[i][l];
            if (change[at][i] == 1)
            got = r - l - got;
            am[at][i] = got;
        }
    }
    if (l + 1 != r){
        mark[at * 2 + 1] = true;
        mark[at * 2 + 2] = true;
        
        for(int i = 1; i <= C; ++i){
            if (change[at][i] < 2){
                change[at * 2 + 1][i] = change[at][i];
                change[at * 2 + 2][i] = change[at][i];
                change[at][i] = 2;
            }
        }
    }
}

void update(int at, int l, int r, int nl, int nr, int cols[]){
    if(mark[at]){
		split(at, l, r);
	}
    if(l == nl && r == nr){
        mark[at] = true;
        
        for(int i = 1; i <= C; ++i){
            if(cols[i] < 2){
            	change[at][i] = cols[i];
			}
        }
        split(at, l, r);
        return;
    }
    int m = (l + r) / 2;
    if(nr <= m){
    	update(at * 2 + 1, l, m, nl, nr, cols);
	}  
    else if(m <= nl){
    	update(at * 2 + 2, m, r, nl, nr, cols);
	}
    else{
        update(at * 2 + 1, l, m, nl, m, cols);
        update(at * 2 + 2, m, r, m, nr, cols);
    }
    if(mark[at * 2 + 1]){
    	split(at * 2 + 1, l, m);
	}
    if(mark[at * 2 + 2]){
    	split(at * 2 + 2, m, r);
	}
    for(int i = 1; i <= C; ++i){
		am[at][i] = am[at * 2 + 1][i] + am[at * 2 + 2][i];
	}
}

void read(){
    scanf("%d %d %d", &R, &C, &Q);
    
    for(int i = 0; i < R; ++i){
    	scanf("%s", grid[i]);
	}
}

void solve(){
    for(int i = 1; i <= C; ++i){
        for(int j = 1; j <= R; ++j){
            am0[i][j] = am0[i][j - 1];
            if(grid[j - 1][i - 1] == '0'){
                ++am0[i][j];
            }
        }
    }
    int cols[MAXC];
    for(int i = 0; i < MAXC; ++i){
    	cols[i] = 0;
	}
    update(0, 0, R, 0, R, cols);
    
	int r1, r2, c1, c2, x;
    
	if(mark[0]){
		split(0, 0, R);
	}
    for (int i = 0; i < Q; ++i){
    	
        scanf("%d %d %d %d %d", &r1, &r2, &c1, &c2, &x);
        
		for (int j = 0; j <= C; ++j){
            if(j >= c1 && j <= c2){
                cols[j] = x;
            }
            else{
                cols[j] = 2;
            }
        }
        update(0, 0, R, r1 - 1, r2, cols);
        
		if(mark[0]){
			split(0, 0, R);
		}
        int ans = 0;
        
        for(int i = 1; i <= C; ++i){
        	ans += am[0][i];
		}
		
        printf("%d\n", ans);
    }
}

int main(){
    read(); solve(); return 0;
}