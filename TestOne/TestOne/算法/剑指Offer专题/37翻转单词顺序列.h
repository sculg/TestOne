//
//  37翻转单词顺序列.h
//
//  Created by lg on 2020/6/18.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _7________h
#define _7________h

//翻转单词顺序列
//例如，“student. a am I”。->“I am a student.”。

void Reverse(string &str,int begin,int end){
    while(begin < end){
        char tem = str[begin];
        str[begin] = str[end];
        str[end] = tem;
        begin++;
        end--;
    }
}

string ReverseSentence(string str) {
    int length = str.size();
    if (length == 0) {
        return "";
    }
    int begin = 0;
    int end = 0;
    Reverse(str,0,length-1);
    while (str[begin] != '\0') {
        if (str[begin] == ' ') {
            begin++;
            end++;
        } else if (str[end] == ' '||str[end] == '\0') {
            Reverse(str,begin,--end);
            begin = ++end;
        } else {
            end++;
        }
    }
    return str;
}
#endif /* _7________h */

__block int count = 0;

id obj = xxx;

dispatch_async(dispatch_queue_create("Test Queue", DISPATCH_QUEUE_SERIAL), ^{

    count++;

    obj;
    [self performSelector:@selector(testMethod) withObject:nil afterDelay:2];
});


  //cin >> a;
    cout << "Hello World!" << endl;
    __weak typeof(weakSelf) = self;
    self.testBlock = ^(){
        

[weakSelf performSelector:@selector(testMethod) withObject:nil];

};
