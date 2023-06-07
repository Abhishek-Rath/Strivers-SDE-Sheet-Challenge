// T.C: O(nlogn) + O(n)
// S.C: O(n)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n <= 1) {
            return intervals;
        }

        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        vector<int> interval = intervals[0];
        ans.push_back(interval);
        int j = 0; // pointer to ans array

        for(int i = 1; i < n; i++) {
            if(intervals[i][0] <= ans[j][1]) {
                ans[j][1] = max(ans[j][1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
                j++;
            }
        }
        return ans;
    }
};