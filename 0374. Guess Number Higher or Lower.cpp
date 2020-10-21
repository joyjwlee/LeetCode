/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
  public:
    int guessNumber(int n) {
        // edge
        if (guess(n) == 0)
            return n;

        // simple binary search
        int left = 0, right = n, mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (guess(mid) == 0)
                return mid;
            if (guess(mid) == -1)
                right = mid;
            else
                left = mid;
        }
        return mid;
    }
};