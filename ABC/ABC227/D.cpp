#include <algorithm>
#include <deque>
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
    int N, K;
    cin >> N >> K;
    int i;
    vector<long long> A;
    myfor(i, N) {
        long long a;
        cin >> a;
        A.push_back(a);
    }
    long long maximum = (2*1e17)*2/K;
    long long minimum = 0;
    while(maximum - minimum > 1){
        long long half = (maximum + minimum) / 2;
        long long sum = 0;
        for(long long x : A) {
            sum += min(half, x);
        }
        if(sum >= half*K){
            minimum = half;
        }else{
            maximum = half;
        }
    }

    cout << minimum << endl;
    return 0;
}