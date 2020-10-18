//
//  链表中倒数第k个结点.h
//
//  Created by lg on 2020/6/16.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef ______k____h
#define ______k____h

//链表中倒数第k个结点
//输入一个链表，输出该链表中倒数第k个结点。

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    
    if (pListHead == nullptr || k == 0) {
        return nullptr;
    }
    ListNode* slow = pListHead;
    ListNode* fast = pListHead;
    for (int i = 0; i< k-1; i++) {//注意这里是k-1
        if (fast->next != nullptr) {
            fast = fast->next;
        } else {
            return nullptr;
        }
    }
    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
#endif /* ______k____h */
