// Brute force:
// Looping from 1 to n and keeping a ans(double) variable. 
// Now every time your loop runs, multiply x with ans. 
// TC: O(n)
class Solution {
    public:
        double myPow(double x, int n) {
            double ans = 1.0;
            for (int i = 0; i < n; i++) {
                ans = ans * x;
            }
            return ans;
        }
};


// OPtimal Approach: Binary Exponentiation

// Initialize ans as 1.0  and store a duplicate copy of n to avoid overflow

// Check if nn is a negative number, in that case, make it a positive number.

// Keep on iterating until nn is greater than zero, now if nn is an odd power then multiply x with ans ans reduce m by 1. 
// Else multiply x with itself and divide m by two.

// Now after the entire binary exponentiation is complete and nn becomes zero,
//  check if n is a negative value we know the answer will be 1 divided by ans
// TC: O(NlogN), SC: O(1)

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n;
        if(nn < 0) {
            nn = -1 * nn;
        }

        while(nn) {
            if(nn % 2 == 1) {
                ans = ans * x;
                nn = nn-1;
            } else {
                x = x * x;
                nn /= 2;
            }
        }

        if(n < 0) {
            ans = (double)(1.0) / (double)(ans);
        }
        return ans;
    }
};