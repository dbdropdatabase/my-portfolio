a = 72
b = 132

def gcd(a,b):
    if b == 0:
        return a
    else:
        return gcd(b,a%b)
print(gcd(a,b))

def lcm(a,b):
    lcm1 = a*b / gcd(a,b)
    return lcm1
print(lcm(a,b)*(a,b))