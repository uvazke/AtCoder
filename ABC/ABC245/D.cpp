#include <algorithm>
#include <float.h>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <vector>
#define myfor(i, N) for (i = 0; i < N; i++)
#define myforFL(i, f, l) for (i = f; i < l; i++)
#define myforInv(i, N) for (i = N; i >= 0; i--)
#define myforFLInv(i, f, l) for (i = f; i > l; i--)
using namespace std;

int main() {
    int N, M,A[101],B[101],C[201];
    cin >> N >> M;
    int i;
    myfor(i, N+1) { cin >> A[i]; }
    myfor(i, N+M+1) { cin >> C[i]; }

    myfor(i, M+1) {
        int k;
        int sum = 0;
        myforFL(k, 1, i+1) { 
            if(N >= k && M + k >=i && M- i+ k <= M ){
                sum += A[N - k] * B[M - i + k];             
            }            
        }
        B[M - i] = (C[N + M - i] - sum) / A[N];
    }
    myfor(i, M) { cout << B[i] << " "; }
    cout  << B[M]<< endl;
    return 0;
}