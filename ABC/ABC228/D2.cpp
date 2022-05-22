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
    long t, x;
    map<int, int> spans;
    int i, j, Q;
    const int n = 1048576;
    spans[n] = 0;
    cin >> Q;
    myfor(i, n) { 
        a[i] = -1;
    }
    myfor(i, Q) {
        cin >> t;
        cin >> x;
        int index = x % n;
        if(t == 2){
            cout << a[index] << endl;
            continue;
        }

        auto itr = spans.upper_bound(index);
        if(itr == end(spans)){
            index = 0;
            itr = begin(spans);
        }

        if(itr->second <= index) {
            a[index] = x;
            int l1 = itr->second, r1 = index, l2 = index + 1, r2 = itr->first;
            spans.erase(itr);
            if(l1 != r1){
                spans[r1] = l1;
            }
            if(l2 != r2){
                spans[r2] = l2;
            }
        }else{
            a[itr->second] = x;
            itr->second++;
            if(itr->first == itr->second){
                spans.erase(itr);
            }
        }
        
    }

    return 0;
}