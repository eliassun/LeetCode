#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
        vector<string> ret;
 public:
    void solve(int left, int right, int n, string str, vector<string> &vec)
     {
         if (left > n || left < right)   return;    //×óÀ¨ºÅÊý´óÓÚn 
         if (left == right) {
            if (left == n)
               vec.push_back(str);
         }
         solve(left+1, right, n, str+'(', vec);
         solve(left, right+1, n, str+')', vec);
     }
     
     vector<string> generateParenthesis(int n) {
         // Start typing your C/C++ solution below
         // DO NOT write int main() function
         vector<string> vec;
         solve(0, 0, n,"", vec);
         return vec;
     }
 };
 
 int main()
 {
     Solution s;
     vector<string> vec;
     vec = s.generateParenthesis(3);
     for (int i = 0; i < vec.size(); i++) {
         cout << vec[i] << endl;    
     }
     system("pause");
     return 0;
 }
