//
//  67. 二进制求和.h
//
//  Created by lg on 2020/8/5.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _7________h
#define _7________h

string addBinary(string a, string b) {
    string result = "";
    int indexA = a.size()-1;
    int indexB = b.size()-1;
    int sum = 0;
    while(indexA >= 0 || indexB >= 0) {
        if(indexA >= 0 && a[indexA] == '1') {
            sum++;
        }
        if(indexB >= 0 && b[indexB] == '1') {
            sum++;
        }
        result += '0' + sum%2;
        sum  = sum/2;
        indexA--;
        indexB--;
    }
    if(sum>0) {
        result += '0' + (sum%2);
    }
    reverse(result.begin(),result.end());
    return result;
}

#endif /* _7________h */
