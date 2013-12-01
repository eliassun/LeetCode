#include <iostream>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
           int len = s.length();
           bool **lp;
           lp = new bool *[len];
           for (int i = 0; i < len; i++)
               lp[i] = new bool[len];
           
           for (int i = 0; i < len; i++)
               for (int j = 0; j < len; j++) {
                   if (i >= j)
                      lp[i][j] = 1;
                   else lp[i][j] = 0;
               }
           
           int maxlen = 1;
           int sl = 0, sr = 0;
           for (int k = 1; k < len; k++) {
               for (int i = 0; i + k < len; i++) {
                   int j = i + k;
                   if (s[i] == s[j]) {
                      lp[i][j] = lp[i+1][j-1];
                      if (lp[i][j]) {
                         if (maxlen < k + 1) {
                            maxlen = k + 1;
                            sl = i;
                            sr = j;
                         }
                      }
                   }
                   else lp[i][j] = 0;
               }
           }
           
           for (int i = 0; i < len; i++)
               delete lp[i];
           delete lp;
           return s.substr(sl, maxlen);
    }
};

int main()
{
    string b = "a";
    Solution s;
    string a = s.longestPalindrome(b);
    cout << a;
    system("pause");
    return 0;
}
