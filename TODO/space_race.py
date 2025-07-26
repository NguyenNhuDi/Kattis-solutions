def main():
    n = int(input())
    d = float(input())
    inpoo = []

    for i in range(n):
        t = input().split()
        inpoo.append([d / float(t[2]),t[0]])

    inpoo.sort(reverse=True)
    print(inpoo[0][1])
main()
