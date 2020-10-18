//
//  179. 最大数.h
//
//  Created by lg on 2020/8/4.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _79______h
#define _79______h

string largestNumber(vector<int>& nums) {
    if(nums.empty()) return "";
    if(nums.size() == 1) return to_string(nums[0]);

    sort(nums.begin(), nums.end(), comparison); // 调用STL中的sort函数
    string result = "";
    for(int i : nums)
    {
        result += to_string(i);
    }
    if(result[0] == '0') return "0"; // 特殊case，全是0的时候应该输出0而不是00000
    return result;
}
static bool comparison(const int& a, const int& b) {
    // 此处要用static，因为std::sort是属于全局的，无法调用非静态成员函数，而静态成员函数或全局函数是不依赖于具体对象，可以独立访问。
    // 也可以把comparison这个函数放在Solution这个class的外面，但是记住一定要放在调用这个函数的那一行的前面哦（也就是指Solution的上面），不然调用的时候会找不到这个
    // 函数然后报错。
    string concatenation1 = to_string(a) + to_string(b);
    string concatenation2 = to_string(b) + to_string(a);
    
    return concatenation1 > concatenation2;
}

#endif /* _79______h */
