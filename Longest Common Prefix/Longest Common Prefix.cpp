#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (!strs.size())   return "";
        string pre = strs[0];
        
        for (vector<string>::iterator iter = strs.begin(); iter != strs.end(); ++iter) {
            
            int i = 0;
            while (i < pre.size() && i < (*iter).size() && pre[i] == (*iter)[i]) {
                  i++;
            }
            pre = pre.substr(0, i);
        }
        return pre;
    }
};

int main()
{
    vector<string> strs;
    strs.push_back("acfdkfd");
    strs.push_back("acflls");
    strs.push_back("acfkd");
    
    Solution s;
    cout << s.longestCommonPrefix(strs);
    system("pause");
    return 0;
}
