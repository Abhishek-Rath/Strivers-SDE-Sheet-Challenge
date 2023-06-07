// Brute force: Use extra array to store all the elements and then sort it
// T.C: O((n+m) log(n+m)), S.C: O(n+m)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans(n+m);
        for(int i = 0; i < n+m; i++) {
            if(i < m) ans[i] = nums1[i];
            else ans[i] = nums2[i-m];
        }
        for(auto x : ans) cout <<x <<" ";
        sort(ans.begin(), ans.end());
        nums1 = ans;
    
    }
};

// Optimal Approach: Use 3 pointers
// T.C: O(n), S.C: O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, k = m+n-1;
        while(i >= 0 && j >= 0) {
            if(nums1[i] >= nums2[j]) {
                nums1[k] = nums1[i];
                k--, i--;
            } else {
                nums1[k] = nums2[j];
                k--, j--;
            }
        }

        while(i >= 0) {
            nums1[k] = nums1[i];
            k--, i--;
        }

        while(j >= 0) {
            nums1[k] = nums2[j];
            k--, j--;
        }
    }
};