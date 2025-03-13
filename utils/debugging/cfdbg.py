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


if len(sys.argv) == 1:
    print(bcolors.FAIL + "Which part to debug?" + bcolors.ENDC)
    exit(1)

part = sys.argv[1].rstrip(".")

input_file = f"{part}.cpp"
output_file = f"{part}.out"
print(f"{bcolors.BOLD}Executing {input_file}{bcolors.ENDC}", file=sys.stderr)

try:
    f = open(f"{part}.in", "r")
except:
    print(
        f'{bcolors.FAIL}ERROR: Enter the testcases in "{part}.in"{bcolors.FAIL}',
        file=sys.stderr,
    )
else:
    flags = "-Wall -Wextra -Wconversion -O2 -Wshadow -Wfloat-equal -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector"
    local = "-DLOCAL"
    status = os.system(f"g++ {flags} {local} -g -o {output_file} {input_file}")
    if status == 0:
        print(f"{bcolors.BOLD}Compiled successfuly\n{bcolors.ENDC}", file=sys.stderr)
    else:
        print(f"{bcolors.FAIL}Status returned: {status}{bcolors.ENDC}", file=sys.stderr)
    try:
        start = time.time()
        output = subprocess.check_output([f"./{output_file} < {part}.in"], shell=True)
        end = time.time()
    except subprocess.CalledProcessError as err:
        print(err)
    else:
        print(output.decode())
        print(
            f"{bcolors.BOLD}Time taken: {(end-start):.5f} s{bcolors.ENDC}",
            file=sys.stderr,
        )
