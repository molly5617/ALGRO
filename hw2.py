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
def findmax(arr,start,end,ranks):
    if end-start==0:
        ranks[start]=0
        return 
    elif end-start==1:
        if arr[start][1]>arr[end][1]:
            ranks[start]=0
            ranks[end]=0
            return 
        else:
            ranks[start]=0
            ranks[end]=1
            return 
    else:
        
        findmax(arr, start, int((end+start)/2),ranks)
        findmax(arr,int((end+start)/2)+1,end,ranks)
        for i in range(int((end+start)/2)+1,end+1,1):
            for j in range(start, int((end+start)/2)+1,1):
                
                if arr[j][1]<arr[i][1]:
                    ranks[i]+=1
        return
       
                
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
            num.append(int(float(a[i])))
        else:
            num.append(float(a[i]))
    lii.append(num)
    
data = lii
heapSort(data)
print(data)
maxrank=[]
srank=len(data)
mrank=0
avgrank=0
for i in range(len(data)):
    maxrank.append(0)
findmax(data,0,len(data)-1, maxrank)

for i,j in zip(data,maxrank):
    print(i,end="")
    print("        rank ",str(j))
    if(j<srank):
        srank=j
    if(j>mrank):
        mrank=j
    avgrank+=j
print(maxrank)
print("點的個數  ",len(data))   
print("最大 rank ",mrank)
print("最小 rank ",srank)
print("平均 rank %.2f" % (avgrank/len(data)))


