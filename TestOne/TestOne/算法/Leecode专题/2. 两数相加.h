//
//  2. 两数相加.h
//
//  Created by lg on 2020/8/4.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef ________h
#define ________h

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *head = new ListNode(-1);
    ListNode *h = head;
    int sum = 0;
    int carray = 0;
    while(l1 || l2 || carray) {
        int val1 = l1 ? l1->val : 0;
        int val2 = l2 ? l2->val : 0;
        sum = val1 + val2 + carray;
        carray = sum / 10;
        ListNode *node = new ListNode(sum %10 );
        h->next = node;
        h = node;
        if(l1) {
            l1 = l1->next;
        }
        if(l2) {
            l2 = l2->next;
        }
    }
    return head->next;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* resultNode = new ListNode(0);
    ListNode* cur = resultNode;
    int carry = 0;
    while(l1!=NULL || l2!=NULL) {
        int a = (l1!=0?l1->val:0);
        int b = (l2!=0?l2->val:0);
        int sum = a + b + carry;
        carry = sum/10;
        cur->next = new ListNode(sum%10);
        cur = cur->next;
        if(l1!=NULL) l1 = l1->next;
        if(l2!=NULL) l2 = l2->next;
    }
    if(carry>0) {
        cur->next = new ListNode(carry);
    }
    return resultNode->next;
}

#endif /* ________h */
