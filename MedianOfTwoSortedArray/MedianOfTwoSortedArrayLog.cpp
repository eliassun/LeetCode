#include <iostream>
using namespace std;
double findKth(int a[], int m, int b[], int n, int k)  
{  
    if (m > n) return findKth(b, n, a, m, k);
    if (m == 0) return b[k - 1];
    if (k == 1) return a[0] > b[0] ? b[0] : a[0];
    
    int pa = k/2 > m ? m : k/2;
    int pb = k - pa;              //pa + pb = k
    if (a[pa - 1] < b[pb - 1])
       return findKth(a + pa, m - pa, b, n, k - pa);
    else if (a[pa - 1] > b[pb - 1])
            return findKth(a, m, b + pb, n - pb, k - pb);
    else return a[pa - 1];
}  

class Solution {
      public:
             double findMedianSortedArrays(int A[], int m, int B[], int n) {
                    int len = m + n;
                    if (len % 2)
                       return findKth(A, m, B, n, (len  >> 1) + 1);
                    else return (findKth(A, m, B, n, len >> 1) + findKth(A, m, B, n, (len >> 1) + 1)) / 2;
             }
};

int main()
{
    int a[] = {100001};
    int b[] = {100000};
    Solution s;
    cout << s.findMedianSortedArrays(a, 1, b, 1);
    system("pause");
    return 0;
}
