def find_lc(str1:str,str2:str):
    """
    找到str1和str2之间的最长子字符串，返回其长度和该字符串
    """
    m = [ [ 0 for _ in range(len(str2)+1) ] for _ in range(len(str1)+1) ]  #长度
    d = [ [ '' for _ in range(len(str2)+1) ] for _ in range(len(str1)+1) ]  #子字符串

    for p1 in range(len(str1)):
        for p2 in range(len(str2)):
            if str1[p1]==str2[p2]:
                m[p1+1][p2+1]=m[p1][p2]+1
                d[p1+1][p2+1]=d[p1][p2]+str1[p1]
            elif m[p1+1][p2]>m[p1][p2+1]:
                m[p1+1][p2+1]=m[p1+1][p2]
                d[p1+1][p2+1]=d[p1+1][p2]
            else:
                m[p1+1][p2+1]=m[p1][p2+1]
                d[p1+1][p2+1]=d[p1][p2+1]
    
    return (m[len(str1)][len(str2)],d[len(str1)][len(str2)])

print(find_lc('1357904','20468'))