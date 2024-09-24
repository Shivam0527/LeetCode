/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return \t     -1 if num is higher than the picked number
 *\t\t\t      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        while(left <= right) {
            int mid = (right - left) / 2 + left;

            int pickRes = guess(mid);

            if(pickRes == 0) return mid;
            else if(pickRes == -1) right = mid - 1;
            else left = mid + 1; 
        }

        return -1;
    }
};