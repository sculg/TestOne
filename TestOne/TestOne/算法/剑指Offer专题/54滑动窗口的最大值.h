//
//  54滑动窗口的最大值.h
//
//  Created by lg on 2020/6/20.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _4_________h
#define _4_________h

//暴力法
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    if(nums.size() == 0) {
        return result;
    }
    for(int i = 0;i<=nums.size()-k;i++) {
        int maxNum = nums[i];
        for(int j=i; j<i+k; j++) {
            maxNum = max(maxNum,nums[j]);
        }
        result.push_back(maxNum);
    }
    return result;
}

//滑动窗口的最大值
vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
    vector<int> result;
    int length = num.size();
    if (length == 0 || size == 0) {
        return result;
    }
    deque<int> q;
    for (int i = 0; i<length; i++) {
        //从后面依次弹出队列中比当前num值小的元素，同时也能保证队列首元素为当前窗口最大值下标
        while (q.size()>0 && num[q.back()]<=num[i]) {
            q.pop_back();
        }
        //当当前窗口移出队首元素所在的位置，即队首元素坐标对应的num不在窗口中，需要弹出
        while (q.size()>0 && i-q.front()+1>size) {
            q.pop_front();
        }
        //把每次滑动的num下标加入队列
        q.push_back(i);
        //当滑动窗口首地址i大于等于size时才开始写入窗口最大值
        if (1+i>=size) {
            result.push_back(num[q.front()]);
        }
    }
    return result;
}

//双端队列
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    if(nums.size() == 0) {
        return result;
    }
    deque<int> deq;
    for(int i = 0;i < nums.size();i++) {
        //将队列中小于nums[i]的坐标全部pop
        while(!deq.empty() && nums[i] > nums[deq.back()]) {
            deq.pop_back();
        }
        //检查队首的index是否在窗口内，不在的话需要出队
        if(!deq.empty() && deq.front() < i - k + 1) {
            deq.pop_front();
        }
        //从第k位开始记录最大值
        deq.push_back(i);
        if(i >= k-1) {
            result.push_back(nums[deq.front()]);
        }
    }
    return result;
}
#endif /* _4_________h */
