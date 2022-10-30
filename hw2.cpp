#include<iostream>
#include<fstream>
#include<queue>
#include <tuple>
#include <cmath>
using namespace std;

struct point
{
    float x;
    float y;
    int index;
};
int rank[2001];
point arr[2001];
point buffer[2001];
int ranks[10000];
int maxrank=0;
int minrank=9999;
void maxheap(point arr[],int n,int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    
    if (l<n&&(arr[i].x< arr[l].x))
    {
        largest = l;
    }
    if(r <n && arr[largest].x <arr[r].x)  
    {
        largest = r;
    }
    if (largest != i)
    {
        point temp;
        temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        maxheap(arr,n,largest);
    }
}

void heapsort(point arr[],int num)
{
    int n = num;
    
    for(int i=((n/2)-1);i>-1;i--)
    {
        maxheap(arr,n,i);
    }
    
    for(int i=n-1;i>0;i--)
    {
        point temp=arr[i];
        arr[i]=arr[0];
        arr[0]=temp;
        maxheap(arr,i,0);
    }
   
}

    
void Rank2D(int left, int right) {
	if (right - left <= 1)
		return;
	int middle = (left + right)/2, medianX = arr[middle].x, counts = 0, i = left, j = middle, k = left;
	Rank2D(left, middle); 
    Rank2D(middle, right);
	while (i < middle || j < right) {
		if (i == middle) {
			buffer[k] = arr[j]; 
            ranks[buffer[k].index] += counts;
			j++; 
            k++;
		}
		else if (j == right) {
			buffer[k] = arr[i];
			i++; k++;
		}
		else if (arr[i].y < arr[j].y) {
			buffer[k] = arr[i]; 
            counts++;
			i++; 
            k++;
		}
		else {
			buffer[k] = arr[j]; 
            ranks[buffer[k].index] += counts;
			j++; 
            k++;
		}
	}
	for (i = left; i < right; i++)
		arr[i] = buffer[i];
}
    




int main()
{
    int choose;
    int left,right,i=0;
    float b,c;
   
    ifstream myfile;  
    myfile.open("test2.txt");
    float sum = 0, value = 0;
    
    
    
    while(!myfile.eof())
    { 
        myfile >> b >> c;
        arr[i].x=b;
        arr[i].y=c;
        arr[i].index=i;
        i++;
    }

   
    int num=i;
    point temp[2001];
    for(int i=0;i<num;i++)
    {
        temp[i]=arr[i];
    }
    heapsort(arr,num);
    for(int i=0;i<num;i++)
    {
        cout<<"("<<arr[i].x<<","<<arr[i].x<<")"<<" ";
    }
    cout<<endl;
    Rank2D(0, num);
    int average=0;
    for(i=0;i<num;i++)
    {
        if(maxrank<ranks[i])
            maxrank=ranks[i];
        if(minrank>ranks[i])
            minrank=ranks[i];

         average=average+ranks[i];
    }
    
    for (int i = 0; i < num; i++)
			cout <<"("<<temp[i].x<<" , "<<temp[i].y<<")   "<<"rank="<<ranks[i] << '\n';
    cout<<"點的個數:"<<" "<<num<<endl;
    cout<<"最大rank:"<<" "<<maxrank<<endl;
    cout<<"最小rank:"<<" "<<minrank<<endl;
    cout<<"平均rank:"<<" ";printf("%.2f",(float)average/num);



}