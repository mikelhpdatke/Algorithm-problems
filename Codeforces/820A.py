#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jul 10 09:21:33 2017

@author: malware
"""


c, v0, v1, a, l = map(int, input().strip().split())

res = 0 
cur = v0
while (c > 0):
    if (res == 0):
        res = res + 1
        c -= cur
    else:
        res = res + 1
        c -= cur - l
    cur = min(a + cur, v1)
    
print(res)
        