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
    string s1, s2;
    cin >> s1;
    cin >> s2;
    int i,j;
    if((s1[0] == '#' && s2[1] == '#' && s1[1] == '.' && s2[0] == '.')||
    (s1[0] == '.' && s2[1] == '.' && s1[1] == '#' && s2[0] == '#')){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;

    return 0;
}