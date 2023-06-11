// Try out every possible way -> recursion
// T.C: O(2^(m+n))

int rec(int i, int j) {
	// rec(i, j) --> gives no. of ways to reach cell (i, j) from (0, 0)

	if(i < 0 || j < 0) return 0;
	
	// base case
	if(i == 0 && j == 0) {
		return 1;
	}

	//  compute
	int up = rec(i-1, j);
	int left = rec(i, j-1);

	// save and return 
	return up + left;
}

int uniquePaths(int m, int n) {
	return rec(m-1, n-1);
}


// Memoization: Use cache array of size m*n, to store the number of ways from (0, 0) to (i, j) in dp array 
// Cache array can be used to retrieve the results of overlapping subproblems

#include <bits/stdc++.h> 

int rec(int i, int j, vector<vector<int>>& dp) {
	// rec(i, j) --> gives no. of ways to reach cell (i, j) from (0, 0)

	if(i < 0 || j < 0) return 0;
	
	// base case
	if(i == 0 && j == 0) {
		return 1;
	}

	// cache check
	if(dp[i][j] != -1) {
		return dp[i][j];
	}

	// compute
	int up = rec(i-1, j, dp);
	int left = rec(i, j-1, dp);

	// save and return 
	return dp[i][j] = up + left;
}

int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m, vector<int>(n, -1));
	return rec(m-1, n-1, dp);
}