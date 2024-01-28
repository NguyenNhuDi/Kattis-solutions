import os
import glob


if __name__ == '__main__':
    f = open('README.md', 'w')

    cDir = os.getcwd()

    pFile = glob.glob(f'{cDir}/*.py')
    cppFile = glob.glob(f'{cDir}/*.cpp')

    pLen = len(pFile) - 1 # exclude this file
    cppLen = len(cppFile)


    f.write(f'Total problems solved: {pLen + cppLen}\n')
    f.write(f'Total problems solved with Python: {pLen}\n')
    f.write(f'Total problems solved with C++: {cppLen}\n')

    f.close()