#include <iostream>
using namespace std;
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
       if (!*p) return !*s;
       if (*(p+1) != '*')
          return ((*s == *p) || (*p == '.' && *s)) && isMatch(s+1, p+1);
       
       while (*s == *p || (*p == '.' && *s)) {
             if (isMatch(s, p+2))    return true;
             s++;
       }
       return isMatch(s, p+2);  //aaa    ab*a*c*a
    }
    
};

int main()
{
    Solution s;
    cout << s.isMatch("aa", "a");
    system("pause");
    return 0;
}
