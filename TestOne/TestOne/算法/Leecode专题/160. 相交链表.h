//
//  160. 相交链表.h
//
//  Created by lg on 2020/8/4.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _60_______h
#define _60_______h

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lengthA = 0;
    int lengthB = 0;
    ListNode *hA = headA;
    ListNode *hB = headB;
    while(hA) {
        hA = hA->next;
        lengthA++;
    }
    while(hB) {
        hB = hB->next;
        lengthB++;
    }
    int distance;
    if(lengthA > lengthB) {
        distance = lengthA-lengthB;
        while(distance>0) {
            headA = headA->next;
            distance--;
        }
    } else {
        distance = lengthB-lengthA;
        while(distance>0) {
            headB = headB->next;
            distance--;
        }
    }
    ListNode *result = nullptr;
    while(headA !=nullptr && headB != nullptr) {
        if(headA == headB) {
            result = headA;
            return result;
        }
        headA = headA->next;
        headB = headB->next;
    }
    return result;
}

#endif /* _60_______h */
