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
    long A, B;
    cin >> A >> B;
    while(A != 0 && B != 0) {
        auto A1 = A % 10;
        auto B1 = B % 10;
        if(A1+B1 >= 10){
            cout << "Hard" << endl;
            return 0;
        }

        A /= 10;
        B /= 10;
    }
    cout << "Easy" << endl;
    return 0;
}