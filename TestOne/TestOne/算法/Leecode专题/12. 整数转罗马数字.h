//
//  12. 整数转罗马数字.h
//
//  Created by lg on 2020/7/29.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _2__________h
#define _2__________h

string intToRoman(int num) {
    string result;
    vector<int> store = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    vector<string> strs = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int size = store.size();
    for(int i = 0; i < size; i++) {
        while(num >= store[i]) {
            result.append(strs[i]);
            num = num - store[i];
        }
    }
    return result;
}

#endif /* _2__________h */
