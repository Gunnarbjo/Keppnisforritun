
a = input()
b = int(str(a))
c = input().split()
cnt = 1
works = True

for x in range(b):
    d = c[x]
    if(d != "mumble"):
        if((int)(d) != cnt):
            works = False
    cnt +=1


if(works):
    print("makes sense\n")
else:
    print("something is fishy\n")