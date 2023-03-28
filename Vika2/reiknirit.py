a = (int(str(input())))
b = (int(str(input())))

def sum(n,cnt):
    if(cnt < a):
        return sum(n + b[cnt],cnt+1)
    return n

sum(0,0)