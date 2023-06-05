/* Brute Force
Traverse through the matrix and if you find an element with 
value 0, then change all the elements in its row and column to -1, except when an element is 0. The reason for not 
changing other elements to 0, but -1, is because that might affect other columns and rows. Now traverse through the 
matrix again and if an element is -1 change it to 0, which will be the answer.

TC: O(n*m*(n+m) + n*m)  
SC: O(1)

*/

#include <bits/stdc++.h>

const int mark = INT_MAX;

void markRow(vector<vector<int>>& matrix, int n, int m, int i) {
	for(int j = 0; j < m; j++) {
		if(matrix[i][j] != 0) {
			matrix[i][j] = mark;
		}
	}
}

void markCol(vector<vector<int>>& matrix, int n, int m, int j) {
	for(int i = 0; i < n; i++) {
		if(matrix[i][j] != 0) {
			matrix[i][j] = mark;
		}
	}
}

void setZeros(vector<vector<int>> &matrix) {
	int n = matrix.size();
	int m = matrix[0].size();

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(matrix[i][j] == 0) {
				markRow(matrix, n, m, i);
				markCol(matrix, n, m, j);
			}
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(matrix[i][j] == INT_MAX) {
				matrix[i][j] = 0;
			}
		}
	}

}


// Better Approach
//  Take two dummy array one of size of n and other of size of m. Now traverse through the matrix. If matrix[i][j] == 0 
//  then set dummy1 [i] = 0 (for row) and dummy2[j] = 0 (for column). 
// Now traverse through the matrix again and if dummy1[i]==0  || dummy2[j]==0 then matrix[i][j] = 0.
// T.C: O(n*m + n*m), S.C: O(n) + O(m)

void setZeros(vector<vector<int>> &matrix) {
	int n = matrix.size();
	int m = matrix[0].size();

	vector<int> markRow(n, 0);
	vector<int> markCol(m, 0);

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(matrix[i][j] == 0) {
				markRow[i] = 1;
				markCol[j] = 1;
			}
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(markRow[i] == 1 || markCol[j] == 1) {
				matrix[i][j] = 0;
			}
		}
	}

}