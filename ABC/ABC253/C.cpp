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
	int Q, i;
    map<int, int> myMap;
    cin >> Q;
	myfor(i, Q) {
        int command;
		cin >> command;       
        if (command == 1) {
            int x;
            cin >> x;
            auto const res = myMap.insert(make_pair(x, 1));
            if (not res.second) {
                res.first->second++;
            }
            continue;
        }
        if (command == 2) {
            int x;
            cin >> x;
            int c;
            cin >> c;
            if (myMap.find(x) != myMap.end()) {
                myMap[x] -= min(myMap[x], c);
                if (myMap[x] == 0) {
                    myMap.erase(x);
                }

                continue;
            }
            continue;
        }
        if (myMap.empty()) {
            continue;
        }
        auto maxi = myMap.rbegin()->first;
        auto mini = myMap.begin()->first;
        cout << maxi - mini << endl;

	}
	return 0;
}
