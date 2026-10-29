#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    
    int a[n], b[n];
    int x;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        a[i] = x;
        b[i] = x;
    }

    sort(a, a+n);
    int cnt = 0;
    for(int i = 0; i < n; i++){
    	if(a[i] != b[i])cnt++;
    }

    int result;

    if(cnt == 0)result = 0;
    else if(cnt == 2)result = 1;
    else result = -1;
    

    printf("%d\n", result);

    return 0;
}