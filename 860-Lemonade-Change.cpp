class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        vector<int> hash(2, 0);

        for(int i=0; i<bills.size(); i++) {
            if(bills[i] == 5)
                hash[0]++;

            else if(bills[i] == 10) {
                if(hash[0] > 0) {
                    hash[0]--;
                    hash[1]++;
                }
                else 
                    return false;
            }

            else {
                if(hash[0] > 0 && hash[1] > 0) {
                    hash[0]--;
                    hash[1]--;
                }
                else if(hash[0] >= 3)
                    hash[0] -=3;
                else 
                    return false;
            }
        }

        return true;
    }
};