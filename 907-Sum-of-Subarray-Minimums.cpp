class Solution {
public:
    int findMax(vector<int> &v) {
        int maxi = INT_MIN;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, v[i]);
        }
        return maxi;
    }
    double eat(vector<int>& piles, int mid, int h) {
        double timeTaken=0;
        for(int i=0; i<piles.size(); i++) {
            double div = (piles[i]/mid);
            timeTaken += div;
            if(piles[i]%mid!=0) timeTaken+=1;
        }
        return timeTaken;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = findMax(piles);
        int left=1, right=maxi;
        while(left<=right) {
            int mid=left + (right-left)/2;
            double timeTaken=eat(piles, mid, h);
            if(timeTaken<=h) {
                right=mid-1;
            } else {
                left=mid+1;
            }
        }
        return left;        
    }
};
const int ZERO = []()
{
\tstd::ios_base::sync_with_stdio(false);
\tstd::cin.tie(nullptr);
\treturn 0;
}();