//
//  349. 两个数组的交集.h
//
//  Created by lg on 2020/6/29.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _49__________h
#define _49__________h

//349. 两个数组的交集
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set;
    unordered_set<int> nums1_set(nums1.begin(),nums1.end());
    for(int num : nums2) {
        if(nums1_set.count(num) == 1) {
            set.insert(num);
        }
    }
    return vector<int>(set.begin(),set.end());
}

//unodered_set 相关使用
//查找函数 find() 通过给定主键查找元素
unordered_set<int>::iterator find_iter = c1.find(1);
//value出现的次数 count() 返回匹配给定主键的元素的个数
c1.count(1);
//返回元素在哪个区域equal_range() 返回值匹配给定搜索值的元素组成的范围
pair<unordered_set<int>::iterator, unordered_set<int>::iterator> pair_equal_range = c1.equal_range(1);
//插入函数 emplace()
c1.emplace(1);
//插入函数 emplace_hint() 使用迭代器
c1.emplace_hint(ite_begin, 1);
//插入函数 insert()
c1.insert(1);
//删除 erase()
c1.erase(1);//1.迭代器 value 区域
//清空 clear()
c1.clear();
//交换 swap()
c1.swap(c2);

#endif /* _49__________h */
