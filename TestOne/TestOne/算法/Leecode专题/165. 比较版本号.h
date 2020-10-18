//
//  165. 比较版本号.h
//
//  Created by lg on 2020/8/4.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _65________h
#define _65________h

int compareVersion(string version1, string version2) {
        int p1 = 0, p2 = 0;
        int end = max(version1.size(), version2.size());
        while (p1 < end || p2 < end) {
            int v1 = 0, v2 = 0;
            while (p1 < version1.size() && version1[p1] != '.') {
                v1 = v1 * 10 + version1[p1] - '0';
                p1++;
            }
            while (p2 < version2.size() && version2[p2] != '.') {
                v2 = v2 * 10 + version2[p2] - '0';
                p2++;
            }
            if (v1 > v2) return 1;
            else if (v1 < v2) return -1;
            p1++;
            p2++;
        }
        return 0;
    }
};


#endif /* _65________h */
