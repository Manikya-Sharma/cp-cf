import sys
import os
import subprocess
import time


class bcolors:
    HEADER = "\033[95m"
    OKBLUE = "\033[94m"
    OKCYAN = "\033[96m"
    OKGREEN = "\033[92m"
    WARNING = "\033[93m"
    FAIL = "\033[91m"
    ENDC = "\033[0m"
    BOLD = "\033[1m"
    UNDERLINE = "\033[4m"


input_file = "a.cpp" if len(sys.argv) == 1 else sys.argv[1]
print(f"{bcolors.BOLD}Executing {input_file}{bcolors.ENDC}", file=sys.stderr)

try:
    f = open("in", "r")
except:
    print(
        f'{bcolors.FAIL}ERROR: Enter the testcases in "in"{bcolors.FAIL}',
        file=sys.stderr,
    )
else:
    status = os.system(
        f"g++ -Wall -Wextra -Wshadow -Wfloat-equal -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector -DLOCAL -g -o sample_output.out {input_file}"
    )
    if status == 0:
        print(f"{bcolors.BOLD}Compiled successfuly\n{bcolors.ENDC}", file=sys.stderr)
    else:
        print(f"{bcolors.FAIL}Status returned: {status}{bcolors.ENDC}", file=sys.stderr)
    try:
        start = time.time()
        output = subprocess.check_output([f"./sample_output.out < in"], shell=True)
        end = time.time()
    except subprocess.CalledProcessError as err:
        print(err)
    else:
        print(output.decode())
        print(
            f"{bcolors.BOLD}Time taken: {(end-start):.5f} s{bcolors.ENDC}",
            file=sys.stderr,
        )
