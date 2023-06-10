#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n) {
	sort(arr.begin(), arr.end());
	vector<int> count(n+1, 0);
	pair<int, int> ans;
	for(int i = 0; i < n-1; i++) {
		if(arr[i] == arr[i+1]) {
			ans.second = arr[i];
		}
		count[arr[i]]++;
	}
	count[arr[n-1]]++; //add last element

	for(int i = 1; i < n+1; i++) {
		if(count[i] == 0) {
			ans.first = i;
			break;
		}
	}
	return ans;
	
}
