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

print(bcolors.BOLD + "Checking your outputs" + bcolors.ENDC)

try:
    with open("out", "r") as f:
        outputs = f.read()
        results = list(map(lambda elem: elem.upper(), outputs.split('\n')))
        results = list(filter(lambda elem: len(elem) != 0, results))
        print("Enter expected outputs:-")
        expected = []
        for i in range(len(results)):
            testcase_output = input()
            expected.append(testcase_output.upper())
        flag = False
        for i in range(len(results)):
            if expected[i].rstrip() != results[i].rstrip():
                flag = True
                print(f"{bcolors.FAIL}FAILED AT TESTCASE: {i+1}{bcolors.ENDC}")
                print(f"\tExpected: {expected[i]}")
                print(f"\tFound   : {results[i]}")
        if not flag:
            print(bcolors.OKCYAN + bcolors.BOLD+ "ALL TESTS PASSED!" + bcolors.ENDC*2)

except FileNotFoundError:
    print(bcolors.FAIL + "First run dbgrun to check outputs and store in \"out\"" + bcolors.ENDC)


