import sys
import os
import subprocess

input_file = "a.cpp" if len(sys.argv)==1 else sys.argv[1]
print(f"Executing {input_file}")
output_file = "output.txt"

status = os.system(f"g++ -Wall -Wextra -Wshadow -Wfloat-equal -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector -DLOCAL -g -o sample_output.out {input_file}")

if (status == 0):
    print("Compiled successfuly")
else:
    print(f"Status returned: {status}")


if len(sys.argv) > 2:
    if sys.argv.count("debug") > 0:
        os.system("gdb sample_output.out")
else:
    print("Enter the testcases:-")

    try:
        output = subprocess.check_output(["./sample_output.out"])
        with open(output_file, "wb") as f:
            f.write(output)
        print(f"Output written to {output_file}")
    except subprocess.CalledProcessError as err:
        print(err)

if sys.argv.count("preserve") == 0:
    os.system("rm sample_output.out")
os.system(f"cat {output_file}")


