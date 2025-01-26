import sys
import os
from datetime import date


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


# Take input
if len(sys.argv) == 1:
    print(bcolors.FAIL + "Question number not provided" + bcolors.ENDC)
    exit(1)
if len(sys.argv) < 2:
    print(bcolors.FAIL + "Question name not provided" + bcolors.ENDC)
    exit(1)

file_name = sys.argv[1] + ".cpp"
question = f"{os.getcwd().split('/')[-1]}_{sys.argv[1]}_{sys.argv[2]}"
is_no_testcase = ("notc" in sys.argv) or (os.environ.get("NOTC") == 1)

# Get all required data for template
path = sys.argv[0].rstrip("cf_template.py")
with open(f"{path}common_template.cpp") as f:
    template_data = f.read()
with open(
    f"{path}{'std_notc_template.cpp' if is_no_testcase else 'std_template.cpp'}"
) as f:
    main_data = f.read()

data = f"""/* ***  METADATA
PROBLEM: {question}
ON: {date.today()}
BY: Manikya
*** */

{template_data}
{main_data}

"""

with open(file_name, "w") as f:
    f.write(data)

print(f"{bcolors.BOLD}Template created successfully at {file_name}{bcolors.ENDC}")
