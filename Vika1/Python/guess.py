import sys

mid = 500
min = 1
max = 1001

for x in range(10):
    print(mid)
    sys.stdout.flush()
    resp = input()
    if(resp == "correct"): break
    if(resp == "higher"): min = mid
    if(resp == "lower"): max = mid
    mid = min + (max - min)//2