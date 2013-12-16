#include <iostream>
using namespace std;
class Solution {
public:
    string convert(string s, int nRows) {
        int len = s.length();
        string zigzag;
        
        if (len <= nRows || nRows == 1)
           return s;
        
        for (int row = 1; row <= nRows; row++) {
            zigzag += s[row - 1];
            int lastPos = row - 1;
            int pos = row - 1 + 2 * (nRows - row);
            while (pos < len) {
                  if (pos != lastPos)
                     zigzag += s[pos];
                  if (2*row - 2) {
                     pos += 2 * row - 2;
                      if (pos >= len)
                         break;
                      zigzag += s[pos];
                  }
                  lastPos = pos;
                  pos += 2 * (nRows - row);
            }
        }
        return zigzag;
    }
    
    string convertOn(string s, int nRows) {
        if (nRows == 1)
           return s;
        string lines[nRows];
        int len = s.length();
        int idx = -1, step = 1;
        for (int i = 0; i < len; i++) {
            idx += step;
            if (idx == nRows) {
               idx = nRows - 2;
               step = -1;
            }
            else if (idx == -1) {
                 idx = 1;
                 step = 1;
            }
            lines[idx] += s[i];
        }
        string zigzag;
        for (int i = 0; i < nRows; i++)
            zigzag += lines[i];
        return zigzag;
    }
};

int main()
{
    string a("PAYPALISHIRING");
    string b("AB");
    Solution s;
    cout << s.convertOn(a, 3);
    system("pause");
    return 0;
}
