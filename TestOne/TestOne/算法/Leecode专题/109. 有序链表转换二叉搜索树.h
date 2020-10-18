//
//  109. 有序链表转换二叉搜索树.h
//
//  Created by lg on 2020/8/8.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _09______________h
#define _09______________h

//方法一 块慢指针
TreeNode* sortedListToBST(ListNode* head) {
    return buildTree(head, nullptr);
}
TreeNode * buildTree(ListNode* head, ListNode * tail){
    if(head == tail) return nullptr;
    ListNode* slow = head, *fast = head;
    while(fast != tail && fast->next != tail){
        slow = slow->next;
        fast = fast->next->next;
    }
    TreeNode * root = new TreeNode(slow->val);
    root->left = buildTree(head, slow);
    root->right = buildTree(slow->next, tail);
    return root;
}

//方法一 链表转数组
TreeNode* sortedListToBST(ListNode* head) {
    vector<int> nums;
    while(head != nullptr) {
        nums.push_back(head->val);
        head = head->next;
    }
    return helper(nums,0,nums.size() - 1);
}

TreeNode* helper(vector<int>& nums,int start, int end) {
    if(start > end) {
        return nullptr;
    }
    int mid = (start + end + rand()%2)/2;
    TreeNode *rootNode = new TreeNode(nums[mid]);
    rootNode->left = helper(nums,start,mid-1);
    rootNode->right = helper(nums,mid + 1,end);
    return rootNode;
}


#endif /* _09______________h */
