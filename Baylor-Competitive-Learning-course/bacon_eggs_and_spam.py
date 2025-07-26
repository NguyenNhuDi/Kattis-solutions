if __name__ == '__main__':
    while True:
        try:
            n = int(input())

            data = {}
            for i in range(n):
                inpoo = input().split()

                name = inpoo[0]

                for i in range(1,len(inpoo)):
                    if inpoo[i] in data:
                        data[inpoo[i]].append(name)
                    else:
                        data[inpoo[i]] = [name]

            out_list = []

            for key in data:
                data[key].sort()
                out_list.append([key, data[key]])

            out_list.sort(key= lambda x : x[0])


            for i in out_list:
                print(i[0], end=' ')
                for j in range(len(i[1])):
                    print(f'{i[1][j]} ' if j != len(i[1]) - 1 else f'{i[1][j]}\n', end='')
                
            if n != 0:
                print()

        except EOFError:
            break