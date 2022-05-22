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

long a[1048576];
int main() {
    int N;
    cin >> N;
    if(N >= 42){
        N++;
    }
    if(N >= 10){
        cout << "AGC0" << N << endl;
        return 0;
    }
    cout << "AGC00" << N << endl;
    return 0;
}