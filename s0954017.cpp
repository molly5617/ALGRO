#include<iostream>
#include <array>

#include <vector>
using namespace std;
void quicksort(int a[],int left,int right)
{
    int temp,change;
    int i,j;
    if(left+1>right)
    return;
    
    i=left;
    j=right;
    temp=a[left];
    
    while(i<j)
    {
        while (a[j]>=temp&&i<j)
        {
            j--;
        }
         while (a[i]<=temp&&i<j)
        {
            i++;
        }
        if(i<j)
        {
            change=a[i];
            a[i]=a[j];
            a[j]=change;
        }
    }
        a[left]=a[i];
        a[i]=temp;
        quicksort(a,left,i-1);
        quicksort(a,i+1,right);
        
    
}

void insertsort(int a[],int num)
{
    for(int i=0;i<num-1;i++)
    {
        int j=i+1;
        int temp=a[j];
        while(j>0&&temp<a[j-1])
        {
            a[j]=a[j-1];
            j--;
        }
        a[j]=temp;
    }
}



int main()
{
    int choose;
    int left,right,i=0;
    int a[2001],b;
    
    while(cin>>choose)
    {
    
    
    int sum = 0, value = 0;
    
    for (int h=0;h<choose;h++)
    {
        cin>>a[h];
    }
    int num=choose;
    
        quicksort(a,0,num-1);
        for(int i=0;i<num;i++)
        cout<<a[i]<<" ";
        cout<<endl;
        
    }
    
    
    

   
    
    
    
}