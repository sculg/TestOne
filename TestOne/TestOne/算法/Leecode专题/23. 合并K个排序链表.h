//
//  23. 合并K个排序链表.h
//
//  Created by lg on 2020/8/9.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _3____K______h
#define _3____K______h

//方法一
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* resultNode = nullptr;
    if(l1 == nullptr) {
        return l2;
    }
    if(l2 == nullptr) {
        return l1;
    }
    if(l1->val >= l2->val) {
        resultNode = l2;
        resultNode -> next = mergeTwoLists(l1,l2->next);
    } else {
        resultNode = l1;
        resultNode -> next = mergeTwoLists(l2,l1->next);
    }
    return resultNode;
}

//方法二
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;
    int n = lists.size();
    ListNode *res = lists[0];
    for (int i = 1; i < n; ++i) {
        res = mergeTwoLists(res, lists[i]);
    }
    return res;

}

#endif /* _3____K______h */
