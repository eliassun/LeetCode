#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution_On2 {
      public:
             vector<int> twoSum(vector<int> &number, int target) {
                 vector<int> sol(2);
                 
                 int len = number.size();
                 for (int i = 0; i < len; i++) {
                     for (int j = i + 1; j < len; j++) {
                         if (number[i] + number[j] == target) {
                            sol[0] = i + 1;
                            sol[1] = j + 1;
                            break;
                         }
                     }
                 }
                 return sol;
             }
};

typedef struct node{
      int idx;
      int val;
} Node;

class Solution_Onlgn {
      public:
             vector<int> twoSum(vector<int> &numbers, int target) {
                 vector<int> sol(2);
                 vector<Node> num;
                 int len = numbers.size();
                 
                 for (int i = 0; i < len; i++) {
                     Node temp;
                     temp.idx = i + 1;
                     temp.val = numbers[i];
                     num.push_back(temp);
                 }
                 
                 sort(num, 0, len-1);
                 
                 for (int i = 0, j = len - 1; i < j;) {
                     int sum;
                     if ((sum = num[i].val + num[j].val) == target) {
                        sol[0] = num[i].idx < num[j].idx? num[i].idx: num[j].idx;
                        sol[1] = num[i].idx > num[j].idx? num[i].idx: num[j].idx;
                        break;
                     }
                     else if (sum < target)
                             i++;
                          else j--;
                 }
                 
                 return sol;
             }
             
             void swap(Node &a, Node &b) {
                  Node temp = a;
                  a = b;
                  b = temp;
             }
             
             int partition(vector<Node> &a, int l, int r)
             {
                  int povitpos = l, povit = a[l].val;
                  for (int i = l+1; i <= r; i++) {
                      if (a[i].val <= povit) {
                         povitpos++;
                         if (povitpos != i)
                            swap(a[i], a[povitpos]);
                      }
                  }
                  swap(a[l], a[povitpos]);
                  return povitpos;
             }
             
             void sort(vector<Node> &a, int l, int r)
             {
                  if (l < r) {
                     int i = partition(a, l, r);
                     sort(a, l, i-1);
                     sort(a, i+1, r);
                  }
             }
             
};

class Solution_On {
      public:
             vector<int> twoSum(vector<int> &numbers, int target) {
                 vector<int> sol(2);
                 int len = numbers.size();
                 map<long long, int> mapping;
                 vector<long long> mul(len, 0); 
                 
                 for (int i = 0; i < len; i++) {
                     mul[i] = (target - numbers[i]) * numbers[i];
                     if (mapping[mul[i]] > 0) {
                        if (numbers[i] + numbers[mapping[mul[i]]-1] == target) {
                           sol[0] = mapping[mul[i]];
                           sol[1] = i + 1;
                           break;
                        }
                     }
                     else
                         mapping[mul[i]] = i + 1;       //mul值第一次出现时的下标 
                 }
                 return sol;
             }
};

int main()
{
    vector<int> number;
    number.push_back(2);
    number.push_back(7);
    number.push_back(11);
    number.push_back(15);
    
    Solution_On s;
    vector<int> sol = s.twoSum(number, 9);
    cout << sol[0] << " " << sol[1];
    system("pause");
    return 0;
}
