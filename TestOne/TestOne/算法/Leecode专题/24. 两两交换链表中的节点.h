//
//  24. 两两交换链表中的节点.h
//
//  Created by lg on 2020/7/30.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _4_____________h
#define _4_____________h

ListNode* swapPairs(ListNode* head) {
    if(head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode* secondNode = head->next;
    ListNode* tempNode = secondNode->next;
    secondNode->next = head;
    head->next = swapPairs(tempNode);
    return secondNode;
}

ListNode* swapPairs(ListNode* head) {
    if(head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode* first = head;
    ListNode* secondNode = head->next;
    ListNode* tem = nullptr;
    first->next = secondNode->next;
    secondNode->next = first;
    head = secondNode;
    while (first->next != nullptr) {
        tem = first;
        first = first->next;
        if(first->next == nullptr) {
            break;
        }
        secondNode = first->next;
        tem->next = secondNode;
        first->next = secondNode->next;
        secondNode->next = first;
    }
    return head;
}

#endif /* _4_____________h */
