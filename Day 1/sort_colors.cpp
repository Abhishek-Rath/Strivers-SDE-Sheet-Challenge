// Brute force : Use in built sort library
// T.C: O(n logn), S.C: O(1)

void sort012(int *arr, int n) {
    sort(arr, arr+n);
}

// Better Approach: Use three variables to store the count of 0s, 1s, and 2s in first pass
// in 2nd pass - store the 0s, then 1s and 2s 
// T.C: O(n), S.C: O(1)
 
void sort012(int *arr, int n) {
   int zeros = 0, ones = 0, twos = 0;
   for(int i = 0; i < n; i++) {
      int num = arr[i];
      if(num == 0) zeros++;
      else if(num == 1) ones++;
      else twos++;
   }
   int i = 0;
   while(zeros--) {
      arr[i] = 0;
      i++;
   }

   while(ones--) {
      arr[i] = 1;
      i++;
   }

   while(twos--) {
      arr[i] = 2;
      i++;
   }
}



// Optimal Approach: Dutch National Flag Algorithm
// Ref: https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/
void sort012(int *a, int n) {
   int low = 0;
   int mid = 0;
   int high = n-1;

   while(mid <= high) {
      if(a[mid] == 0) {
         swap(a[low++], a[mid++]);
      } else if(a[mid] == 1) {
         mid++;
      } else {
         swap(a[mid], a[high--]);
      }
   }
}