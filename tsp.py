temp=[0]*441
with open("test5.txt","r") as f:
 sum=0
 i=-1;
 for line in f:#遍历每一行
     wordlist=line.split()#将每一行的数字分开放在列表中
     for a in wordlist:#遍历每一行的数字
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
      
        


   
