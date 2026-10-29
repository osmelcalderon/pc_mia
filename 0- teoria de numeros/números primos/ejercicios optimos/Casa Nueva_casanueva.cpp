#include<stdio.h>


#define Hd main(void)
int min(int a,int b){
    return (a>b? b:a);
}
int max(int a,int b){
    return (a<b? b:a);
}
int solve(){
    int n;
    scanf("%d",&n);
    char s[n][n];
    for(int i=0;i<n;i++){
        scanf("%s",s[i]);
    }
    int mz = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(s[i][j] == '.'){
                for(int siz=1;siz<=min(n-i,n-j);siz++){
                    int f = 1;
                    for(int x=i;x<i+siz;x++){
                        for(int y=j;y<j+siz;y++){
                            if(x>=n || y>=n || s[x][y] == '#'){
                                f = 0;
                                break;
                            }
                        }
                        if(!f){
                            break;
                        }
                    }
                    if(f){
                        mz = max(mz,siz);
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }
    return mz;
}

Hd{
    int t;
    scanf("%d",&t);
    while(t--){
        int ans = solve();
        printf("%d\n",ans);
    }
}
