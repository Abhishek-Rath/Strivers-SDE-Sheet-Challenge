// Brute Force: T.C: O(n^2), S.C: O(1)

bool searchMatrix(vector<vector<int>>& mat, int target) {
      int m = mat.size();
      int n = mat[0].size();

      for(int i = 0; i < m; i++) {
          for(int j = 0; j < n; j++) {
              if(mat[i][j] == target) {
                  return true;
              }
          }
      }  
    return false;
}


// Optimal Approach: Use Binary Search
// T.C: O(nlogn), S.C: O(1)

bool searchMatrix(vector<vector<int>>& mat, int target) {
      int m = mat.size();
      int n = mat[0].size();

      int low = 0, high = m*n-1;
      while(low <= high) {
          int mid = low + (high-low)/2;
          int ele = mat[mid/n][mid%n];
          if(ele == target) {
              return true;
          } else if(ele > target) {
              high = mid-1;
          } else {
              low = mid+1;
          }
      }
      return false;
}