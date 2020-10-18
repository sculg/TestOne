//
//   65队列的最大值.h
//
//  Created by lg on 2020/7/19.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _65_______h
#define _65_______h

请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
若队列为空，pop_front 和 max_value 需要返回 -1
queue<int> queue1;
deque<int> queue2;
MaxQueue() {

}

int max_value() {
    if(queue2.empty()) {
        return -1;
    }
    return queue2.front();
}

void push_back(int value) {
    while(!queue2.empty() && queue2.back()<value) {
        queue2.pop_back();
    }
    queue2.push_back(value);
    queue1.push(value);
}

int pop_front() {
    if(queue1.empty()) {
        return -1;
    }
    int ans = queue1.front();
    if(ans == queue2.front()) {
        queue2.pop_front();
    }
    queue1.pop();
    return ans;
}
#endif /* _65_______h */
