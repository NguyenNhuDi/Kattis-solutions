total, carWeight, n = [int(x) for x in input().split()]
weights = [int(x) for x in input().split()]

maxWeight = (total-carWeight)/100 * 90

for i in weights:
    maxWeight -= i
    
print(int(maxWeight))
