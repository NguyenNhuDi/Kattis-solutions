import os
from glob import glob


if __name__ == '__main__':

    curr_dir = os.path.dirname(__file__)

    comp_dirs = [i for i in glob(f'{curr_dir}/*') if os.path.isdir(i)]

    tracker = set()
    py_file = 0
    cpp_file = 0
    total = 0

    for dir in comp_dirs:
        curr_files = glob(f'{dir}/*')
        for f in curr_files:
            name, extension = os.path.basename(f).split('.')    

            if name not in tracker:
                total += 1

                if "cpp" in extension:
                    cpp_file += 1
                else:
                    py_file += 1

            tracker.add(name)

    with open(f'{curr_dir}/README.md', 'w') as f:
        f.write(f'Total problems solved: {total}  \n')
        f.write(f'Total problems solved with Python: {py_file}  \n')
        f.write(f'Total problems solved with C++: {cpp_file}  \n')