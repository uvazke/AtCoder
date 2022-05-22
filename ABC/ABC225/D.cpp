#include <algorithm>
#include <float.h>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <vector>
#include <deque>
#define myfor(i, N) for (i = 0; i < N; i++)
#define myforFL(i, f, l) for (i = f; i < l; i++)
#define myforInv(i, N) for (i = N; i >= 0; i--)
#define myforFLInv(i, f, l) for (i = f; i > l; i--)
using namespace std;

int main() {
    int N, Q,i;
    cin >> N >> Q;
    map<int, int> arrow, reverseArrow;
    myfor(i, Q) {
        int queryNum;
        cin >> queryNum;
        if(queryNum == 1){
            int x, y;
            cin >> x >> y;
            arrow[x] = y;
            reverseArrow[y] = x;
            continue;
        }
        if(queryNum == 2){
            int x, y;
            cin >> x >> y;
            arrow.erase(x);
            reverseArrow.erase(y);
            continue;
        }
        int x;
        cin >> x;
        queue<int> arrowQueue;
        deque<int> reverseArrowStack;
        arrowQueue.push(x);
        int nextKey = x;
        while(arrow.count(nextKey) >0){
            nextKey = arrow[nextKey];
            arrowQueue.push(nextKey);
        }
        int reverseNextKey = x;
        while(reverseArrow.count(reverseNextKey)>0){
            reverseNextKey = reverseArrow[reverseNextKey];
            reverseArrowStack.push_back(reverseNextKey);
        }
        int count = arrowQueue.size() + reverseArrowStack.size();
        cout << count;
        while(reverseArrowStack.size() > 0) {
            int num = reverseArrowStack.back();
            reverseArrowStack.pop_back();
            cout << " " << num;
        }
        while(arrowQueue.size() > 0) {
            int num = arrowQueue.front();
            arrowQueue.pop();
            cout << " " << num ;
        }
        cout << endl;
    }
    return 0;
}