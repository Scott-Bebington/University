t1 = v0
t2 = 0
IF t1 == t2 THEN L1 ELSE L2

LABEL L1
t3 = v2 
v1 = t3 
GOTO L3 

LABEL L2

LABEL L4
t3 = v2
t4 = 0
IF t3 ≠ t2 THEN L5 ELSE L6

LABEL L5
t6 = v0
t7 = v2
IF t6 > t7 THEN L7 ELSE L8

LABEL L7
t9 = v0
t10 = v2
t8 = t9 - t10
v0 = t8
GOTO L9

LABEL L8
t12 = v2
t13 = v0
t11 = t12 - t13
v2 = t11

LABEL L9
GOTO L4 
LABEL L6
LABEL L3
