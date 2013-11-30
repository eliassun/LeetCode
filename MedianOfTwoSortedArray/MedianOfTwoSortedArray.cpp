#include <iostream>
using namespace std;
class Solution {
      public:
             double findMedianSortedArrays(int A[], int m, int B[], int n) {
                    int *p = new int[m+n];
                    int i(0), j(0), idx(0);
                    while (i < m && j < n) {
                          if (A[i] <= B[j])
                             p[idx++] = A[i++];
                          else p[idx++] = B[j++];
                    }
                    while (i < m) p[idx++] = A[i++];
                    while (j < n) p[idx++] = B[j++];
                    
                    for (int l = 0; l < m+n; l++)
                        cout << p[l] << " " << endl;
                    
                    double median =  ((m + n)%2 ? p[(m+n) >> 1] : (((double)p[(m+n-1) >> 1] + (double)p[(m+n) >> 1]))/2);
                    delete p;
                    return median;
             }
};

int main()
{
    int a[] = {};
    int b[] = {1};
    Solution s;
    cout << s.findMedianSortedArrays(a, 0, b, 1);
    system("pause");
    return 0;
}
