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
    string S;
    cin >> S;
    string pattern = "oxxoxxoxxoxx";
    if(pattern.find(S) == string::npos){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}