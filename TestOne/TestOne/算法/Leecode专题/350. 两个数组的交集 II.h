//
//  350. 两个数组的交集 II.h
//
//  Created by lg on 2020/6/29.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _50__________II_h
#define _50__________II_h

//350. 两个数组的交集 II
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int,int> map;
    vector<int> result;
    for(int i = 0;i<nums1.size();i++) {
        map[nums1[i]]++;
    }
    for(int i = 0;i<nums2.size();i++) {
        if(map[nums2[i]] > 0) {
            result.push_back(nums2[i]);
            map[nums2[i]]--;
        }
    }
    return result;
}

//map：
//优点：有序性，这是map结构最大的优点，其元素的有序性在很多应用中都会简化很多的操作红黑树，内部实现一个红黑书使得map的很多操作在lgn的时间复杂度下就可以实现，因此效率非常的高
//缺点： 空间占用率高，因为map内部实现了红黑树，虽然提高了运行效率，但是因为每一个节点都需要额外保存父节点、孩子节点和红/黑性质，使得每一个节点都占用大量的空间
//适用处：对于那些有顺序要求的问题，用map会更高效一些
//
//unordered_map：
//优点： 因为内部实现了哈希表，因此其查找速度非常的快
//缺点： 哈希表的建立比较耗费时间
//适用处：对于查找问题，unordered_map会更加高效一些，因此遇到查找问题，常会考虑一下用unordered_map
//总结：
//
//内存占有率的问题就转化成红黑树 VS hash表 , 还是unorder_map占用的内存要高。
//但是unordered_map执行效率要比map高很多

//注意：C++11才开始支持括号初始化
  unordered_map<int, string> myMap={{ 5, "张大" },{ 6, "李五" }};//使用{}赋值
  myMap[2] = "李四";  //使用[ ]进行单个插入，若已存在键值2，则赋值修改，若无则插入。
  myMap.insert(pair<int, string>(3, "陈二"));//使用insert和pair插入

  //遍历输出+迭代器的使用
  auto iter = myMap.begin();//auto自动识别为迭代器类型unordered_map<int,string>::iterator
  while (iter!= myMap.end())
  {
      cout << iter->first << "," << iter->second << endl;
      ++iter;
  }
  
  //查找元素并输出+迭代器的使用
  auto iterator = myMap.find(2);//find()返回一个指向2的迭代器
  if (iterator != myMap.end())
      cout << endl<< iterator->first << "," << iterator->second << endl;
  system("pause");


#endif /* _50__________II_h */
