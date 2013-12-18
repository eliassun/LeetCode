#include <iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        int reverse = 0;
        if (x < 0)  return false;
        if (x < 10) return true;
        if (x % 10 == 0) return false;
        while (x > reverse) {
              reverse = reverse * 10 + x % 10;
              x /= 10;
        }
        if (x == reverse || x == reverse / 10)
           return true;
        else return false;
    }
    
    bool isPalindrome1(int x) {
        int n = 1, xx = x;
        while (xx / 10) {
              n *= 10;
              xx /= 10;
        }
        
        while (x) {
              int l = x / n;
              int r = x % 10;
              if (l != r) return false;
              else {
                   x %= n;
                   x /= 10;
                   n /= 100;
              }
        }
        return true;
    }
};

int main()
{
    Solution s;
    int a = 1234321;
    cout << s.isPalindrome1(a);
    system("pause");
    return 0;
}
