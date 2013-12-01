/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
using namespace std;

typedef struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
} ListNode;

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head1 = l1, *head2 = l2, *head3 = NULL, *l3 = NULL;
        int carry = 0;
        while (head1 != NULL && head2 != NULL) {
              int sum = head1 -> val + head2 -> val + carry;
              carry = sum >= 10 ? 1 : 0;
             // l3 = new ListNode(sum % 10);
              if (head3 == NULL) {
                 head3 = new ListNode(sum % 10);
                 l3 = head3;
              }
              else {
                   l3 -> next = new ListNode(sum % 10);
                   l3 = l3 -> next;
              }
              head1 = head1 -> next;
              head2 = head2 -> next;
        }
        if (head1 == NULL && head2 == NULL) {
           if (carry) {
              l3 -> next = new ListNode(carry);
           }
           return head3;
        }
        else
             head1 = (head1 == NULL ? head2 : head1);
        while (head1 != NULL) {
              int sum = head1 -> val + carry;
              carry = sum >= 10 ? 1 : 0;
              l3 -> next = new ListNode(sum % 10);
              l3 = l3 -> next;
              head1 = head1 -> next;
        }
        if (carry) {
              l3 -> next = new ListNode(carry);
        }
        return head3;
    }
    
    ListNode *addTwoNumbersPromoted(ListNode *l1, ListNode *l2) {
        ListNode *head1 = l1, *head2 = l2, *head3 = NULL, *l3 = NULL;
        int carry = 0;

        while (head1 || head2|| carry) {
              int val1 = head1 == NULL? 0 : head1 -> val;
              int val2 = head2 == NULL? 0 : head2 -> val; 
              int sum = val1 + val2 + carry;
              carry = sum >= 10 ? sum/10 : 0;
              if (head3 == NULL) {
                 head3 = new ListNode(sum % 10);
                 l3 = head3;
              }
              else {
                   l3 -> next = new ListNode(sum % 10);
                   l3 = l3 -> next;
              }
              head1 = head1 == NULL? NULL : head1 -> next;
              head2 = head2 == NULL? NULL : head2 -> next;
        }
        return head3;
    }
};

void printList(ListNode *head)
{
     ListNode *p = head;
     while (p != NULL) {
           cout << p -> val << " ";
           if (p->next != NULL)
              cout << "-> ";
           p = p -> next;
     }
}

int main()
{
    ListNode l11(2), l12(4);
    ListNode l21(5), l22(6), l23(4);
    
    l11.next = &l12;
    
    l21.next = &l22;
    l22.next = &l23;
    ListNode *p1 = &l11;
    ListNode *p2 = &l21;
    Solution s;
    ListNode *p3 = s.addTwoNumbersPromoted(p1, p2);
    printList(p3);
    system("pause");
    return 0;
}
