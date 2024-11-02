class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();

        if(sentence[0] != sentence[n-1])
            return false;

        int right = 0;

        while(right < n) {

            if(sentence[right] == ' ') 
                if(sentence[right - 1] != sentence[right + 1])
                    return false;
            
            right++;
        }

        return true;
        
    }
};
const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
