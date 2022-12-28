import math
#檔案輸入
temp=[0]*441
with open("test5.txt","r") as f:
 sum=0
 i=-1;
 for line in f:
     wordlist=line.split()
     for a in wordlist:
        if(i==-1):
             n=(int(a))
        else:
            temp[i]=(int(a)) 
        i=i+1
f.close()
path=[[0]*n for i in range(n)]
for i in range(n) :
    for j in range (n) :
        path[i][j]=temp[i*n+j]

max=float('inf')     
        


    

def firstmin(path,i):
    min=max
    for j in range(n):
        if path[i][j]<min and i!=j:
            min=path[i][j]
            
    return min
            
    

def secmin(path ,i):
    first ,second =max,max
    for j in range (n):
        if (i==j):
            continue
        if (path[i][j]<=first):
            second = first
            first = path [i][j]
        elif(path[i][j]<=second and path[i][j]!=first):
            second= path[i][j]
            
    return second

def copy(nowpath):
    finalpath[:n+1]=nowpath[:]
    finalpath[n]=nowpath[0]
    
def TSPsearch(path, nowbound, weight, level, nowpath, visit):
    global cost
    
    if (level==n):
        if (path[nowpath[level-1]][nowpath[0]]!=0):
            nowcost=weight+path[nowpath[level - 1]][nowpath[0]] 
                
            if nowcost<cost:
                copy(nowpath)
                cost=nowcost
        return
    
    for i in range(n):
        if(path[nowpath[level-1]][i] != 0 and visit[i] == False):
            temp=nowbound
            #print(temp)
            weight+=path[nowpath[level - 1]][i] 
            #print(weight)
            print(nowpath[level-1])
            
            if level == 1:
                nowbound -= ((firstmin(path, nowpath[level - 1]) +firstmin(path, i)) / 2)
            else:
                nowbound -= ((secmin(path, nowpath[level - 1]) +firstmin(path, i)) / 2)
                
            if nowbound + weight < cost:
                nowpath[level] = i
                visit[i] = True
                
                TSPsearch(path, nowbound, weight,level + 1, nowpath, visit)
            
            print(nowbound)
            weight -= path[nowpath[level - 1]][i]
            nowbound = temp  
            
            visit = [False] * len(visit)
            for j in range(level):
                if nowpath[j] != -1:
                    visit[nowpath[j]] = True 
	

def TSP(path):
    nowbound=0
    nowpath=[-1]*(n+1)
    visit=[False]*n
    
    #計算最低成本
    for i in range (n):
        nowbound+=(firstmin(path,i))+secmin(path,i)
        
    nowbound=math.ceil(nowbound/2) #取天花板
    
    
    visit[0]=True
    nowpath[0]=0
    TSPsearch(path, nowbound, 0, 1, nowpath, visit)
    
    
    
    
    







#main
finalpath=[None]*(n+1)
visit=[False]*n
cost=max
TSP(path)
print("Minimum cost :", cost)
print("Path Taken : ", end = ' ')
for i in range(n + 1):
	print(finalpath[i], end = ' ')
        

    
    

      
        


   
