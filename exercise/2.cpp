//链表逆序问题
//解决方法：三指针头插法

#include <stdio.h>

struct ListNode{
    int value;
    ListNode* next;
    ListNode(int x):value(x),next(NULL){}
};

//解法1：自己想的方法，也是三指针
//ListNode* reverseList(ListNode* head){
    //ListNode* pre = head;
    //ListNode* current = pre->next;
    //ListNode* Next;

    //while(current){
        //Next = current->next;
        //current->next = pre;
        //pre = current;
        //current = Next;
    //}
    //head->next = NULL;
    //head = pre;
    //return head;
//}

//头插法，更简单
ListNode* reverseList(ListNode* head){
    ListNode* new_head = NULL;
    while(head){
        ListNode* next = head->next;
        head->next = new_head;
        new_head = head;
        head = next;
    }
    return new_head;
}

int main(){
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;


    ListNode *head = &a;
    
    printf("before reverse: \n");
    while(head){
        printf("%d ",head->value);
        head = head->next;
    }

    //head = solve.reverseList(head);
    head = reverseList(&a);
    printf("\nafter reverse:\n");
    while(head){
        printf("%d ",head->value);
        head = head->next;
    }    
}