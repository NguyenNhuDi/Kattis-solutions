from sys import stdin

def main():
    words = []

    for line in stdin:
        words += line.split('\n')[0].split()

    out = []
    for i in range(len(words)):
        for j in range(len(words)):
            if i == j:
                continue

            if words[i] + words[j] not in out:
                out.append(words[i] + words[j])

    out.sort()
    for word in out:
        print(word)


if __name__ == '__main__':
    main()