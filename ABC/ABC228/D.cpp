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
    long Q, t[2 * 100000], x[2 * 100000];
    vector<pair<int, int>> spans;
    int i, j;
    cin >> Q;
    myfor(i, 1048576) { a[i] = -1; }
    myfor(i, Q) {
        cin >> t[i];
        cin >> x[i];
        int ind = x[i] % ((int)pow(2, 20));
        if(t[i] == 2) {
            cout << a[ind] << endl;
            continue;
        }
        if(a[ind] == -1) {
            a[ind] = x[i];
            spans.push_back(pair<int, int>(ind, ind));
            sort(spans.begin(), spans.end());
            myfor(j, spans.size()) {
                pair<int, int> p = spans[j];
                if(p.first <= ind && ind <= p.second) {
                    if(j + 1 < spans.size()) {
                        if(spans[j + 1].first == p.second + 1) {
                            spans[j].second = spans[j + 1].second;
                            spans.erase(spans.begin() + j + 1);
                        }
                    }
                    break;
                }
            }

        } else {
            myfor(j, spans.size()) {
                pair<int, int> p = spans[j];
                if(p.first <= ind && ind <= p.second) {
                    a[p.second + 1] = x[i];
                    spans[j].second++;
                    if(j + 1 < spans.size()) {
                        if(spans[j + 1].first == p.second + 1) {
                            spans[j].second = spans[j + 1].second;
                            spans.erase(spans.begin() + j + 1);
                        }
                    }
                    break;
                }
            }
        }
    }

    return 0;
}