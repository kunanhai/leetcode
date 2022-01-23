#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        ListNode *tmp;
        while (cur != nullptr) {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }

        head = pre;
        return head;
    }

    void printList(ListNode *head) {
        ListNode *cur = head;
        while (cur != nullptr) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dumyHead = new ListNode(0, head);
        ListNode *slow = dumyHead;
        ListNode *tmp;
        ListNode *fast = slow;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        while(fast != nullptr) {
            tmp = slow;
            slow = slow->next;
            fast = fast->next;
        }

        tmp->next = slow->next;

        return dumyHead->next;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
/*         ListNode *a = headA;
        ListNode *b = headB;
        while(a != nullptr) {
            b = headB;
            while (b != nullptr) {
                if (a == b) {
                    return b;
                } else {
                    b = b->next;
                }
            }
            a = a->next;
        }

        return nullptr; */

        int lenA = 0;
        int lenB = 0;
        ListNode *curA = headA;
        ListNode *curB = headB;
        while (curA != nullptr) {
            lenA++;
            curA = curA->next;
        }

        while (curB != nullptr) {
            lenB++;
            curB = curB->next;
        }

        curA = headA;
        curB = headB;
        if (lenA < lenB) {
            int offset = lenB - lenA;
            for (int i = 0; i < offset; i++) {
                curB = curB->next;
            }
        }

        if (lenA > lenB) {
            int offset = lenA - lenB;
            for (int i = 0; i < offset; i++) {
                curA = curA->next;
            }
        }

        while(curA != nullptr) {
            if (curA == curB) {
                return curB;
            }  else {
                curA = curA->next;
                curB = curB->next;
            }
        }

        return nullptr;
    }
    ListNode *detectCycle(ListNode *head) {

        if (head->next == nullptr) {
            return nullptr;
        }

        ListNode *slow = head;
        ListNode *fast = slow;
        while (fast != nullptr && fast->next != nullptr) {

            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                ListNode *index1 = fast;
                ListNode *index2 = head;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }

                return index1;
            }
        }
        return nullptr;  
    }
};

int main() {
    Solution sol;
    ListNode *head;
    ListNode *A = new ListNode(1);
    ListNode *B = new ListNode(2);
    ListNode *C = new ListNode(3);
    ListNode *D = new ListNode(4);
    ListNode *E = new ListNode(5);
    head = A;
    A->next = B;
    B->next = C;
    C->next = D;
    D->next = E;
    sol.printList(head);
    head = sol.reverseList(head);
    sol.printList(head);
}