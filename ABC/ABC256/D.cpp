#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <map>
#define myfor(i,N) for(i=0;i<N;i++)
#define myforFL(i,f,l) for(i=f;i<l;i++)
#define ll long long
using namespace std;

int main(void) {
    int N;
    cin >> N;
    map<int,int> myMap;
    int i;
    myfor(i, N) {
        int l, r;
        cin >> l >> r;
        if (myMap.count(l)) {
            myMap[l] = max(myMap[l], r);
            continue;
        }
        myMap[l] = r;
    }
    int lPrev = myMap.begin()->first, rPrev = myMap.begin()->second;

    for(auto itr = myMap.begin(); itr != myMap.end(); ++itr)
    {       
        int l = (*itr).first;
        int r = (*itr).second;
        if (rPrev >= l) {
            rPrev = max(r, rPrev);           
            continue;
        }        
        cout << lPrev << " " << rPrev << endl;  
        lPrev = l;
        rPrev = r;
    }
    
    cout << lPrev << " " << rPrev << endl;

    
    return 0;
}
