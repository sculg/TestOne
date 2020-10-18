//
//  19. 删除链表的倒数第N个节点.h
//
//  Created by lg on 2020/7/29.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _9__________N____h
#define _9__________N____h

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head == nullptr) return head;
    //创建一个头节点用于防止删除的是第一个节点的情况
    ListNode* header = new ListNode(0);
    header->next = head;
    ListNode *fastNode = header;
    ListNode *slowNode = header;
    int i = 0;
    for (int i = 0; i <= n; i++) {
        if(fastNode != nullptr) {
            fastNode = fastNode->next;
        } else {
            return nullptr;
        }
    }
    while (fastNode != nullptr) {
        fastNode = fastNode->next;
        slowNode = slowNode->next;
    }
    slowNode->next = slowNode->next->next;
    return header->next;
}

#endif /* _9__________N____h */
