#Geppetto

n,m = input().split()

n,m = [int(n), int(m)]


pizza = set()

illegal = [[False for j in range(n)] for i in range(n)]

for i in range(m):
    a,b = input().split()
    a,b = [int(a), int(b)]

    illegal[a-1][b-1] = True
    illegal[b-1][a-1] = True


def findPizza(topping,num):

    if num == 0:
        return 1
    
    count = 0

    count = findPizza(topping, num-1)

    allowed = True
    for i in topping:
        if illegal[i-1][num-1]:
            allowed = False
            break
    
    if allowed:
        topping.add(num)
        count += findPizza(topping,num-1)
        topping.remove(num)

    return count



print(findPizza(pizza,n))
