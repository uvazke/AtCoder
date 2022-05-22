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
    map<string, int> myMap;
    cin >> N;
    myfor(i,N){
        string s;
        cin >> s;
        if(myMap.find(s) == myMap.end()){
            myMap[s] = 1;
        }else{
            myMap[s]++;
        }
    }
    auto ptr = max_element(
        myMap.begin(), myMap.end(),
        [](const pair<string, int> &p1, const pair<string, int> &p2) {
            return p1.second < p2.second;
        });

    cout << ptr->first<< endl;
    return 0;
}