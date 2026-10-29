#include<bits/stdc++.h>
using namespace std;
int main(){
    int P, resp = 0;
    scanf("%d", &P);
    for (int i = ceil((double)P/(double)2) - 1, x; 3*i >= P; i--){
        x = P - 2*i;
        resp += (i - x)/2;
        resp++;
    }
    printf("%d", resp);
    return 0;
}