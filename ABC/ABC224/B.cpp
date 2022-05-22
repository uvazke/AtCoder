#include <algorithm>
#include <iostream>
#include <list>
#include <set>
#include <vector>
using namespace std;

int main() {
    long H,W,A[50][50];
    cin >> H >> W;
    for(int i = 0; i < H;i++){
        for(int j = 0; j < W;j++){
            cin >> A[i][j];
    }   
    }
    for(int i = 0; i < H;i++){
        for(int j = 0; j < W;j++){
            for(int k = i+1; k < H;k++){
                for(int l = j+1; l < W;l++){
                if(A[i][j] + A[k][l] > A[i][l]+A[k][j]){
                    cout << "No" << endl;
                    return 0;
                }
                }}}}
    cout << "Yes" << endl;
    return 0;
}