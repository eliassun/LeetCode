#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > solution;
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
                  int curSum = num[small] + num[big];
                  if (-cur == curSum) {
                     vector<int> temp;
                     temp.push_back(cur);
                     temp.push_back(num[small]);
                     temp.push_back(num[big]);
                     solution.push_back(temp);
                     small++;
                  }
                  else if (-cur < curSum) {
                       big--;
                  }
                  else small++;
            }
        }
        
        return solution;
    }
    
    vector<vector<int> > threeSum1(vector<int> &num) {  
        // Start typing your C/C++ solution below  
        // DO NOT write int main() function  
         
        vector<vector<int> > ret;  
         ret.clear();  
        sort(num.begin(),num.end());  
        for(int i=0; i!=num.size();i++){  
            if(i > 0 && num[i]==num[i-1])  
                continue;  
            int j,k;  
            j=i+1;  
            k=num.size()-1;  
            while(j<k){  
                if(j>i+1&&num[j]==num[j-1]){   
                    j++;  
                    continue;  
                }  
                if(k<num.size()-1&& num[k]==num[k+1]){  
                    k--;  
                    continue;  
                }  
                 int sum = num[i] + num[j] + num[k];  
                if(sum>0){  
                    k--;  
                }else if(sum<0){  
                    j++;  
                }else{  
                    vector<int> tmp;  
                    tmp.push_back(num[i]);  
                    tmp.push_back(num[j]);  
                    tmp.push_back(num[k]);  
                    ret.push_back(tmp);  
                    j++;  
                }  
            }  
        }  
        return ret;  
              
    }
};

void showVector(vector<int> &num)
{
     for (vector<int>::iterator iter = num.begin(); iter != num.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> num;
    //num.push_back(-1);
    num.push_back(0);
    num.push_back(0);
    num.push_back(0);
    num.push_back(0);
    //num.push_back(1);
//    num.push_back(2);
//    num.push_back(-1);
//    num.push_back(-4);

    
    Solution s;
    vector<vector<int> > list = s.threeSum(num);
    
    for (vector<vector<int> >::iterator iter = list.begin(); iter != list.end(); ++iter) {
        showVector(*iter);
    }
    system("pause");
    return 0;
}
