//
//  28. 实现 strStr().h
//
//  Created by lg on 2020/7/30.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _8_____strStr___h
#define _8_____strStr___h

int strStr(string haystack, string needle) {
    if(haystack.size() < needle.size()) {
        return -1;
    }
    if(needle.size() == 0) {
        return 0;
    }
    int needleIndex = 0;
    int firstIndex = -1;
    for (int i = 0;i < haystack.size();i++) {
        if(needleIndex < needle.size()) {
            if(haystack[i] == needle[needleIndex]) {
                if(firstIndex == -1) {
                    firstIndex = i;
                }
                needleIndex++;
            } else {
                if(firstIndex != -1) {
                    i = firstIndex;
                    firstIndex = -1;
                    needleIndex = 0;
                }
            }
        }
    }
    return needleIndex == needle.size()? firstIndex : -1;
}

#endif /* _8_____strStr___h */
