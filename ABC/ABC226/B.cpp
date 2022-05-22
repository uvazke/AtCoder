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
    int N,i;
    map<string,int> myMap;
    cin >> N;
    myfor(i, N) {
        string str;
        getline(cin >> ws, str);
        if(myMap.count(str) == 0) {
            myMap[str] = 1;
        }
    }
    cout << myMap.size()<< endl;
    return 0;
}