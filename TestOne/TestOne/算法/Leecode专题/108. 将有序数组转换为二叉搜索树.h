//
//  108. 将有序数组转换为二叉搜索树.h
//
//  Created by lg on 2020/8/8.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _08________________h
#define _08________________h

TreeNode* sortedArrayToBST(vector<int>& nums) {
    if(nums.size() == 0) {
        return nullptr;
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

#endif /* _08________________h */
