//
//  44删除链表中重复的结点.h
//
//  Created by lg on 2020/6/19.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _4___________h
#define _4___________h
//删除链表中重复的结点
//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
ListNode* deleteDuplication(ListNode* pHead) {
   
    if (pHead == nullptr) {
        return nullptr;
    }
    
    ListNode* curNode = pHead; //当前处理的节点
    ListNode *preNode = nullptr; //指向前面最晚访问过的不重复结点
    ListNode *laterNode = nullptr; //指向当前处理结点后面结点
    while (curNode != nullptr) {
        if (curNode->next != nullptr && curNode->next->val == curNode->val) {
            laterNode = curNode->next;
            while (laterNode!=nullptr && laterNode->next!=nullptr && laterNode->next->val == curNode->val) {
                laterNode = laterNode->next;
            }
            //如果是链表头
            if (curNode == pHead) {
                pHead = laterNode->next;
            } else {
                preNode->next = laterNode->next;
            }
            curNode = laterNode->next;
        } else {
            preNode = curNode;
            curNode = curNode->next;
        }
    }
    return pHead;
}
#endif /* _4___________h */
