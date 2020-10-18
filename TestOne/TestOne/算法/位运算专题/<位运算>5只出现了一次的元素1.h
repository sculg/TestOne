//
//  singleNumber1.h
//
//  Created by lg on 2020/6/3.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef singleNumber1_h
#define singleNumber1_h

//3、给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。
int singleNumber(vector<int>& nums) {
    int ans = 0;
    for (int i = 0; i<32; i++) {
        int sum = 0;
        for(int num : nums) {
            sum += (num >> i)&1;
        }
        ans ^= (sum % 3) << i;
    }
    return ans;
}

int arr[] = {10,10,9,9,10,9,7};
vector<int> vect(arr,arr+sizeof(arr)/sizeof(int));
int res = Solution().singleNumber(vect);
cout<< res<<endl;

#endif /* singleNumber1_h */
