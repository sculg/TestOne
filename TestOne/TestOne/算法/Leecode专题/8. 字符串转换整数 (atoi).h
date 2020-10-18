//
//  8. 字符串转换整数 (atoi).h
//
//  Created by lg on 2020/7/29.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef ____________atoi__h
#define ____________atoi__h

int myAtoi(string str) {
    long result = 0;
    if(str.size() == 0) {
        return result;
    }
    int index = 0;
    int firstValidIndex = 0;
    int flag = 1;
    while(str[index] == ' ') {
    index++;
    firstValidIndex = index;
    }
    if(str[firstValidIndex] == '-') {
        flag = -1;
        firstValidIndex++;
        index++;
    } else if(str[firstValidIndex] == '+') {
        flag = 1;
        firstValidIndex++;
        index++;
    }
    while(index < str.size()) {
        if(str[firstValidIndex] > '9' || str[firstValidIndex] < '0') {
            return 0;
        } else {
            if(str[index] <= '9' && str[index] >= '0' && str[index] != '\n') {
                result = result * 10 + str[index] - '0';
                if(flag==1 && result > INT_MAX){
                    return INT_MAX;
                }
                if(flag==-1 && -result < INT_MIN){
                    return INT_MIN;
                }
                index++;
            } else {
                return result * flag;
            }
        }
    }
    return result * flag;
}
#endif /* ____________atoi__h */
