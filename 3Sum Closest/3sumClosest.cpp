#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int solution = num[0] + num[1] + num[2];
        sort(num.begin(), num.end());
        
        for (int i = 0; i != num.size(); i++) {
            int cur = num[i];
            if (i && num[i] == num[i - 1])
               continue;
            int small = i + 1, big = num.size() - 1;
            while (small < big) {
                  if (small > i + 1 && num[small] == num[small-1]) {
                     small++;
                     continue;
                  }
                  int curSum = cur + num[small] + num[big];
                  if (abs(curSum - target) < abs(solution - target)) {
                     solution = curSum;
                  }
                  
                  if (curSum == target) {
                     return solution;
                  }
                  else if (curSum < target) {
                       small++;
                  }
                  else big--;
            }
        }
        
        return solution;
    }
};

int main()
{
    vector<int> num;
    num.push_back(-1);
    num.push_back(2);
    num.push_back(1);
    num.push_back(-4);
    Solution s;
    cout << s.threeSumClosest(num, 1);
    system("pause");
    return 0;
}
