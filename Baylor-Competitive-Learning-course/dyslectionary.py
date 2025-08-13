from sys import stdin

def print_arr(arr):
    for i in arr:
        print(i)

def main():

    all_words = [[]]
    maxis = [-1]

    for line in stdin:
        word = line.split('\n')[0]
        if word == '':
            all_words.append([])
            maxis.append(-1)
            continue
            
        maxis[-1] = max(maxis[-1], len(word))
        all_words[-1].append(word)

    for i, words in enumerate(all_words):
        words.sort(key=lambda x : x[::-1])

        for word in words:
            diff = maxis[i] - len(word)

            space = "".join(" " for j in range(diff))
            print(f'{space}{word}')

        if i < len(maxis) - 1:
            print()

if __name__ == '__main__':
    main()