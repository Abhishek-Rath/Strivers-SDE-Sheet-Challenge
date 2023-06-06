// Brute force: O(n^3)

long long maxSubarraySum(int arr[], int n) {
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            long long sum = 0;
            for(int k = i; k <= j; k++) {
                sum += arr[k];
            }
            if(sum > ans) {
                ans = sum;
            }
        }
        
    }
    return ans;
}

// Better: O(n^2) approach

long long maxSubarraySum(int arr[], int n) {
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        long long sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];
            if(sum > ans) {
            ans = sum;
        }
        }
        
    }
    return ans;
}


// Optimal : Kadane's Algorithm
// T.C: O(n)
// Ref: https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/

long long maxSubarraySum(int arr[], int n) {
    long long mx = 0;
    long long sum = 0;
    for(int i = 0; i < n; i++) { 
        sum += arr[i];
        if(sum < 0) {
            sum = 0;
        }  

        if(sum > mx) {
            mx = sum;
        }     
    }
    return mx;
}