#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int x, y;
} Point;

Point queue[MAX*MAX];
int front = 0, rear = -1;

int farm[MAX][MAX] = {0};
int visited[MAX][MAX] = {0};

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void enqueue(Point p) {
    queue[++rear] = p;
}

Point dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

int isInside(int x, int y, int N, int M) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int BFS(Point src, int N, int M) {
    visited[src.x][src.y] = 1;
    enqueue(src);

    int cnt = 0;
    while (!isEmpty()) {
        Point curr = dequeue();
        cnt++;

        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i], ny = curr.y + dy[i];

            if (isInside(nx, ny, N, M) && farm[nx][ny] && !visited[nx][ny]) {
                visited[nx][ny] = 1;
                enqueue((Point){nx, ny});
            }
        }
    }

    return cnt;
}

int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);

    for (int i = 0; i < K; i++) {
        int R, C;
        scanf("%d %d", &R, &C);
        farm[R-1][C-1] = 1;
    }

    int maxLakeSize = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (farm[i][j] && !visited[i][j]) {
                int lakeSize = BFS((Point){i, j}, N, M);
                if (lakeSize > maxLakeSize)
                    maxLakeSize = lakeSize;
            }
        }
    }

    printf("%d\n", maxLakeSize);

    return 0;
}