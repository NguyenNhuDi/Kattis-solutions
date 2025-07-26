def main():
    
    right = 0
    tTime = 0
    
    problems = {}

    while True:
        inpoo = input()
        if inpoo == '-1':
            break

        time, problem, correct = inpoo.split()

        time = int(time)

        if problem not in problems:
            problems[problem] = 0


        if correct == 'right':
            right += 1
            tTime += time
            tTime += problems[problem] * 20
        else:
            problems[problem] += 1
            
    
    print(f'{right} {tTime}')

main()
