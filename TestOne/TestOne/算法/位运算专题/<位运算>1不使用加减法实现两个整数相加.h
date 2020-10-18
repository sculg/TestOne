//
//  Add_without_operater.h
//
//  Created by lg on 2020/6/4.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef Add_without_operater_h
#define Add_without_operater_h

//不使用加减法实现两个整数相加
int Add_without_operater(int num1,int num2) {
    if (num2 == 0) {
        return num1;
    }
    int sum = num1 ^ num2;
    int carry = (unsigned int)(num1 & num2) << 1;
    return Add_without_operater(sum,carry);
}


int res = Solution().Add_without_operater(7,8);
cout<< res<<endl;

#endif /* Add_without_operater_h */
