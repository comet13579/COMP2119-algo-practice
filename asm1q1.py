import math

n = 143 ## 100 growth

print("a:", math.pow(n, math.pi))
print("b:", math.pow(math.pi, n))
print("c:", math.pow(n, n))
print("d:", math.log(n, 2))
print("e:", math.pow(math.pi, math.log(n, 2)))
print("f:", math.pow(n, math.log(math.pi, 2)))
print("g:", n / math.log(math.pi, 2))
print("h:", n / math.log(n, 2))
print("i:", n / math.log(math.log(n, 2), 2))
print("j:", math.log(n / math.log(n, 2), 2))
print("k:", math.pow(math.pi,math.log(2 * n, 2)))
print("l:", math.pow(n,math.log(2 * math.pi, 2)))

msum = 0
for i in range(1,n+1):
    msum += (i+1)
print("m:", math.pow(msum,0.5))

print("n:", 1910 * math.factorial(n) + 316 * math.pow(n,n))