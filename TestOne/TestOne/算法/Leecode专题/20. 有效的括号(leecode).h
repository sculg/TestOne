//
//  20. 有效的括号(leecode).h
//
//  Created by lg on 2020/6/28.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _0________leecode__h
#define _0________leecode__h
//20. 有效的括号

//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
//
//有效字符串需满足：
//
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//注意空字符串可被认为是有效字符串

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

#endif /* _0________leecode__h */
