one = [int(x) for x in input().split()]
two = [int(x) for x in input().split()]
three = [int(x) for x in input().split()]

all = [one, two, three]

x_counter = {}
y_counter = {}


for arr in all:
    if arr[0] not in x_counter:
        x_counter[arr[0]] = 1
    else:
        x_counter[arr[0]] += 1

    if arr[1] not in y_counter:
        y_counter[arr[1]] = 1
    else:
        y_counter[arr[1]] += 1

x = None
y = None

for item in x_counter:
    if x_counter[item] == 1:
        x = item
        break

for item in y_counter:
    if y_counter[item] == 1:
        y = item
        break
print(x, y)
