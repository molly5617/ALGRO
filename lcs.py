def longestCommonSequence(str_one, str_two, case_sensitive=True):
    len_str1 = len(str_one)
    len_str2 = len(str_two)
    record = [[0 for i in range(len_str2 + 1)] for j in range(len_str1 + 1)]
    for i in range(len_str1):
        for j in range(len_str2):
            if str_one[i] == str_two[j]:
                record[i + 1][j + 1] = record[i][j] + 1
            elif record[i + 1][j] > record[i][j + 1]:
                record[i + 1][j + 1] = record[i + 1][j]
            else:
                record[i + 1][j + 1] = record[i][j + 1]

    return record[-1][-1]

s1 = "BDCABA"
s2 = "ABCBDAB"
res = longestCommonSequence(s1, s2)
print(res)