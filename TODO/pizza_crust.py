def main():
    n = (int(x) for x in input().split())
    r, c = n
    pi = 3.14159
    has_cheese = (r-c) * (r-c) * pi
    area = r * r * pi
    print(has_cheese / area * 100)

main()
