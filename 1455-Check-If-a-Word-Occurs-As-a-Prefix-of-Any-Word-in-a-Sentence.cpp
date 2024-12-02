class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        
        string word = "";
        int cnt = 1;

        for(int i=0; i<sentence.size(); i++) {

            word += sentence[i];

            if(sentence[i] == ' ') {
               word = ""; 
               cnt++;               
            }

            if(word == searchWord)
                return cnt;
        }

        return -1;
    }
};
const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
