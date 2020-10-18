//
//  145. 二叉树的后序遍历.h
//
//  Created by lg on 2020/8/9.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _45___________h
#define _45___________h

//方法一递归
vector<int> result;
vector<int> postorderTraversal(TreeNode* root) {
    dfs(root);
    return result;
}
void dfs(TreeNode* root) {
    if(root == nullptr) {
        return;
    }
    dfs(root->left);
    dfs(root->right);
    result.push_back(root->val);
}

//方法二 前序遍历 逆转
vector<int> result;
vector<int> postorderTraversal(TreeNode* root) {
    stack<TreeNode*> stk;
    if (root) stk.push(root);
    vector<int> ans;
    while (!stk.empty()) {
        TreeNode* cur = stk.top(); stk.pop();
        ans.push_back(cur->val);
        if (cur->left) stk.push(cur->left);
        if (cur->right) stk.push(cur->right);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}


//方法三 非递归
vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        if (root) stk.push(root);
        vector<int> ans;
        while (!stk.empty()) {
            TreeNode* cur = stk.top();
            if (!cur) {
                stk.pop();
                ans.emplace_back(stk.top()->val);
                stk.pop();
                continue;
            }
            stk.emplace(nullptr);
            if (cur->right) stk.push(cur->right);
            if (cur->left) stk.push(cur->left);
        }
        return ans;
    }

作者：Gary_coding
链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal/solution/c-zhong-gui-zhong-ju-de-0msjie-fa-di-gui-fei-di-gu/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
#endif /* _45___________h */
