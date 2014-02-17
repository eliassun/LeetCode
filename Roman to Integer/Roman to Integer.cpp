#include <iostream>
#include <map>
using namespace std;
class Solution {
public:
      int rToI[128];
      map<char, int> m;
      Solution() { 
         rToI['I'] = 1;
         rToI['V'] = 5;
         rToI['X'] = 10;
         rToI['L'] = 50;
         rToI['C'] = 100;
         rToI['D'] = 500;
         rToI['M'] = 1000;
    }
    
    int romanToInt(string s) {
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
           // cout << "s[" << i << "] = " << s[i] << "    " << "s[" << (i + 1) << "] = " << s[i+1] << endl;
            if (rToI[s[i]] >= rToI[s[i+1]]) {
               sum += rToI[s[i]];
            }
            else {
                 sum = sum + rToI[s[i+1]] - rToI[s[i]];
                 i++;
 
           }
        }
        return sum ;
    }
    
    int romanToInt1(string s) {
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            if (m[s[i]] >= m[s[i+1]]) {
               sum += m[s[i]];
            }
            else {
                 sum = sum + m[s[i+1]] - m[s[i]];
                 i++;
 
           }
        }
        return sum ;
    }
};

int main()
{
    Solution s;
    cout << s.romanToInt1("DCXXI");
    system("pause");
    return 0;
}
