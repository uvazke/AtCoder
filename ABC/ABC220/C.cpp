#include <algorithm>
#include <iostream>
#include <list>
#include <set>
#include <vector>
using namespace std;


int BinarySearch(int min, int max, long target, long list[]){
    int half = min + (max - min) / 2;
    if(max - min <= 1){
        if(list[min] > target){
            return min;
        }
        if(list[max] > target){
            return max;
        }
        return max + 1;
    }
    if(list[half] > target){
        return BinarySearch(min, half - 1,target,list);
    }
    if(list[half] < target){
        return BinarySearch(half + 1, max,target,list);
    }
    return half;
}

int main() {
    int N;
    long A[100000];
    long sum[100000];
    long X;
    cin >> N;
    for(int i = 0; i < N;i++){
        cin >> A[i];
        if(i == 0){
            sum[i] = A[i];
            continue;
        }
        sum[i] = sum[i - 1] + A[i];
    }
    cin >> X;
    long maxSum = sum[N - 1];
    long count = X / maxSum;
    long residue = X % maxSum;
    int index = BinarySearch(0, N - 1, residue, sum);
    cout << count * (long)N + (long)index + 1 << endl;
    return 0;
}
