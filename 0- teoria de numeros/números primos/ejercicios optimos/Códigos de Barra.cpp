#include<stdio.h>
#define ll long long
#define MOD 1000000007

template <int M, int N>
struct Matrix{
    unsigned long long mat[M][N];

    template<int K>
    Matrix<M, K> operator*(Matrix<N, K> &other){
        Matrix<M, K> result;
        for(int i = 0; i<M; i++)
            for(int j = 0; j<K; j++){
                result.mat[i][j]=0;
                for(int k = 0; k<N; k++){
                    result.mat[i][j] += (this->mat[i][k]*other.mat[k][j])%MOD;
                }
                result.mat[i][j] %= MOD;
            }
        return result;
    }

    Matrix<M, N> unit(){
        static_assert(M==N, "Must be a sqare matrix");
        Matrix<M, N> mat;
        for(int i = 0; i<M; i++)
            for(int j = 0; j<M; j++){
                mat.mat[i][j] = i==j ? 1 : 0;
            }
        return mat;
    }
};

template <int K>
Matrix<K, K> binpow(Matrix<K, K> b, unsigned long long exp){
    if(exp==0)return b.unit();
    else if(exp==1)return b;
    auto res = binpow(b, exp>>1);
    res = res*res;
    if(exp&1)res = res*b;
    return res;
}

template <int M, int N> void printmat(Matrix<M, N> mat){
    for(int i = 0; i<M; i++){
        for(int j = 0; j<N; j++)
            printf("%lld ", mat.mat[i][j]);
        printf("\n");
    }
}

int main(){
    
    Matrix<4, 4> a{{
        {0,1,0,1},
        {1,0,1,0},
        {1,0,0,0},
        {0,1,0,0}
    }};
    Matrix<4,1> b{{
        {1},
        {0},
        {0},
        {1}
    }};

    int n; scanf("%d", &n);

    if(n<3){
        printf("1");
        return 0;
    }

    auto res = binpow(a, n-3)*b;
    long long sol = 0;
    sol+=res.mat[0][0];
    sol+=res.mat[1][0];
    sol+=res.mat[2][0];

    printf("%lld", sol%MOD );

    return 0;
}