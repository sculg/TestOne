//
//  53约瑟夫环问题.h
//
//  Created by lg on 2020/6/20.
//  Copyright © 2020 sculg. All rights reserved.
//

#ifndef _3_______h
#define _3_______h

//利用数学分析得到的解法
//f(n,m)=[f(n-1,m)+m]%n，其中f(n,m)为长度为n的删除第m个节点，最后剩下的数字
int LastRemaining_Solution(int n, int m) {
    if (n<=0 || m<=0) {
        return -1;
    }
    int last = 0;
    for (int  i = 2; i<=n; i++) {
        last = (last + m)%i;
    }
    return  last;
}

int LastRemaining_Solution1(int n, int m)
{
    if(n<=0||m<=0)
        //非负的int型的异常判断要设置为返回-1
        return -1;
    //list型的容器，容器的一种
    list<int> num;
    for(int i=0;i<n;i++)
        num.push_back(i);
    //迭代器生成的都是指针形式的
    list<int>::iterator cur=num.begin();
    //当最后size为1的时候，就停止循环了
    while(num.size()>1)
    {
        //为了得到待删除的点
        for(int i=1;i<m;i++)
        {
            cur++;
            //list毕竟不是环，如果指向末尾了，需要让它重新指向开头，这样来达到模拟一个环的作用
            if(cur==num.end())
                cur=num.begin();
        }
        //赋值的时候先自加，再赋值，因为我想要保存下来cur的值，而cur是一个类似指针的形式
        //所以就新建一个迭代器
        list<int>::iterator next=(++cur);
        //这里也要考虑到模拟环的作用
        if(next==num.end())
            next=num.begin();
        //cur之前自加了，这里要让它变回原来那个待删除的点
        cur--;
        //直接删除这个类似指针的东西，就可以达到删除的目的
        num.erase(cur);
        cur=next;
    }
    //返回的要是值，所以加*
    return *(cur);
}
#endif /* _3_______h */
