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


def compile(input_file, output_file):
    flags = "-Wall -Wextra -Wconversion -O2 -Wshadow -Wfloat-equal -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector"
    local = "-DLOCAL"
    status = os.system(f"g++ {flags} {local} -g -o {output_file} {input_file}")
    if status == 0:
        print(f"{bcolors.BOLD}Compiled successfuly\n{bcolors.ENDC}", file=sys.stderr)
    else:
        print(f"{bcolors.FAIL}Status returned: {status}{bcolors.ENDC}", file=sys.stderr)


def simple_show(output):
    print(output)


def diff_show(out, exp):
    out_lines = list(out.splitlines())
    exp_lines = list(exp.splitlines())
    max_out_w = 0
    max_exp_w = 0
    for line in out_lines:
        max_out_w = max(max_out_w, len(line))
    for line in exp_lines:
        max_exp_w = max(max_exp_w, len(line))
    print(f"{'OUTPUT': <{max_out_w}}\t{'EXPECTED': <{max_exp_w}}")
    is_exact = True
    for i in range(max(len(out_lines), len(exp_lines))):
        out_line = out_lines[i] if i < len(out_lines) else ""
        exp_line = exp_lines[i] if i < len(exp_lines) else ""
        if out_line != exp_line:
            is_exact = False
        print(
            f"{bcolors.BOLD if out_line == exp_line else bcolors.FAIL}{out_line: <{max_out_w}}{bcolors.ENDC}\t{exp_line: <{max_exp_w}}"
        )
    if not is_exact:
        print(f"\n{bcolors.FAIL}======  FAIL  ======{bcolors.ENDC}")
    else:
        print(f"\n{bcolors.BOLD}====== SUCCESS ======{bcolors.ENDC}")


def run(output_file, part, expected_file, has_exp):
    try:
        start = time.time()
        output = subprocess.check_output([f"./{output_file} < {part}.in"], shell=True)
        end = time.time()
    except subprocess.CalledProcessError as err:
        print(err)
    else:
        if not has_exp:
            simple_show(output.decode())
        else:
            with open(expected_file, "r") as f:
                exp = f.read()
            diff_show(output.decode(), exp)
        print(
            f"{bcolors.BOLD}Time taken: {(end - start):.5f} s{bcolors.ENDC}",
            file=sys.stderr,
        )


if len(sys.argv) == 1:
    print(bcolors.FAIL + "Which part to debug?" + bcolors.ENDC)
    exit(1)

part = sys.argv[1].rstrip(".")

input_file = f"{part}.cpp"
output_file = f"x_{part}.out"
expected_file = f"{part}.exp"
with open(expected_file, "r") as f:
    has_exp = len(f.read()) > 0

print(
    f"{bcolors.BOLD}Executing {input_file} {'with diff' if has_exp else ''}{bcolors.ENDC}",
    file=sys.stderr,
)

try:
    f = open(f"{part}.in", "r")
except:
    print(
        f'{bcolors.FAIL}ERROR: Enter the testcases in "{part}.in"{bcolors.ENDC}',
        file=sys.stderr,
    )
else:
    compile(input_file, output_file)
    run(output_file, part, expected_file, has_exp)
