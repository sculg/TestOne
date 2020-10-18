//
//  57复杂链表的复制.h
//
//  Created by lg on 2020/6/24.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _7________h
#define _7________h
//复杂链表的复制
//输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，
//另一个特殊指针random指向一个随机节点），请对此链表进行深拷贝，并返回拷贝后的头结点
void nodeClone(RandomListNode *head) {
    RandomListNode *pNode = head;
    while (pNode != nullptr) {
        RandomListNode *pClone = new RandomListNode(pNode->label);
        pClone->next = pNode->next;
        pNode->next = pClone;
        pNode = pClone->next;
    }
}

void connectRandom(RandomListNode *head) {
    RandomListNode *pNode = head;
    while (pNode != nullptr) {
        RandomListNode *pClone = pNode->next;
        if (pNode->random) {
            pClone->random = pNode->random->next;
        }
        pNode = pClone->next;
    }
    
}
RandomListNode *reconnect(RandomListNode *head) {
    RandomListNode *pNode = head;
    RandomListNode *result = head->next;
    while (pNode != nullptr) {
        RandomListNode *pClone = pNode->next;
        pNode->next = pClone->next;
        pNode = pNode->next;
        if (pNode != nullptr) {
            pClone->next = pNode->next;
        }
    }
    return result;
}

RandomListNode* Clone(RandomListNode* pHead) {
    if (pHead == nullptr) {
        return nullptr;
    }
    nodeClone(pHead);
    connectRandom(pHead);
    return reconnect(pHead);
}

#endif /* _7________h */
