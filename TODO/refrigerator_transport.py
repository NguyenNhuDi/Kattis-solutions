import math

cost_a, cap_a, cost_b, cap_b, tot = input().split()
cost_a, cap_a, cost_b, cap_b, tot = int(cost_a), int(cap_a), int(cost_b), int(cap_b), int(tot)

costs = []


run_amount = tot // cap_a

y = -1
i = 1
while y!= 0:
    # whats left over
    y =  math.ceil((tot - (i * cap_a)) / cap_b)

    if y * cap_b + i * cap_a >= tot:
        costs.append((i, y, y * cost_b + i * cost_a))
    i += 1

costs.sort(key=lambda x :x[2])

print(int(costs[0][0]), int(costs[0][1]), int(costs[0][2]))





