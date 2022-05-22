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
    int N, W;
    vector<pair<long, int>> vec;
    cin >> N >> W;
    int i;
    myfor(i, N) {
        long a;
        int b;
        cin >> a >> b;
        auto p = pair<long, int>(a, b);
        vec.push_back(p);
    }
    sort(vec.begin(),vec.end(),greater<pair<long, int>>());
    int weight = 0;
    long deliciousPoint = 0;
    for(auto pa : vec) {
        if(weight + pa.second <= W){
            weight += pa.second;
            deliciousPoint += pa.first * (long)pa.second;
        }else{
            auto newWeight = W - weight;
            weight += newWeight;
            deliciousPoint += pa.first * (long)newWeight;
        }
    }
    cout << deliciousPoint << endl;
    return 0;
}