//
//  206. 反转链表.h
//
//  Created by lg on 2020/8/5.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _06_______h
#define _06_______h

ListNode* reverseList(ListNode* head) {
    ListNode *pre = nullptr;
    ListNode *cur = head;
    while(cur != nullptr) {
        ListNode *temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    return pre;
}

#endif /* _06_______h */
