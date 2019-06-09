#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
#define f2(i,a,b) for(int i=a;i<b;i++)

void matrixMul(int size,long matrix[100][100], long newMatrix[100][100]){
	f(i,size)f(j,size){
		newMatrix[i][j] = 0;
		f(k,size){
		newMatrix[i][j] ^= (matrix[i][k] & matrix[k][j]); 
		}
	}
}

void matrixTimesVector(int size,long matrix[100][100], long vec[100],long newVector[100]){
	f(i,size){
		newVector[i] = 0;
		f(j,size){
			newVector[i] ^= (matrix[i][j] & vec[j]);
		}
	}
}

void insert(int size, long matrix1[100][100], long matrix2[100][100]){
	f(i,size)memmove(matrix2[i],matrix1[i],100*8);
}
int main(){
	long matrixs[32][100][100], matrix[100][100], newMatrix[100][100];
	long K,M,M2,A[100],B[100],C[100];
	cin >> K >> M;
	rf(i,K) cin >> A[i];
	f(i,K) cin >> matrix[0][i];
	vector<int> Mdigit2;
	M2 = M-K;
	while(M2){
		if(M2&1)Mdigit2.push_back(1);
		else Mdigit2.push_back(0);
		M2 >>= 1;
	}
	f2(i,1,K)f(j,K) matrix[i][j] = i-1 == j ? long(pow(2,33)-1) : 0;
	insert(K,matrix, matrixs[0]);
	f2(i,1,Mdigit2.size()){
		matrixMul(K,matrixs[i-1], matrixs[i]);
	}
	f(i,Mdigit2.size()){
		if(Mdigit2[i] == 1){
			matrixTimesVector(K,matrixs[i],A,B);
			memmove(A,B,100*8);
		}
	}


	cout << A[0] << endl;
	return 0;
}