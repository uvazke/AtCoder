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
    int N, M, b[7],bPrevBase=-1,i,j;
    cin >> N >> M;
    myfor(i,N){
        myfor(j, M) { 
            cin >> b[j];
        }
        myfor(j, M-1) { 
            if(b[j]%7 == 0 || b[j] + 1 != b[j+1]){
                cout << "No" << endl;
                return 0;
            }
        }
        if(bPrevBase == -1){
            bPrevBase = b[0];
            continue;
        }
        if(b[0] != bPrevBase + 7){
            cout << "No" << endl;
            return 0;
        }
        bPrevBase = b[0];
    }
    cout << "Yes" << endl;
    return 0;
}