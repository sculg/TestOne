//
//  49求1+2+3+...+n.h
//
//  Created by lg on 2020/6/19.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _9_1_2_3_____n_h
#define _9_1_2_3_____n_h

//求1+2+3+...+n
//求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
//1.需利用逻辑与的短路特性实现递归终止。
//2.当n==0时，(n>0)&&((sum+=Sum_Solution(n-1))>0)只执行前面的判断，为false，然后直接返回0；
//3.当n>0时，执行sum+=Sum_Solution(n-1)，实现递归计算Sum_Solution(n)。

int Sum_Solution(int n) {
    int ans=n;
    ans&&(ans+=Sum_Solution(n-1));
    return ans;
}

#endif /* _9_1_2_3_____n_h */
