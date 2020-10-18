//
//  45字符流中第一个不重复的字符.h
//
//  Created by lg on 2020/6/19.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _5______________h
#define _5______________h

//请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
//字符流中第一个不重复的字符
    void Insert(char ch)
      {
          ++hashArray[ch-'\0'];
          if (hashArray[ch-'\0'] == 1) {
              data.push_back(ch);
          }
      }
      char FirstAppearingOnce()
      {
          while(!data.empty()&&hashArray[data.front()] >= 2) {
              data.pop_front();
          }
          if (data.empty()) {
              return '#';
          }
          return data.front();
      }
private:
    unsigned char hashArray[256];
    deque<char> data;
#endif /* _5______________h */
