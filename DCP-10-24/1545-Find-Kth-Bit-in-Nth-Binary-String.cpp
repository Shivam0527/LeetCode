class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1) return '0';

        int len = pow(2, n) - 1;

        if(k < (len + 1) / 2) {
            return findKthBit(n-1, k);
        }
        else if(k == (len + 1) / 2) {
            return '1';
        }
        else {
            char c = findKthBit(n-1, len - k + 1);

            if(c == '0') return '1';
            return '0';
        }
    }
};
const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
