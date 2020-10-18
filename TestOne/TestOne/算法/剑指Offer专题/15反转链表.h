//
//  14反转链表.h
//
//  Created by lg on 2020/6/16.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _4_____h
#define _4_____h

//反转链表
//输入一个链表，反转链表后，输出新链表的表头。

ListNode* ReverseList(ListNode* pHead) {
    ListNode* ReversedNode = nullptr;
    ListNode* curNode = pHead;
    while (curNode!= nullptr) {
        ListNode* temp = curNode->next;
        curNode->next = ReversedNode;
        ReversedNode = curNode;
        curNode = temp;
    }
    return ReversedNode;
}

#endif /* _4_____h */
