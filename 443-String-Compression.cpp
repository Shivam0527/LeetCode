class Solution {
public:
    int compress(vector<char>& chars) {

        if(chars.size() == 1) return 1;
        int i = 0;
        int write = 0;

        while(i < chars.size()) {
            int cnt = 0;
            char c = chars[i];

            while(i < chars.size() && chars[i] == c) {
                cnt++;
                i++;
            }

            chars[write++] = c;

            if(cnt > 1){
                string num =  to_string(cnt);

                for(char ch : num) {
                    chars[write++] = ch;
                }
            }

        }

        return write;               
    }
};
const int ZERO = []()
{
\tstd::ios_base::sync_with_stdio(false);
\tstd::cin.tie(nullptr);
\treturn 0;
}();
