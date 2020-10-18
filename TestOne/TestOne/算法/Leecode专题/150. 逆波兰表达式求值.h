//
//  evalRPN.h
//
//  Created by lg on 2019/9/29.
//  Copyright © 2019 sculg. All rights reserved.
//

#ifndef evalRPN_h
#define evalRPN_h
//

/*根据逆波兰表示法，求表达式的值。
有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
说明：
整数除法只保留整数部分。
给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
示例 1：
输入: ["2", "1", "+", "3", "*"]
输出: 9
解释: ((2 + 1) * 3) = 9
示例 2：
输入: ["4", "13", "5", "/", "+"]
输出: 6
解释: (4 + (13 / 5)) = 6
示例 3：
输入: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
输出: 22
解释:
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/


int evalRPN(vector<string>& tokens) {
    stack<int> nums;
    int result = 0;
    for (int i = 0; i<tokens.size(); i++) {
        
    }
    return result;
}
int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int op1 = 0, op2 = 0;
        for(string str : tokens)
        {
            char t = str[0];
            // 负数的第一位为符号位
            // 如果s的长度大于1则用第二位做判断，虽然可能是两位以上整数，但是不会影响下面的判断
            if(str.length() > 1)
                t = str[1];
            switch(t)
            {
                case '+':
                    op2 = s.top();
                    s.pop();
                    op1 = s.top();
                    s.pop();
                    s.push(op1 + op2);
                    break;
                case '-':
                    op2 = s.top();
                    s.pop();
                    op1 = s.top();
                    s.pop();
                    s.push(op1 - op2);
                    break;
                case '*':
                    op2 = s.top();
                    s.pop();
                    op1 = s.top();
                    s.pop();
                    s.push(op1 * op2);
                    break;
                case '/':
                    op2 = s.top();
                    s.pop();
                    op1 = s.top();
                    s.pop();
                    s.push(op1 / op2);
                    break;
                default:
                    s.push(atoi(str.c_str()));
                    break;
            }
        }
        return s.top();
    }


int calculate(int a,int b, string operation) {
    switch (operation[0]) {
        case '+':
            a = a + b;
            break;
        case '-':
            a = a + b;
            break;
        case '*':
            a = a + b;
            break;
        case '/':
            a = a + b;
            break;
        default:
            break;
    }
    return a;
}

string arr[] = {"2", "1", "+", "3", "*"};
vector<string> priceVect(arr,arr+sizeof(arr)/sizeof(char));
int maxProfit = Solution().evalRPN(priceVect);
cout<< maxProfit << endl;

#endif /* evalRPN_h */
