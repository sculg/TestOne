//
//  25二叉搜索树的后序遍历序列.h
//
//  Created by lg on 2020/6/17.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _5_____________h
#define _5_____________h

//二叉搜索树的后序遍历序列
//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
bool VerifySquenceOfBST1(vector<int> sequence,int startIndex, int endIndex) {
      
      if (sequence.empty()|| startIndex > endIndex) {
          return false;
      }
      
      int root = sequence[endIndex];
      int i = startIndex;
      for (; i<endIndex; i++) {
          if (sequence[i]>root) {
              break;
          }
      }
      for (int j = i + 1; j<endIndex; j++) {
          if (sequence[j] < root) {
              return false;
          }
      }
      bool left = true;
      if (i>startIndex) {
          left = VerifySquenceOfBST1(sequence,startIndex,i-1);
      }
      bool right = true;
      if (i<endIndex) {
          right = VerifySquenceOfBST1(sequence,i+1,endIndex);
      }
      return left&&right;
  }
  
  bool VerifySquenceOfBST(vector<int> sequence) {
      if (sequence.empty()) {
          return false;
      }
      //下表双指针，进行判断
      return VerifySquenceOfBST1(sequence,0,sequence.size()-1);
  }
#endif /* _5_____________h */
