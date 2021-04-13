//
//  main.cpp
//
//  Created by lg on 2019/7/27.
//  Copyright © 2019 sculg. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <list>
using namespace std;

struct ListNode {
    ListNode* next;
    int val;
};

struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

 struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
    
public:
       int searchBin(int array[],int low,int high,int target) {
           if (array == nullptr || low > high) {
               return -1;
           }
           while (low <= high) {
               int middle = low + (high-low)/2;
               if (array[middle] == target) {
                   std::cout<<low<<endl;
                   std::cout<<high<<endl;
                   return middle;
               }
               else if (array[middle] > target) {
                   high = middle-1;
               } else {
                   low = middle+1;
               }
           }
           return -1;
       }
    
    int StrToInt(char *string) {
        int num = 0;
        if (string == NULL || *string == '\0') {
            return -1;
        }
        char *temp = string;
        int flag = 1;
        if (*temp == '+') {
            flag = 1;
            temp++;
        } else if (*temp == '-') {
            flag = -1;
            temp++;
        }
        while (*temp !='\0') {
            if(*temp >='0' && *temp <= '9' ) {
                num = num*10 + *temp - '0';
            }
            else {
                return -1;
            }
            temp++;
        }
        return num*flag;
    }
    
    void InsertBST(TreeNode* &t, int key) {
        TreeNode* temp = NULL;
        //先判断节点是否存在，如果不存在，则新建节点
        if (t == NULL) {
            temp = new TreeNode(0);
            temp->left = temp->right = NULL;
            temp->val = key;
            t = temp;
            return;
        }
        //新插入的点总是叶子节点，不能插在中间
        if (key < t->val) {
            InsertBST(t->left, key);//key小，则插入左子树
        }
        else if(key > t->val) {
            InsertBST(t->right, key);//key大，则插入右子树，key等于根节点则不插入
        }
    }
     
     
    //创建二叉排序树,data是数组名，n是数组长度
    TreeNode* CreateBiTree(TreeNode* tree,int data[],int n) {
        for (int i = 0; i < n; i++) {
            InsertBST(tree, data[i]);
        }
        return tree;
    }
     
     
    //删除二叉树,tree为根节点
    void DelBiTree(TreeNode* tree) {
        if (tree) {
         DelBiTree(tree->left);
         DelBiTree(tree->right);
         delete tree;
        }
    }
     
     
    //先序遍历
    void PreOrder(TreeNode* tree) {
        if (tree) {
            cout << tree->val << " ";
            PreOrder(tree->left);
            PreOrder(tree->right);
        }
    }
     
     
    //中序遍历
    void InOrder(TreeNode* tree) {
        if (tree) {
            InOrder(tree->left);
            cout << tree->val << " ";
            InOrder(tree->right);
        }
    }
     
     
    //后续遍历
    void PostOrder(TreeNode* tree) {
        if (tree) {
            PostOrder(tree->left);
            PostOrder(tree->right);
            cout << tree->val << " ";
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
            return new TreeNode(val);
        if(val > root -> val)
            root -> right = insertIntoBST(root -> right, val);
        else
            root -> left = insertIntoBST(root -> left, val);
        return root;
    }
    //B是否是A的子集
    bool isSub(vector<int> arrA, vector<int> arrB) {
        int lengthA = arrA.size();
        int lengthB = arrB.size();
        if(lengthA < lengthB || arrA[lengthA - 1] < arrB[lengthB - 1]) {
            return false;
        }
        int i = 0,j = 0;
        while (i < lengthA && j < lengthB) {
            if(arrA[i] == arrB[j]) {
                i++;
                j++;
            } else if (arrA[i] < arrB[j]) {
                i++;
            } else {
                return false;
            }
        }
        return true;
    }
    
    void reverseStr(string &str, int start, int end) {
        if(str.size() == 0) {
            return;
        }
        char temp = str[start];
        str[0] = str[end];
        str[end] = temp;
        reverseStr(str,++start,--end);
    }
    
    vector<int> findMaxAndMin(vector<int> &arr) {
        vector<int> result;
        if(arr.size() == 0) {
            return result;
        }
        if(arr.size() == 1) {
            result.push_back(arr[0]);
            result.push_back(arr[0]);
            return result;
        }
        for(int i = 0;i<arr.size();i = i + 2) {
            if(arr[i] < arr[i+1]) {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
        int max = 0;
        for (int i = 0; i < arr.size(); i = i+2) {
            if(max < arr[i]) {
                max = arr[i];
            }
        }
        int min = 0;
        for (int i = 1; i < arr.size(); i = i+2) {
            if(min > arr[i]) {
                min = arr[i];
            }
        }
        result.push_back(max);
        result.push_back(min);
        return result;
    }
    int minNumber(vector<int> arr,int target) {
        if(arr.size() == 0) {
            return 0;
        }
        vector<int> dp(target + 1,-1);
        for (int i = 0; i<arr.size(); i++) {
            if(arr[i] == target) {
                return 1;
            }
            dp[arr[i]] = 1;
        }
        for (int i = 1; i<=target; i++) {
            for (int j = 0; j < arr.size(); j++) {
                if(i-arr[j] >= 0 && dp[i-arr[j]] != -1) {
                    if(dp[i] == -1 || dp[i] > dp[i-arr[j]] + 1) {
                        dp[i] = dp[i-arr[j]] + 1;
                    }
                }
            }
        }
        return dp[target];
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double result;
        vector<int> temp;
        int nums1Length = nums1.size();
        int nums2Length = nums2.size();
        int leftIndex = 0;
        for (int i = 0; i < nums2Length; i++) {
            while(leftIndex < nums1Length && nums1[leftIndex] <= nums2[i]) {
                temp.push_back(nums1[leftIndex]);
                leftIndex++;
            }
            temp.push_back(nums2[i]);
        }
        while(leftIndex < nums1Length) {
            temp.push_back(nums1[leftIndex]);
            leftIndex++;
        }
        if(temp.size() & 0x01) {
            result = temp[temp.size()/2];
        } else {
            result = (double)(temp[(temp.size() + 1)/2] + temp[(temp.size() - 1)/2])/(double)2.0;
        }
        return result;
    }
    bool isValid(string s) {
        if(s.empty()) {
            return true;
        }
        stack<char> stack;
        for (int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] ==  '{' || s[i] =='[') {
                stack.push(s[i]);
            } else {
                if(stack.empty()){
                    return false;
                }
                char tem = stack.top();
                if((s[i] == ')' && tem == '(')|| (s[i] == ']' && tem == '[')||(s[i] == '}' && tem == '{')) {
                    stack.pop();
                } else {
                    return false;
                }
            }
        }
        if (stack.size() == 0) {
            return true;
        } else {
            return false;
        }
    }
    
    int strStr(string haystack, string needle) {
        if(haystack.size() < needle.size()) {
            return -1;
        }
        if(needle.size() == 0) {
            return 0;
        }
        int needleIndex = 0;
        int firstIndex = -1;
        for (int i = 0;i < haystack.size();i++) {
            if(needleIndex < needle.size()) {
                if(haystack[i] == needle[needleIndex]) {
                    if(firstIndex == -1) {
                        firstIndex = i;
                    }
                    needleIndex++;
                } else {
                    if(firstIndex != -1) {
                        i = firstIndex;
                        firstIndex = -1;
                        needleIndex = 0;
                    }
                }
            }
        }
        return needleIndex == needle.size()? firstIndex : -1;;
    }
    
    void quickSort(vector<int>& nums, int start, int end) {
        if(nums.size() == 0 || start >= end) {
            return;
        }
        int i = start;
        int j = end;
        int temp = nums[start];
        while(i < j) {
            while(i<j && nums[j] >= temp) {
                j--;
            }
            while(i<j && nums[i] <= temp) {
                i++;
            }
            swap(nums[i],nums[j]);
        }
        swap(nums[i],temp);
        quickSort(nums,start,i-1);
        quickSort(nums,i+1,end);
    }

    void nextPermutation(vector<int>& nums) {
        int rightIndex = nums.size()-1;
        while(rightIndex > 0) {
            if(nums[rightIndex] <= nums[rightIndex-1]) {
                rightIndex--;
            } else {
                break;
            }
        }
        if(rightIndex == 0) {
            int p = 0;
            int q = nums.size()-1;
            while(p<=q) {
                swap(nums[p++],nums[q--]);
            }
            return;
        }
        int j = rightIndex;
        int slected = nums[rightIndex - 1];
        while(nums[j] >= slected) {
            j++;
            if(j == nums.size()) break;
        }
        while(nums[j-1] == slected) {
            j--;
        }
        swap(nums[rightIndex-1],nums[j-1]);
        quickSort(nums,rightIndex,nums.size()-1);
    }
    
    string countAndSay(int n) {
        vector<string> dp(n+1);
        dp[0] = "1";
        for(int i = 1; i < n ; i++) {
            string str = dp[i-1];
            string tem = "";
            int count = 1;
            char temchar = str[0];
            for(int j = 1;j <=str.size();j++) {
                if(str[j] != temchar) {
                    tem.append(to_string(count));
                    tem.push_back(temchar);
                    temchar = str[j];
                    count = 1;
                } else {
                    count++;
                }
            }
            dp[i] = tem;
        }
        return dp[n-1];
    }
    
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int startOf1 = -1;
        for(int i = 0;i < nums.size(); i++) {
            if(nums[i] <= 0) {
                continue;
            } else if(startOf1 == -1) {
                startOf1 = i;
            } else {
                if(nums[i] != nums[startOf1] + 1) {
                    return nums[startOf1] + 1;
                } else {
                    startOf1 = i;
                }
            }
        }
        return nums[startOf1] + 1;
    }

};

