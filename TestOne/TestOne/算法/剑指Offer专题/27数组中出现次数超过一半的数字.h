//
//  27数组中出现次数超过一半的数字.h
//
//  Created by lg on 2020/6/17.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _7_______________h
#define _7_______________h

//数组中出现次数超过一半的数字
//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
int MoreThanHalfNum_Solution(vector<int> numbers) {
    if (numbers.size() == 0) {
        return 0;
    }
    int result = numbers[0];
    int count = 1;
    for (int i = 1; i<numbers.size(); i++) {
        if (numbers[i] != result) {
            count--;
            if (count == 0 && (i != numbers.size()-1)) {//注意换数字的条件，不仅是count= 0，还需要限定不是最后一位
                result = numbers[i];
                count = 1;
            }
        } else {
            count++;
        }
    }
    if (count>0) {
        return result;
    }
    return 0;
}


//以下的方法更准确

#endif /* _7_______________h */
