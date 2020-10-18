//
//  FindNumsAppearOnce.h
//
//  Created by lg on 2020/6/3.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef FindNumsAppearOnce_h
#define FindNumsAppearOnce_h

//一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。

vector<int> FindNumsAppearOnce(vector<int> data) {
    vector<int> result;
    if(data.size()<2){
        return result;
    }
    int a = 0;
    for(int i = 0;i<data.size();++i){
        a^= data[i];
    }
    int indexOf1 = findIndexOfFirst1(a);

    int num1 = 0;
    int num2 = 0;
    for(int j = 0;j<data.size();++j){
        if(is1AtIndex(data[j],indexOf1)){
           num1 ^= data[j];
        } else {
            num2 ^= data[j];
        }
    }
    result.push_back(num1);
    result.push_back(num2);
    return result;
}
int findIndexOfFirst1(int num){
    int indexOf1 = 0;
    while(((num&1)==0)&& indexOf1<8*sizeof(int)){
        num = num>>1;
        ++indexOf1;
    }
    return indexOf1;
}

bool is1AtIndex(int num, int index){
    num = num >> index;
    return (num&1);
}


//用例

int arr[] = {3,10,7,9,10,9};
vector<int> vect(arr,arr+sizeof(arr)/sizeof(int));
vector<int> res = Solution().FindNumsAppearOnce(vect);
cout<< res[0]<<endl;
cout<< res[1]<<endl;

#endif /* FindNumsAppearOnce_h */
