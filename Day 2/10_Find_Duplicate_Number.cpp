// Sort the array. After that, if there is any duplicate number they will be adjacent
// T.C: O(Nlogn + N)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans;
        for(int i = 0; i < n-1; i++) {
            if(nums[i] == nums[i+1]) {
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};