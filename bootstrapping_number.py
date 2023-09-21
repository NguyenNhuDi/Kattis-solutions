# Bootstrapping Number

import math

def aprox(x, y, n, prev_x):
    if x - 10e-9 <= prev_x <= x + 10e-9:
        return x 

    log_x = math.log(x)

    if n - 10e-6 <= x ** x <= n + 10e-6:
        return x
    
    return aprox((x + y) / (log_x + 1) , y, n, x)


n = int(input())

y = math.log(n)

print(aprox(1, y, n, -1))


