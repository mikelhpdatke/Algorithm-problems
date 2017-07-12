#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Jul 12 10:15:46 2017

@author: malware
"""

n, m = map(int, input().split())

c = []
a = []
numBlack = 0
for i in range(n):
    st = str(input())
    #print(st)
    c.append([])
    for ch in st:
        c[i].append(ch)
s = []
#print(c)

for i in range(n):
    a.append([0]*m)
    s.append([0]*m)
    for j in range(m):
        if (c[i][j] == 'W'):
            a[i][j] = 0
        else:
            a[i][j] = 1
        numBlack = numBlack + a[i][j]

s[0][0] = a[0][0]
for i in range(1, n):
        s[i][0] = s[i - 1][0] + a[i][0]
        
for j in range(1, m):
    s[0][j] = s[0][j - 1] + a[0][j]
    
    
for i in range(1, n):
    for j in range(1, m):
        s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j]
#print(numBlack)
res = 123456789
for len in range(1, min(n, m) + 1):
    for i in range(n - len + 1):
        for j in range(m - len + 1):
            square = len * len
            if (i == 0):
                One = 0;
            else:
                One = s[i - 1][j + len - 1];
                Three = 0
            if (j == 0):
                Two = 0;
                Three = 0
            else:
                Two = s[i + len - 1][j - 1];
            if (i > 0 and j > 0): Three = s[i - 1][j - 1]
            Four = s[i + len - 1][j + len - 1];
            Black = Four - One - Two + Three 
           
            if (Black != numBlack): continue
            #print(len, ' ',i,' ',j,' ',Black,' ', square)
            cur = square - Black
            res = min(res, cur)
if (res == 123456789): res = -1
print(res)

