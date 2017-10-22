import subprocess
import os
import random

MAX_TEST_SIZE = 100000
MIN_TEST_SIZE = 1
MAX_VALUE = 100000000
TEST_NUMBER = 25


def gen_test(size):
    test = str(size) + '\n'
    data = []
    for j in range(0, size):
        next_value = random.randint(-MAX_VALUE, MAX_VALUE)
        test = test + str(next_value) + ' '
        data.append(next_value)
    data.sort()
    return (str(test), data)


def check_ans(number, size, correct_answer, answer):
    result = True
    for j in range(0, size):
        if str(correct_answer[j]) != str(answer[j]):
            result = False
            break
    if not result:
        print("WA" + str(number))
        return result
    return result


if __name__ == "__main__":
    random.seed()
    files = subprocess.check_output(["ls"], universal_newlines=True)
    files = files.split('\n')
    for program in files:
        if program[-4:] == ".cpp":
            subprocess.call(["g++", program, "-o", "check"])
            print("Checking " + program[:-4] + "...")
            verdict = True
            for i in range(0, TEST_NUMBER):
                print("TEST " + str(i + 1))
                test_size = random.randint(MIN_TEST_SIZE, MAX_TEST_SIZE)
                input_data = gen_test(test_size)
                p = subprocess.Popen(['./check'], stdout=subprocess.PIPE, stdin=subprocess.PIPE,
                                     universal_newlines=True)
                output_data = p.communicate(input=input_data[0])[0]
                verdict = check_ans(i + 1, test_size, input_data[1], output_data.split(' '))
                if not verdict:
                    break
            os.remove("check")
            if verdict:
                print("OK\n")
