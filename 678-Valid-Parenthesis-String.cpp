class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0;
        int maxOpen = 0;

        for(char c : s) {
            if(c == '(') {
                minOpen++;
                maxOpen++;
            }
            else if(c == ')') {
                if(minOpen > 0)
                    minOpen--;
                
                maxOpen--;
            }
            else {
                if(minOpen > 0)
                    minOpen--;

                maxOpen++;
            }

            if(maxOpen < 0)
                return false;
        }

        return minOpen == 0;
    }
};
const int ZERO = []()
{
\tstd::ios_base::sync_with_stdio(false);
\tstd::cin.tie(nullptr);
\treturn 0;
}();
