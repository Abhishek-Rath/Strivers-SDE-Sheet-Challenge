// Brute force
vector<int> majorityElement(vector<int> v) {
    int n = v.size(); //size of the array
    vector<int> ans; // list of answers

    for (int i = 0; i < n; i++) {
        //selected element is v[i]: // Checking if v[i] is not already
        // a part of the answer:
        if (ans.size() == 0 || ans[0] != v[i]) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                // counting the frequency of v[i]
                if (v[j] == v[i]) {
                    cnt++;
                }
            }

            // check if frquency is greater than n/3:
            if (cnt > (n / 3))
                ans.push_back(v[i]);
        }

        if (ans.size() == 2) break;
    }

    return ans;
}

// Better approach: Use map to store the frequency of elements
// T.C: O(N), S.C: O(n)

vector<int> majorityElementII(vector<int> &arr)
{
    vector<int> ans;
    unordered_map<int,int> mp;
    for(auto x : arr) {
        mp[x]++;
    }

    for(auto it : mp) {
        if(it.second > arr.size()/3) {
            ans.push_back(it.first);
        }
    }
    return ans;
}


// Approach 2: Extended Moore's voting algo
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int el1, el2;
        int cnt1 = 0, cnt2 = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == el1) {
                cnt1++;
            } else if(nums[i] == el2) {
                cnt2++;
            } else if(cnt1 == 0) {
                cnt1 = 1;
                el1 = nums[i];
            } else if(cnt2 == 0) {
                cnt2 = 1;
                el2 = nums[i];
            } else {
                cnt1--;
                cnt2--;
            }
        }
    
        vector<int> ans;
        cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == el1) {
                cnt1++;
            } else if(nums[i] == el2) {
                cnt2++;
            }
        }

        if(cnt1 > n/3) {
            ans.push_back(el1);
        }
        if(cnt2 > n/3) {
            ans.push_back(el2);
        }
        return ans;
    }
};