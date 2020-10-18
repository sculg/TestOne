//
//  63设计一个单例.h
//
//  Created by lg on 2020/7/1.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _3_______h
#define _3_______h

//63设计一个单例
+(Student *)shareInstance {
    dispatch_once_t onceToken;
    static Student *myStudent = nil;
    dispatch_once(&onceToken, ^{
        myStudent = [[Student alloc] init];
    });
    return myStudent;
}

#endif /* _3_______h */
