//
//  83. 删除排序链表中的重复元素.h
//
//  Created by lg on 2020/8/9.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _3_______________h
#define _3_______________h

ListNode* deleteDuplicates(ListNode* head) {
    if(head == nullptr) {
        return nullptr;
    }
    ListNode* header = new ListNode(0);
    header->next = head;
    ListNode* cur = head;
    while(cur->next != nullptr) {
        if(cur->val != cur->next->val) {
            cur = cur->next;
        } else {
            cur->next = cur->next->next;
        }
    }
    return header->next;
}

#endif /* _3_______________h */
