#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int> &height) {
        vector<int>::iterator beg = height.begin(), end = height.end();
        end--;
        int most = 0;
        while (beg != end) {
              int min = *beg < *end ? *beg : *end; 
              int size = min * (end - beg);
              if (size > most)
                 most = size;
              if (*beg > *end) end--;
              else beg++;
        }
        return most;
    }
};

int main()
{
    Solution s;
    vector<int> height;
    height.push_back(3);
    height.push_back(1);
    height.push_back(4);
    height.push_back(2);
    cout << s.maxArea(height);
    system("pause");
    return 0;
}
