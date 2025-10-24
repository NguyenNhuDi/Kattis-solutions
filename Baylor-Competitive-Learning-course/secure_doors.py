from sys import stdin

def main():
    n = int(input())

    tracker = set()

    for i in range(n):
        op, name = input().split()

        if op == "entry":
            out = f"{name} entered"
            if name in tracker:
                out += " (ANOMALY)"
            tracker.add(name)
            print(out)
        else:
            out = f"{name} exited"
            if name not in tracker:
                out += " (ANOMALY)"
            else:
                tracker.remove(name)
            print(out)
            
if __name__ == '__main__':
    main()