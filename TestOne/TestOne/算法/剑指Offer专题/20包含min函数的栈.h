//
//  20包含min函数的栈.h
//
//  Created by lg on 2020/6/17.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _0__min_____h
#define _0__min_____h
//包含min函数的栈
//定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
//注意：保证测试中不会当栈为空的时候，对栈调用pop()或者min()或者top()方法。

stack<int> stackA;
stack<int> stackB;
void push(int value) {
    stackA.push(value);
    if (stackB.empty()) {
        stackB.push(value);
    }
    else if (value < stackB.top()) {
        stackB.push(value);
    } else {
        stackB.push(stackB.top());
    }
}
void pop() {
    stackA.pop();
    stackB.pop();
}
int top() {
    return stackA.top();
}
int min() {
    return stackB.top();
}
#endif /* _0__min_____h */
