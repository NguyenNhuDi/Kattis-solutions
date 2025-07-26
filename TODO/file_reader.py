
my_ans = r'/home/di_nguyen/UNI/CPC/CPSC 591/Week 3/out.txt'
real_ans = r'/home/di_nguyen/UNI/CPC/CPSC 591/Week 3/rout.txt'


ma = open(my_ans, 'r')
ra = open(real_ans, 'r')


valid = True

counter = 1

while(True):

    mR = ma.readline()
    rR = ra.readline()


    if (mR != rR):
        valid = False
        print(f'bad at line {counter}')
        break

    if (mR == ""):
        break

    counter += 1

print("good" if valid else "bad")

