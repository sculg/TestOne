//
//  实现hash函数.h
//
//  Created by lg on 2020/8/6.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef __hash___h
#define __hash___h

#include <stdio.h>
#include <vector>
#include <list>
#include <iostream>
#include <iostream>

using namespace std;

class MyHashMap {
    size_t m_size = 10000;
    vector<list<pair<int, int>>> m_data;
public:
    // 初始化，设置大小
    MyHashMap() {
        m_data.resize(m_size);
    }
    // 哈希函数
    int hashCode(int key) {
        return key % m_size;
    }
    
    // 根据 key 存储对应的 value，如果 key 已经存在，更新 value
    void put(int key, int value) {
        // 根据哈希函数找到对应的链表
        auto &list = m_data[hashCode(key)];
        for (auto & val : list) {
            // 如果已经存在，根据 key 来更新对应的值
            if (val.first == key) {
                val.second = value;
                return;
            }
        }
        // 插入链表的尾部
        list.emplace_back(key, value);
    }
    
    // 根据 key 来获取值
    int get(int key) {
        const auto &list = m_data[hashCode(key)];
        if (list.empty()) {
            return -1;
        }
        for (auto & val : list) {
            // 如果已经存在，找到了对应的值
            if (val.first == key) {
                return val.second;
            }
        }
        return -1;
    }
    
    // 根据 key 删除对应的值
    void remove(int key) {
        auto &list = m_data[hashCode(key)];
        // 找到节点后删除
        list.remove_if([key](auto n) {
            return n.first == key;
        });
    }
};

int main() {
    
    MyHashMap().put(1, 10);
//    MyHashMap().put(2, 20);
//    MyHashMap().put(3, 30);
    printf("%d \n",MyHashMap().get(1));
    return 0;
}

#endif /* __hash___h */
