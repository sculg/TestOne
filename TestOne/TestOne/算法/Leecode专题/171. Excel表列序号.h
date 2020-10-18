//
//  171. Excel表列序号.h
//
//  Created by lg on 2020/8/4.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _71__Excel_____h
#define _71__Excel_____h

int titleToNumber(string s) {
    long result = 0;
    int i = 0;
    while(s[i] != '\0') {
        result = result*26 + s[i] - 'A' + 1;
        i++;
    }
    return result;
}

#endif /* _71__Excel_____h */
