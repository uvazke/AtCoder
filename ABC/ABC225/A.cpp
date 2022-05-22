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
    string s;
    cin >> s;
    if(s[0] == s[1] && s[0] == s[2]){
        cout << 1 << endl;
        return 0;
    }
    if(s[0] == s[1] || s[0] == s[2] || s[1] == s[2]){
        cout << 3 << endl;
        return 0;
    }
    cout << 6 << endl;
    return 0;
}