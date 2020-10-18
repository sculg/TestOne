//
//  146.h
//
//  Created by lg on 2020/7/22.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _46_h
#define _46_h

运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。
获取数据 get(key) - 如果关键字 (key) 存在于缓存中，则获取关键字的值（总是正数），否则返回 -1。
写入数据 put(key, value) - 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字/值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
进阶:
你是否可以在 O(1) 时间复杂度内完成这两种操作？
示例:
LRUCache cache = new LRUCache( 2 /* 缓存容量 */ );
cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // 返回  1
cache.put(3, 3);    // 该操作会使得关键字 2 作废
cache.get(2);       // 返回 -1 (未找到)
cache.put(4, 4);    // 该操作会使得关键字 1 作废
cache.get(1);       // 返回 -1 (未找到)
cache.get(3);       // 返回  3
cache.get(4);       // 返回  4

class LRUCache {
private:
    int cap;
    // 双链表：装着 (key, value) 元组
    list<pair<int, int>> cache;
    // 哈希表：key 映射到 (key, value) 在 cache 中的位置
    unordered_map<int, list<pair<int, int>>::iterator> map;
public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }
    int get(int key) {
        auto it = map.find(key);
        // 访问的 key 不存在
        if (it == map.end())
            return -1;
        // key 存在，把 (k, v) 换到队头
        pair<int, int> kv = *map[key];
        cache.erase(map[key]);
        cache.push_front(kv);
        // 更新 (key, value) 在 cache 中的位置
        map[key] = cache.begin();
        return kv.second; // value
    }
    void put(int key, int value) {
        /* 要先判断 key 是否已经存在 */
        auto it = map.find(key);
        /* key 不存在，判断 cache 是否已满 */
        if (it == map.end()) {
            if (cache.size() == cap) {
                // cache 已满，删除尾部的键值对腾位置
                // cache 和 map 中的数据都要删除
                auto lastPair = cache.back();
                int lastKey = lastPair.first;
                map.erase(lastKey);
                cache.pop_back();
            }
            // cache 没满，可以直接添加
            cache.push_front(make_pair(key, value));
            map[key] = cache.begin();
        } else {
            /* key 存在，更改 value 并换到队头 */
            cache.erase(map[key]);
            cache.push_front(make_pair(key, value));
            map[key] = cache.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
void FormatString(char str[], int len)
{
  if(str == NULL || len <= 0)
  return;
 
  int i = 0, j = 0;
  while(str[i] == ' ')//开头的空格
    i++;
  while(str[i] != '\0')
  {
    if(str[i] == ' ' && (str[i+1] == ' ' || str[i+1] == '\0'))
    {
//中间或者结尾的空格
        i++;
        continue;
    }
    str[j++] = str[i++];
  }
  str[j] = '\0';
}

function isSub(arr1,arr2){
    var i=0, j=0,
    Len1=arr1.length, Len2=arr2.length;
 
    //如果数组1的长度小于数组2的长度，就肯定不是子集
    //如果数组1的最后一个元素比数组2的最后一个元素小，也不是子集
    if (Len1<Len2 || arr1[Len1-1]<arr2[Len2-1]) {
        return false;
    }
    while(i<Len1 && j<Len2){
        var a=arr1[i], b=arr2[j];
        if (a===b) {
            i++;
            j++;
        }else if (a<b) {
            i++;
        }else{
            return false;
        }
    }
    return true;
}

vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int n = board.size(), m = board[0].size();
        int row = click[0], col = click[1];
        if(board[row][col] == 'M' || board[row][col] == 'X'){
            board[row][col] = 'X';
            return board;
        }
        vector<vector<int>> dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}, {1,1}, {1, -1}, {-1,1}, {-1, -1}};
        int num = 0;
        for(auto dir: dirs){
            int new_row = row + dir[0];
            int new_col = col + dir[1];
            if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && board[new_row][new_col] == 'M') num ++;
        }
        if(num > 0){
            board[row][col] = num + '0';
            return board;
        }
        board[row][col] = 'B';
        for(auto dir: dirs){
            int new_row = row + dir[0];
            int new_col = col + dir[1];
            if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && board[new_row][new_col] == 'E'){
                vector<int> next_click = {new_row, new_col};
                updateBoard(board, next_click);
            }
        }
        return board;
    }


#endif /* _46_h */
