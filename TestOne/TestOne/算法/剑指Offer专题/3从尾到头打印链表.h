//
//  printListFromTailToHead.h
//
//  Created by lg on 2020/6/14.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef printListFromTailToHead_h
#define printListFromTailToHead_h
//从尾到头打印链表

//输入一个链表，按链表从尾到头的顺序返回一个ArrayList。

vector<int> printListFromTailToHead(ListNode* head) {
    stack<int> stack;
    vector<int> result;
    ListNode* p = head;
    while (p != nullptr) {
        stack.push(p->val);
        p = p->next;
    }
    int len = stack.size();
    for (int i = 0; i<len; i++) {
        result.push_back(stack.top());
        stack.pop();
    }
    return result;
}


#endif /* printListFromTailToHead_h */
