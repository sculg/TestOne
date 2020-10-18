//
//  25. K 个一组翻转链表.h
//
//  Created by lg on 2020/8/9.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _5__K_________h
#define _5__K_________h

ListNode* reverseKGroup(ListNode* head, int k) {
    if(head == nullptr) {
        return nullptr;
    }
    ListNode *a = head;
    ListNode *b = head;
    for (int i = 0; i < k;i++) {
        if(b == nullptr) {
            return head;
        }
        b = b->next;
    }
    ListNode *newNode = reverseKGroup1(a,b);
    a->next = reverseKGroup(b,k);
    return newNode;
}
ListNode* reverseKGroup1(ListNode* start,ListNode* end) {
    ListNode *pre,*cur,*later;
    pre = nullptr;
    cur = start;
    later = start;
    while(cur != end) {
        later = cur->next;
        cur->next = pre;
        pre = cur;
        cur = later;
    }
    return pre;
}

#endif /* _5__K_________h */
