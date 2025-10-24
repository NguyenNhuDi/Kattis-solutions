from sys import stdin

def main():
    for line in stdin:
        words = line.split()

        name = []
        number = []

        for word in words:
            try:
                number.append(float(word))
            except:
                name.append(word)

        print(f"{sum(number) / len(number):.3f} {' '.join(name)}")


if __name__ == '__main__':
    main()