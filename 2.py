# -*- coding: utf-8 -*-
"""
Created on Fri Oct 28 10:16:31 2022

@author: User
"""
import numpy as np

def maxHeapify(arr, n, i):
    largest = i
    l = 2 * i + 1
    r = 2 * i + 2
  
    if l < n and arr[i][0] < arr[l][0]:
        largest = l
  
    if r < n and arr[largest][0] < arr[r][0]:
        largest = r
  
    if largest != i:
        arr[i],arr[largest] = arr[largest],arr[i]
        maxHeapify(arr, n, largest)
  
def heapSort(arr):
    n = len(arr)

    for i in range(n // 2 - 1, -1, -1):
        maxHeapify(arr, n, i)
  
    for i in range(n-1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        maxHeapify(arr, i, 0)
def findmax(arr,start,end):
    if end-start==0:
        return arr[start]
    elif end-start==1:
        if arr[start][1]>arr[end][1]:
            temp=[]
            temp.append(arr[start])
            temp.append(arr[end])
            return temp
        else:
           return arr[end]
    else:
        maxlist=[]
        maxL=findmax(arr, start, int((end+start)/2))
        maxR=findmax(arr,int((end+start)/2)+1,end)
        R=-99999999.9
        if len(np.array(maxR).shape)==1:
            R=maxR[0]
            maxlist.append(maxR)
            #arr.remove(maxR)
        else:
            for i in maxR:
                maxlist.append(i)
                #arr.remove(i)
                if R < i[1]:
                    R=i[1]
        if len(np.array(maxL).shape)>1:
            for i in maxL:
                if i[1] > R:
                    maxlist.append(i)
                    #arr.remove(i)
        else:
            if maxL[1]>R:
                maxlist.append(maxL)
                #arr.remove(maxL)
        return maxlist
                
filename = 'test2.txt'

elements = []
with open(filename) as file:
   for line in file:
      line = line.strip().split()
      elements.append(line)
lii=[]
ele_array = np.array(elements)
file.close()
for a in ele_array:
    num=[]
    for i in range(2):
        if float(a[i])-int(float(a[i]))==0:
            num.append(int(a[i]))
        else:
            num.append(float(a[i]))
    lii.append(num)
    
data = lii
heapSort(data)
print(data)
maxrank=[]
count=len(data)
datalen=len(data)
avgrank=0
mrank=0
srank=len(data)
while len(data)>0:
    temp=[]
    temp=findmax(data,0,len(data)-1)
    if len(np.array(temp).shape)==1:
        data.remove(temp)
    else:
        for i in temp:
            data.remove(i)
    maxrank.append(temp)
for i in maxrank:
    if len(np.array(i).shape)==1:
        count-=1
        print(i,end="")
        print("              rank "+str(count))
        avgrank+=count
    else:
        count-=len(i)
        avgrank+=count*len(i)
        for j in i:
            print(j,end="")
            print("             rank "+str(count))
    if count>mrank:
        mrank=count
    srank=count   
    
print("點的個數  ",datalen)   
print("最大 rank ",mrank)
print("最小 rank ",srank)
print("平均 rank %.2f" % (avgrank/datalen))


