//
//  52扑克牌顺子.h
//
//  Created by lg on 2020/6/20.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _2______h
#define _2______h

//扑克牌顺子

bool IsContinuous( vector<int> numbers ) {
    if (numbers.empty()) {
        return false;
    }
    int count[14] = {0};
    int length = numbers.size();
    int max = -1;
    int min = 14;
    for (int i = 0; i<length; i++) {
        count[numbers[i]]++;
        if (numbers[i] == 0) {
            continue;
        }
        if (count[numbers[i]]>1) {
            return false;
        }
        if (numbers[i]>max) {
            max = numbers[i];
        }
        if (numbers[i]<min) {
            min = numbers[i];
        }
    }
    if (max-min<5) {
        return true;
    }
    else {
        return false;
    }
}
#endif /* _2______h */
