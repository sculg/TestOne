//
//  21. 合并两个有序链表.h
//
//  Created by lg on 2020/7/29.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _1___________h
#define _1___________h

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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (l1 != nullptr && l2 != nullptr) {
            ListNode** pp = (l1->val < l2->val) ? &l1 : &l2;
            cur->next = *pp;
            cur = cur->next;
            *pp = (*pp)->next;
        }
        cur->next = (l1 == nullptr) ? l2 : l1;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }

作者：ikaruga
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists/solution/merge-two-sorted-lists-by-ikaruga/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

#endif /* _1___________h */
