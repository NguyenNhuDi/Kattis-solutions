from sys import stdin

def main():
    inpoo = input()
    ans = [1, None, None]

    for c in inpoo:
        if c == 'A':
            ans[0], ans[1] = ans[1], ans[0]
        elif c == 'B':
            ans[1], ans[2] = ans[2], ans[1]
        else:
            ans[0], ans[2] = ans[2], ans[0]

    for i, item in enumerate(ans):
        if item:
            print(i + 1)
            break

if __name__ == '__main__':
    main()