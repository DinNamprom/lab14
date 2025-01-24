#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

void inputMatrix(double matrix[][N]) {
	for (int i=0;i<N;i++) {
		cout << "Row " << i+1 << ": ";
		for (int j=0;j<N;j++) {
			cin >> matrix[i][j];
		}
	}
}

void findLocalMax(const double MatA[][N], bool MatB[][N]) {
	int up=0,low=N,left=0,right=N;

	for (int i=0;i<N;i++) {
		MatB[up][i] = false;
	}
	for (int i=0;i<N;i++) {
		MatB[low][i] = false;
	}
	for (int i=0;i<N;i++) {
		MatB[i][left] = false;
	}
	for (int i=0;i<N;i++) {
		MatB[i][right] = false;
	}

	for (int j=1;j<N-1;j++) {
		for(int k=1;k<N-1;k++) {
			double Slag=MatA[j][k];
			if (Slag >= MatA[j][k-1] && Slag >= MatA[j][k+1] && Slag >= MatA[j-1][k] && Slag >= MatA[j+1][k]) {
				MatB[j][k] = true;
			}else {
				MatB[j][k] = false;
			}
		}
	}
}

void showMatrix(const bool matrix[][N]) {
	for (int i=0;i<N;i++) {
		for (int j=0;j<N;j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

//Do not modify source code above this line 
