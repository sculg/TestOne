//
//  168. Excel表列名称.h
//
//  Created by lg on 2020/8/4.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _68__Excel_____h
#define _68__Excel_____h

string convertToTitle(int n) {
    string result;
    while(n>0) {
        char tem;
        n = n -1;
        tem= n%26 + 'A';
        result = tem + result;
        n = n/26;
    }
    return result;
}

#endif /* _68__Excel_____h */
