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
vector<pair<long, long>> GetPrimeNumbers(long N){
    long i;
    vector<pair<long, long>> vec;
    myforFL(i, 2, floor(sqrt(N)) + 1) {
        if(N%i != 0){
            continue;
        }
        long count =0;
        while(N % i == 0) {
            count++;
            N /= i;
        }
        pair<long, long> p(i, count);
        vec.push_back(p);
    }
    return vec;
}

long GetPrimeNumbersCount(long N){
    long i;
    long count = 0;
    myforFL(i, 2, floor(sqrt(N)) + 1) {
        if(N%i != 0){
            continue;
        }
        while(N % i == 0) {
            count++;
            N /= i;
        }
    }
    return count;
}

int main() {
    int N;
    cin >> N;
    auto count = GetPrimeNumbersCount(N);
    int i;
    long ans = 0;
    myfor(i, count) { ans += (long)tgammal(count + 3) / 6; }
    cout << ans << endl;
    return 0;
}