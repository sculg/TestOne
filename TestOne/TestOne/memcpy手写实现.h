//
//  memcpy手写实现.h
//
//  Created by lg on 2020/7/25.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef memcpy_____h
#define memcpy_____h

void *memcpy(void *dest, const void *src, size_t count) {
    char *d;
    const char *s;
    if (dest > (src+size)) || (dest < src)) {
        d = dest;
        s = src;
        while (count--)
            *d++ = *s++;
    }
    else {
        d = (char *)(dest + count - 1); /* offset of pointer is from 0 */
        s = (char *)(src + count -1);
        while (count --)
            *d-- = *s--;
    }
    return dest;
}


#endif /* memcpy_____h */
