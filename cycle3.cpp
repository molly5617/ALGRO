#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

using namespace std;
struct cycles
{
    string string;
    int cost;
};
bool mycompare(cycles s1, cycles s2){
   return s1.cost < s2.cost;
}


int main(int argc,char *argv[])
{
    int i,j;
    string record[20000];
    FILE *fp;
    char newline[10],*tempch=" ";
    int nodenum,edgenum,cost,begin,end;
    cycles ans[20000];
    int ansnum=0;
    int before,after,first;
	fp=fopen("txt1.txt","r");
	fgets(newline,10,fp);

	sscanf(newline,"%i %i",&nodenum,&edgenum);
    int target=edgenum-nodenum+1;
    int A[nodenum][nodenum];//儲存連線的點
    int minimum[nodenum][nodenum]={0};
    for(i=0;i<nodenum;i++)
        for(j=0;j<nodenum;j++)
            A[i][j]=0;
    while(fgets(newline,10,fp) != NULL)
	{
	   sscanf(newline,"%i %i %i",&begin,&end,&cost);
	   A[begin][end]=1;
	   A[end][begin]=1;
       minimum[begin][end]=cost;
	   minimum[end][begin]=cost;
	}
	fclose(fp);

            int r,f;
   


    int k,c,pre,no;//第no格
    int b=0;//有b個temp(多出來的排列組合)
    int s=0,e=nodenum,cycle=0;
    int temp[nodenum];
    int order[20000][nodenum];//預設值-1
    int check_re[20000];
    int check_cycle[nodenum];
    int costsum[20000];
    int already[nodenum][nodenum];
    for(i=0;i<20000;i++)
        for(j=0;j<nodenum;j++)
            order[i][j]=-1;
    for(i=0;i<nodenum;i++)
        order[i][0]=i;
    int adde;
    int t;//比大小時的temp
    int smallest,compare;
    int m,n;

    for(no=1;no<nodenum;no++)//設定no
    {


        adde=0;
        s=0;
        for(k=0;k<e;k++)//做e次加長連線(e預設為nodenum)
        {
           s=s+b;
           b=0;
           pre=order[s][no-1];//pre是前一個頂點
           for((i=order[s][0]+1);i<nodenum;i++)//i=pre+1修改修改修改修改修改修改修改修改修改修改修改
           {
              if(A[pre][i]==1)
              {
                for(j=1;j<(no-1);j++)//for迴圈 檢查有沒有重複的頂點
                {
                    if(order[s][j]==i)
                    {
                        j=-1;
                        break;
                    }
                }
                if(j!=-1)
                    temp[b++]=i;//b計算多出來的排列組合
              }
           }
           c=0;

           if(b>0)
           {
               adde=adde+b-1;
               for(i=e+adde;i>s;i--)//往後移 (更改:e->e+adde)
               {
                  for(j=0;j<no;j++)
                      order[i+b-1][j]=order[i][j];
               }
               for(i=s;i<(s+b);i++)//補上&新連線
               {
                   order[i][no]=temp[c++];
                   for(j=0;j<no;j++)
                       order[i][j]=order[s][j];

                   //檢查cycle
                   if(no>1&&A[order[i][no]][order[i][0]]==1)
                   {

                       for(m=0;m<=no;m++)
                           check_cycle[m]=order[i][m];

                       compare=0;//檢查是否為反序

                       for(m=1;m<=no;m++)
                           compare=compare*10+check_cycle[m];
                       compare=compare*10+check_cycle[0];

                       check_re[i]=0;
                       for(m=no;m>=0;m--)
                           check_re[i]=check_re[i]*10+check_cycle[m];

                       for(m=0;m<i;m++)
                       {
                           if(check_re[m]==compare)
                           {
                               m=-1;
                               break;
                           }
                       }
                       if(m!=-1)
                       {
                            before=order[i][0];
                            for(j=0;j<=no;j++)
                                {
                                    //printf("%d->",order[i][j]);
                                    ans[cycle].string+=to_string(order[i][j])+"->";
                                    after=order[i][j];
                                    record[cycle]+=to_string(minimum[before][after])+"+";
                                    costsum[cycle]+=minimum[before][after];
                                    before=after;
                                    
                                    
                                }
                            costsum[cycle]+=minimum[before][order[i][0]];
                            record[cycle]+=to_string(minimum[before][order[i][0]]);
                            ans[cycle].string+=to_string(order[i][0]);
                            ans[cycle].cost=costsum[cycle];
                            //printf("%d",order[i][0]);
                            //printf(" %d",costsum[cycle]);
                            //printf("\n");
                            cycle++;
                            ansnum++;
                       }

                   }
               }
           }
           else//b==0
           {
               for(i=s;i<e+adde;i++)//往前移1格
               {
                  for(j=0;j<=no;j++)
                      order[i][j]=order[i+1][j];
               }
               adde--;
           }
        }
        e=e+adde;

    }
   int now=0;
   
    sort(ans, ans+cycle,  mycompare);

     for(i=0;i<ansnum;i++)
    {
        vector<string> v;
        int tempv[20000];
        while (1) {
        v.push_back(ans[i].string.substr(0, ans[i].string.find("->"))); // 從第一個空白分割出左側子字串放入vector
        ans[i].string = ans[i].string.substr(ans[i].string.find("->") + 1, ans[i].string.length()); // 從第一個空白分割出右側子字串設為s

        // 取得最後一個字。最後一個字找不到空白了
        if (ans[i].string.find("->") == -1) {
            v.push_back(ans[i].string);
            break;
        }
        }   
        int yes=0;
        string temps[20000];
        cout << v.size() << endl; // 3
        for(int n=0;n<v.size();n++)
        {
            temps[i]+=v[n];
            cout<<v[n]<<" ";
            
        }
        

       
        
        

       
   
    }
     printf("%d cycles\n",cycle);
    getchar();
    
}