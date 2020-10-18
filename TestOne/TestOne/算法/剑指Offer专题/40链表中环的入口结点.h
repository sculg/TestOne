//
//  40链表中环的入口结点.h
//
//  Created by lg on 2020/6/18.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _0__________h
#define _0__________h

//链表中环的入口结点
//给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
ListNode* EntryNodeOfLoop(ListNode* pHead) {
    ListNode* fastNode = pHead;
    ListNode* slowNode = pHead;
    ListNode* meetNode = nullptr;
    while (fastNode != nullptr ) {
        fastNode = fastNode->next;
        slowNode = slowNode->next;
        if (fastNode==nullptr) {
            return nullptr;
        }
        fastNode = fastNode->next;
        if (fastNode == slowNode) {
            meetNode = fastNode;
            break;
        }
    }
    if (meetNode == nullptr) {
        return nullptr;
    }
    
    while (pHead != nullptr && meetNode != nullptr) {
        if (pHead == meetNode) {
            return pHead;
        }
        pHead = pHead->next;
        meetNode = meetNode->next;
    }
    return nullptr;
}

#endif /* _0__________h */
