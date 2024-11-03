print("Checking your outputs")

try:
    with open("output.txt", "r") as f:
        outputs = f.read()
        results = list(map(lambda elem: elem.upper(), outputs.split()))
        print("Enter expected outputs:-")
        expected = []
        for i in range(len(results)):
            testcase_output = input()
            expected.append(testcase_output.upper())
        flag = False
        for i in range(len(results)):
            if expected[i].rstrip() != results[i].rstrip():
                flag = True
                print(f"!!FAILED AT TESTCASE: {i+1}")
                print(f"Expected: {expected[i]}")
                print(f"Found   : {results[i]}")
        if not flag:
            print("ALL TESTS PASSED!")

except FileNotFoundError:
    print("First run dbgrun to check outputs!")


