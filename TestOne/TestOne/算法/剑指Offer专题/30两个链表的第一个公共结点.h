//
//  两个链表的第一个公共结点.h
//
//  Created by lg on 2020/6/18.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _____________h
#define _____________h
//两个链表的第一个公共结点
//输入两个链表，找出它们的第一个公共结点。（注意因为传入数据是链表，所以错误测试数据的提示是用其他方式显示的，保证传入数据是正确的）
int GetLengthOfNode(ListNode* node) {
    int count = 0;
    ListNode *pNode = node;
    while (pNode!=nullptr) {
        count++;
        pNode = pNode->next;
    }
    return count;
}

ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
    if (pHead1 == nullptr || pHead2 == nullptr) {
        return nullptr;
    }
    int length1 = GetLengthOfNode(pHead1);
    int length2 = GetLengthOfNode(pHead2);
    int distance;
    ListNode* pFast;
    ListNode* pSlow;
    if (length1>= length2) {
        distance = length1-length2;
        pFast = pHead1;
        pSlow = pHead2;
    } else {
        distance = length2-length1;
        pFast = pHead2;
        pSlow = pHead1;
    }
    while (distance > 0) {
        pFast = pFast->next;
        distance--;
    }
    //注意终止条件是两个链表节点相同且两个链表均不为空，这个必须判断
    while (pFast!=nullptr && pSlow != nullptr) {
        if (pFast == pSlow) {
            break;
        }
        pFast = pFast->next;
        pSlow = pSlow->next;
    }
    return pFast;
}
#endif /* _____________h */
