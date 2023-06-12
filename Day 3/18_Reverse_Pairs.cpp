// Brute force: T.C: O(n^2), SC: O(1)
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(1LL * nums[i] > 1LL * 2*nums[j]) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};


// Optimal Approach
/*
    In order to solve this problem we will use the merge sort algorithm like we used in the problem count inversion 
    with a slight modification of the merge() function

    The steps of the countPairs() function will be as follows:

        We will declare a variable, cnt, initialized with 0.
        We will run a loop from low to mid, to select an element at a time from the left half.
        Inside that loop, we will use another loop to check how many elements from the right half can make a pair.
        Lastly, we will add the total number of elements i.e. (right-(mid+1)) (where right = current index), to the cnt and return it.

    T.C: O(NlogN), SC: O(N)
*/

class Solution {
public:
    int countPairs(vector<int>& nums, int low, int mid, int high) {
        int right = mid+1;
        int cnt = 0;
        for(int i = low; i <= mid; i++) {
            while(right <= high && 1LL * nums[i] > 1LL * 2 * nums[right]) {
                right++;
            }
            cnt += (right - (mid+1));
        }
        return cnt;
    }

    void merge(vector<int>& nums, int low, int mid, int high) {
        int left = low; // start index of left half
        int right = mid+1; // starting index of right half
        vector<int> temp; // to store the sorted numbers

        while(left <= mid && right <= high) {
            if(nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
                right++;
            }
        }

        while(left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        while(right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        for(int i = low; i <= high; i++) {
            nums[i] = temp[i-low];
        }
    }

    int mergeSort(vector<int>& nums, int low, int high) {
        int cnt = 0;
        if(low >= high)  return cnt;
        int mid = (low + high)/2;
        cnt += mergeSort(nums, low, mid); 
        cnt += mergeSort(nums, mid+1, high);
        cnt += countPairs(nums, low, mid, high);
        merge(nums, low, mid, high);
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int ans = mergeSort(nums, 0, n-1);
        return ans;
    }
};