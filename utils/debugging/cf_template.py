import sys
import os

file_name = (
    "a.cpp"
    if len(sys.argv) == 1
    else sys.argv[1] if sys.argv[1].rfind(".") != -1 else sys.argv[1] + ".cpp"
)

is_no_testcase = ("notc" in sys.argv) or (os.environ.get("NOTC") == 1)

with open(
    sys.argv[0].rstrip("cf_template.py")
    + ("std_template.cpp" if not is_no_testcase else "std_notc_template.cpp")
) as f:
    content = f.read()

with open(file_name, "w") as f:
    f.write(content)

print(f"Template created successfully at {file_name}")
