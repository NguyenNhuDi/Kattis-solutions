from sys import stdin


def type_1(x, y):
    l = 0
    out = 0
    for r in range(len(x), len(y) + 1):
        if(y[l:r] == x):
            out += 1
        l += 1

    return out

def type_2(x, y):
    seen = set()

    out = 0
    for i in range(len(x)):
        word = list(x)
        word.pop(i)

        word = "".join(word)

        if word in seen:
            continue

        seen.add(word)
        out += type_1(word, y)

    return out

def type_3(x, y):
    if len(y) - len(x) == 0:
        return 0
    
    seen = set()
    chars = ['A', 'G', 'C', 'T']
    out = 0
    for char in chars:

        for i in range(len(x) + 1):
            word = list(x)
            word.insert(i, char)
            word = "".join(word)

            if word in seen:
                continue
            seen.add(word)

            out += type_1(word, y)
    return out

def main():
    for line in stdin:
        if line == '0\n':
            break

        s, l = line.split()
        a = type_1(s, l)
        b = type_2(s, l)
        c = type_3(s, l)
        print(f'{a} {b} {c}')
        


if __name__ == '__main__':
    main()