class Solution {
public:
    int minAddToMakeValid(string s) {

        int n = s.size();
        int cnt = 0;

        stack<char> st;

        for(int i=n-1; i>=0; i--) {
            if(s[i] == '(') {
                if(st.empty()) {
                    cnt++;
                }
                else {
                    st.pop();
                }
            } 
            else {
                st.push(s[i]);
            }
        } 

        cnt += st.size();

        return cnt;        
    }
};
const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
