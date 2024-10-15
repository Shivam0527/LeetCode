class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int n = s.size();

        int lastAIndex = -1, lastBIndex = -1, lastCIndex = -1;
        int cnt = 0;
        
        for(int i=0; i<n; i++) {
            if(s[i] == 'a') lastAIndex = i;
            else if(s[i] == 'b') lastBIndex = i;
            else lastCIndex = i;

            if(lastAIndex != -1 && lastBIndex != -1 && lastCIndex != -1) {
                int minIndex = min(lastAIndex, min(lastBIndex, lastCIndex));
                
                cnt += (minIndex + 1);
            }
        }

        return cnt;
    }
};



// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int n = s.size();
        
//         int cnt = 0;
//         int left = 0, right = 0;
//         vector<int> vec(3, 0);

//         while(right < n) {
            
//             vec[s[right] - 'a']++;

//             while(vec[0]>0 && vec[1]>0 && vec[2]>0) {
//                 cnt += (n - right);
                
//                 vec[s[left] - 'a']--;

//                 left++;
//             }        

//             right++;
//         }        

//         return cnt;
//     }
// };
const int ZERO = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();
