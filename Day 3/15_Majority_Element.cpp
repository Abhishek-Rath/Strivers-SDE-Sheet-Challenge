// Brute force: TC: O(n^2), S.C: O(1)

int findMajorityElement(int arr[], int n) {
	for(int i = 0; i < n; i++) {
		int cnt = 0;
		for(int j = 0; j < n; j++) {
			if(arr[i] == arr[j]) {
				cnt++;
			}
		}
		if(cnt > n/2) {
			return arr[i];
		}
	}
	return -1;
}

// Better Approach: Use Map to store frequency of the elements
// T.C: O(n), S.C: O(n)

int findMajorityElement(int arr[], int n) {
	unordered_map<int, int> mp;
	for(int i = 0; i < n; i++) {
		mp[arr[i]]++;
	}

	for(auto it : mp) {
		if(it.second > (int)floor(n/2)) {
			return it.first;
		}
	}
	return -1;
}

// Optimal Approach: Use Moore's Voting Algorithm
/*
    Initialize 2 variables:
    Count –  for tracking the count of element
    Element – for which element we are counting
    Traverse through the given array.
        If Count is 0 then store the current element of the array as Element.
        If the current element and Element are the same increase the Count by 1.
        If they are different decrease the Count by 1.
        The integer present in Element should be the result we are expecting 
*/

int findMajorityElement(int arr[], int n) {
	int el;
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if(cnt == 0) {
			el = arr[i];
			cnt = 1;
		} else if(arr[i] == el) {
			cnt++;
		} else {
			cnt--;
		}
	}

	int cnt1 = 0;
	for(int i = 0; i < n; i++) {
		if(el == arr[i]) cnt1++;
	}

	if(cnt1 > n/2) {
		return el;
	}
	return -1;
	
}