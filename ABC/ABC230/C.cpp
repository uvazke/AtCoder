
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
    long N,A,B,P,Q,R,S;
    cin >> N >> A >> B;
    cin >> P >> Q >> R >> S;
    long i, j;
    myforFL(i,P,Q+1){
        myforFL(j,R,S+1){
            if((i-A == j-B)||(i-A == B-j)){
                cout << "#";
                continue;
            }
            cout << ".";
        }
        cout << endl;
    }
    return 0;
}