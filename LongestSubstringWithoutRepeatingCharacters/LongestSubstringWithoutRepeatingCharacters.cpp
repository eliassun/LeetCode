#include <iostream>
#include <map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mapping;
        int len = s.length();

        int longest = 0;
        int start = 0;
        
        int begin, end;
        
        for (int i = 0; i < len; i++) {
            if (mapping[s[i]] > start) { //s[i]在当前字串中出现过 
               start = mapping[s[i]];  
            }
            
            
            if (i + 1 - start > longest) {
               longest = i + 1 - start;
               begin = start;
               end = i;
            }
            mapping[s[i]] = i + 1;
        }
        return longest;
    }
};

int main()
{
    string a = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
    for (int i = 0; i < a.length(); i++)
        cout << i << a[i] << " ";
    cout << endl;
    Solution s;
    int b = s.lengthOfLongestSubstring(a);
    cout << b;
    system("pause");
    return 0;
}
