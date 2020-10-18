//
//  两个栈实现队列.h
//
//  Created by lg on 2020/6/14.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef ________h
#define ________h

//用两个栈实现队列
//用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。

public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        
        int result = stack2.top();
        stack2.pop();
        return result;
    }

private:
    stack<int> stack1;
    stack<int> stack2;

#endif /* ________h */
