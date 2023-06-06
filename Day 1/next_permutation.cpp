// Use in built STL library
#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &arr, int n) {
    next_permutation(arr.begin(), arr.end());
    return arr;
}

// Approach 2: Backtracking : Try every possible permutattion 
// T.C: O(n! * n)
// S.C: O(n)

void permute(int ind, vector<int>& arr, vector<vector<int>>& res) {
    // base case
    if(ind == arr.size()) {
        res.push_back(arr);
        return;
    }

    for(int i = ind; i < arr.size(); i++) {
        swap(arr[ind], arr[i]);
        permute(ind+1, arr, res);
        swap(arr[ind], arr[i]);
    }

}
vector<int> nextPermutation(vector<int> &arr, int n) {
    vector<vector<int>>res; 
    permute(0, arr, res);
    sort(res.begin(), res.end());
    vector<int> ans;
    for(int i = 0; i < res.size(); i++) {
        if(res[i] == arr) {
            if(i == res.size()-1) {
                ans = res[0];
            } else {
                ans = res[i+1];
            }
        }
    }
    return ans;
}