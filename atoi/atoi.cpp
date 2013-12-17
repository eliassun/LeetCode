#include <iostream>
using namespace std;
class Solution {
public:
    int atoi(const char *str) {
        int idx = 0;
        while (str[idx++] == ' ');
        idx--;
        
        int flag = 1;
        long long num = 0;
        if (!isdigit(str[idx])) {
           if (str[idx] == '-') flag = -1;
           else if (str[idx] != '+') return 0;
           idx++;
        }
        while (isdigit(str[idx])) {
              if (num > INT_MAX / 10)
                 return flag == 1 ? INT_MAX : INT_MIN;
              else   num *= 10;
              
              if (num  > INT_MAX - str[idx] + '0')
                 return flag == 1 ? INT_MAX : INT_MIN;
              else num += str[idx] - '0';
              
              idx++;
              
        }
        
        return num;
    }
};

int main()
{
    Solution s;
    char *str = "-1";
    cout << s.atoi(str);
    
    system("pause");
    return 0;
}