//    如：[1, [2, [ [3, 4], 5], 6], 7] => [1, 2, 3, 4, 5, 6, 7]
//[1, [2, [ [3, 4], 5], 6], 7] => [1, 2, 3, 4, 5, 6, 7]

//
//}

int minEditCost(string str1, string str2, int ic, int dc, int rc) {
    // write code here
    int m = str1.size();
    int n = str2.size();
    int dp[m+1][n+1];
    dp[0][0] = 0;
    for(int i = 1;i <= m; i++) {
        dp[i][0] = dp[i-1][0] + dc;
    }
    for(int j = 1;j <= n; j++) {
        dp[0][j] = dp[0][j-1] + ic;
    }
    
    for(int i = 1;i <= m; i++) {
        for(int j = 1;j <= n; j++) {
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                int ins = dp[i][j-1] + ic;
                int del = dp[i-1][j] + dc;
                int rep = dp[i-1][j-1] + rc;
                dp[i][j] = min(ins,min(del,rep));
            }
        }
    }
    return dp[m][n];
}


int main(int argc, const char * argv[]) {

    
    
    int array[] = {1,2,0};
//    int array2[] = {2};
//    int len = sizeof(array)/sizeof(int);
//    cout<<"The orginal array are:"<<endl;
//    for(int i=0; i<len; ++i)
//    {
//        cout<< array[i] << " ";
//    }
//    cout<<endl;
    vector<int> vect1(array,array+sizeof(array)/sizeof(int));
//    vector<int> vect2(array2,array2+sizeof(array2)/sizeof(int));

    int result = Solution().firstMissingPositive(vect1);
//    int result = Solution().GetUglyNumber_Solution(20);"mississippi""pi"
//    cout<<result<<endl;
    
//    int arr[] = {1,3,4,5,16,17,29};
//    int index = Solution().searchBin(arr, 0, 6, 4);
//    std::cout<<index<<endl;
//    struct student {
//        char a;
//        int b;
////        int c;
//    };
    
//    char str[] = "12p4";
//    int intAfterConvert = Solution().StrToInt(str);
//    std::cout<<sizeof(student)<<endl;
    
    // insert code here...


//    -
    
    
    return 0;
}

