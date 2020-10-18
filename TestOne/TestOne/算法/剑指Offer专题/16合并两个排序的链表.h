//
//  16合并两个排序的链表.h
//
//  Created by lg on 2020/6/16.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _6__________h
#define _6__________h

//合并两个排序的链表

//输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    if (pHead1 == nullptr) {
        return pHead2;
    } else if(pHead2 == nullptr) {
        return pHead1;
    }
    ListNode* pHeadResult = nullptr;
    if (pHead1->val >= pHead2->val) {
        pHeadResult = pHead2;
        pHeadResult->next = Merge(pHead1,pHead2->next);
    } else {
        pHeadResult = pHead1;
        pHeadResult->next = Merge(pHead1->next,pHead2);
    }
    return pHeadResult;
}
#endif /* _6__________h */
