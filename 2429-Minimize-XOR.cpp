class Solution {
public:
    int isSet(int num, int bit) {
        return num & (1 << bit);
    }
    int minimizeXor(int num1, int num2) {

        int x = 0;
        int reqBit = __builtin_popcount(num2);

        for(int i=31; i>=0 && reqBit>0; i--) {
            if(isSet(num1, i)) {
                x = x | (1 << i);
                reqBit--;
            }
        }

        for(int i=0; i<=31 && reqBit>0; i++) {
            if(!isSet(x, i)) {
                x = x | (1 << i);
                reqBit--;
            }
        }

        return x;       
    }
};


// class Solution {
// public:
//     bool isSetBit(int num, int bit) {
//         return (num & (1 << bit)) > 0;
//     }

//     int minimizeXor(int num1, int num2) {

//         int x = num1;

//         int setBit = __builtin_popcount(num2);
//         int currSetBit = __builtin_popcount(x);

//         if(currSetBit < setBit) {
//             int bit = 0;
//             while(currSetBit < setBit) {
//                 if(!isSetBit(x, bit)) {
//                     x = x | (1 << bit);
//                     currSetBit++;
//                 }

//                 bit++;
//             }
//         }
//         else if(currSetBit > setBit) {
//             int bit = 0;
//             while(currSetBit > setBit) {
//                 if(isSetBit(x, bit)) {
//                     x = x ^ (1 << bit);
//                     currSetBit--;
//                 }

//                 bit++;
//             }
//         }

//         return x;        
//     }
// };