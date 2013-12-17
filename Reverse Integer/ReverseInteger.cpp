#include <iostream>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        int flag = x > 0 ? 1 : -1;
        x = abs(x);
        int rev = 0;
        while (x) {
              rev = rev * 10 + x % 10;
              x /= 10;
        }    
        return flag * rev;
    }
};

int main()
{
    Solution s;
    int a = -120;
    int x = s.reverse(a);
    cout << x;   
    system("pause");
    return 0;
}
