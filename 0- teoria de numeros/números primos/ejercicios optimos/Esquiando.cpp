#include <cstdio>

/*FILE *fin, *fout;*/

const int maxn = 100;
const int max = 10000;
const int way[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int v, m, n;
int map[maxn][maxn];
double speed[maxn][maxn], time[maxn][maxn];
struct {
    int x, y;
} que[max];
bool inque[maxn][maxn];

void init() {
    scanf("%d%d%d", &v, &m, &n);
    int i, j;
    long long/*_int64*/ power[51];
    power[0]=1;
    for (i = 1; i<51; i++) power[i] = power[i-1]<<1;
    for (i = 0; i<m; i++)
        for (j = 0; j<n; j++) {
            scanf("%d", &map[i][j]);
            time[i][j] = power[31];
        }
    speed[0][0] = v;
    for (i = 0; i<m; i++)
        for (j = 0; j<n; j++)
            if (map[i][j]>map[0][0])
                speed[i][j] = v/(double)power[map[i][j]-map[0][0]];
            else
                speed[i][j] = v*power[map[0][0]-map[i][j]];
    time[0][0] = 0;
}

void spfa() {
    int head = -1, tail = 0, i, tx, ty;
    double tem;
    que[0].x = 0;que[0].y = 0;
    inque[0][0] = true;
    while (head != tail) {
        if (++head == max) head=0;
        for (i = 0; i < 4; i++) {
            tx = que[head].x+way[i][0];
            ty = que[head].y+way[i][1];
            if (tx<0 || tx==m || ty<0 ||ty==n) continue;
            tem = time[que[head].x][que[head].y] + 1.0/speed[que[head].x][que[head].y];
            if (tem < time[tx][ty]) {
                time[tx][ty] = tem;
                if (!inque[tx][ty]) {
                    if (++tail == max) tail=0;
                    que[tail].x = tx;
		    que[tail].y = ty;
                    inque[tx][ty] = true;
                }
            }
        }
        inque[que[head].x][que[head].y] = false;
    }
}

void process() {
    spfa();
    printf("%.2lf\n", time[m-1][n-1]);
}

int main() {
    /*fin=fopen("cowski.in", "r");
    fout=fopen("cowski.out", "w");*/
    init();
    process();/*
    fclose(fin);
    fclose(fout);*/
    return 0;
}