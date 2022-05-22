#include <algorithm>
#include <iostream>
#include <list>
#include <set>
#include <vector>
#include <float.h>
#include <math.h>

using namespace std;

int main() {
    int N;
    int x[300], y[300];
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x[i] >> y[i];
    }
    int count = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N;j++){
            for(int k = j+1; k < N;k++){                
                long dx = x[i] - x[j];
                long dy = y[i] - y[j];
                if(dx == 0){  
                    if(x[i] != x[k]){
                        count++;
                    }
                    continue;
                }

                long dxb = dx * y[i] - dy * x[i];
                if(dxb == dx * y[k] - dy * x[k]) {
                    continue;
                }

                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}