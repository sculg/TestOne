//
//  257. 二叉树的所有路径.h
//
//  Created by lg on 2020/8/9.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _57___________h
#define _57___________h

vector<string> result;
string temp;
vector<string> binaryTreePaths(TreeNode* root) {
    if(root == nullptr) {
        return result;
    }
    binaryTreePaths(root,temp);
    return result;
}
void binaryTreePaths(TreeNode* root,string path) {
    if(root == nullptr) {
        return;
    }
    path.append(to_string(root->val));
    path.append("->");
    if(root->left == nullptr && root->right == nullptr) {
        path.erase(path.length()-2);
        result.push_back(path);
    }
    binaryTreePaths(root->left,path);
    binaryTreePaths(root->right,path);
}

#endif /* _57___________h */
