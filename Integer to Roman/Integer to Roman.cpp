#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string R[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int I[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
        string roman = "";
        
        for (int i = 0; i < 13; i++) {
            if (!num) return roman;
            while (num >= I[i]) {
                  roman += R[i];
                  num -= I[i];
            }
        }
        
        return roman;
    }
};

int main()
{
    Solution s;
    cout << s.intToRoman(2000);
    system("pause");
    return 0;
}
