#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Jul 12 09:45:32 2017

@author: malware
"""

n, a, b = map(int, input().strip().split())
T = map(int, input().strip().split())

c = 0
res = 0
for t in T:
    #print(t)
    if (t == 2):
        if (b > 0):
            b = b - 1
        else:
            res = res + 2
    elif (t == 1):
        if (a > 0):
            a = a - 1
        elif (b > 0):
            b = b - 1
            c = c + 1
        elif (c > 0):
            c = c - 1
        else:
            res = res + 1
print(res)        