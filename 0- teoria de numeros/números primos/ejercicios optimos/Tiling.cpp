/*
 * Tiling (pero con matrices :p)
 * author: k4r3l_dev
 */
#include <stdio.h>
#define ll long long
#define MOD 1000000007

namespace competitive{
    template<int M, int N>
    struct Matrix{
        ll mat[M][N];
        
        template<int K>
        Matrix<M, K> operator*(Matrix<N, K> other){
            Matrix<M, K> result;
            
            for(int i = 0; i<M; i++){
                for(int j = 0; j<K; j++){
                    result.mat[i][j]=0;
                    for(int k = 0; k<N; k++){
                        result.mat[i][j] += mat[i][k]*other.mat[k][j];
                    }
                    result.mat[i][j]%=MOD;
                }
            }
            
            return result;
        }
    };
    
    template<int N>
    Matrix<N, N> matunit(){
        Matrix<N, N> res;
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                res.mat[i][j]= (i==j)?1:0;
            }
        }
        return res;
    }
}
using namespace competitive;

/* Binpow */
template<int N>
Matrix<N, N> matbp(Matrix<N,N> base, long long exp){
    if(exp==0)return competitive::matunit<N>();
    else if(exp==1) return base;
    
    auto res = matbp(base, exp>>1);
    res = res*res;
    
    if(exp&1) res = res*base;
    
    return res;
}

/*
 * Metodo principal
 */
int main() {
    int n; scanf("%d", &n);
    
    Matrix<16, 16> base{{
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
        {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
        {0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0},
        {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
        {0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0},
        {1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1},
    }};
    
    Matrix<16, 1> final{{
        {0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{1}
    }};
    
    //auto res = matbp(base, n)*final;
    auto res = matbp(base, n)*final;
    printf("%lld", res.mat[15][0]);
}