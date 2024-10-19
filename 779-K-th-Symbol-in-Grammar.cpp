class Solution {
public:
    int kthGrammar(int n, int k) {

        if(n == 1) return 0;

        int len = 1 << (n-1);
        
        if(k <= len/2) {
            return kthGrammar(n-1, k);
        }
        else {
            return !kthGrammar(n-1, k - len/2);
        }
    }
};
const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
