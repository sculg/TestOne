//
//  MergeSort.h
//
//  Created by lg on 2019/9/14.
//  Copyright © 2019 sculg. All rights reserved.
//

#ifndef MergeSort_h
#define MergeSort_h

void Merge(int arr[], int l, int q, int r){
    int n=r-l+1;//临时数组存合并后的有序序列
    int* tmp=new int[n];
    int i=0;
    int left=l;
    int right=q+1;
    while(left<=q && right<=r)
        tmp[i++] = arr[left]<= arr[right]?arr[left++]:arr[right++];
    while(left<=q)
        tmp[i++]=arr[left++];
    while(right<=r)
        tmp[i++]=arr[right++];
    for(int j=0;j<n;++j)
        arr[l+j]=tmp[j];
    delete [] tmp;//删掉堆区的内存
}

void MergeSort(int arr[], int l, int r){
    if(l==r)
        return;  //递归基是让数组中的每个数单独成为长度为1的区间
    int q = (l + r)/2;
    MergeSort(arr, l, q);
    MergeSort(arr, q + 1, r);
    Merge(arr, l, q, r);
}

void merge(vector<int> &arr,int L,int mid,int R)
{
    int *help = new int(R-L+1);
    int p1=L,p2=mid+1,i=0;
    while(p1<=mid && p2<=R)
    {
        help[i++] = arr[p1]>arr[p2] ? arr[p2++] : arr[p1++];
    }
    while(p1<=mid)
        help[i++] = arr[p1++];
    while(p2<=R)
        help[i++] = arr[p2++];
 
    for (int i=0;i<R-L+1;i++)
    {
        arr[L+i] = help[i];
    }
}
void sortprocess(vector<int> &arr,int L,int R)
{
    if (L < R)
    {
        int mid = L + ((R-L)>>2);  //  (L+R)/2
        sortprocess(arr,L,mid);
        sortprocess(arr,mid+1,R);
        merge(arr,L,mid,R);
    }
}
 

void MergeSort(vector<int> &arr,int L,int R)
{
    if (arr.size()<2)
        return;
    sortprocess(arr,L,R);
}


int array[] = {12,234,45,32,54,556,32};
int len = sizeof(array)/sizeof(int);
cout<<"The orginal array are:"<<endl;
for(int i=0; i<len; ++i)
{
    cout<< array[i] << " ";
}
cout<<endl;
Solution().MergeSort(array,0,len-1);
cout<<"The sorted array are:"<<endl;
for(int i=0; i<len; ++i)
{
    cout<< array[i] << " ";
}
cout<<endl;

#endif /* MergeSort_h */
