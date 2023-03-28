a = (int)(str(input()))
#b = map(int,input().split())
cnt = 0

for x in input().split():
    if(int(x) < 0):
        cnt += 1

print(cnt)