import os.path
from pprint import pprint

def test_hw1_2():
    print('Check existence of README.md')
    assert os.path.isfile('../../README.md') == True

def test_hw1_3_1():
    print('Check bash script result')

    results = []
    with open('testOutput.txt') as f:
        tmp = f.readlines()
        for line in tmp:
            results.append(line.rstrip().replace("\r", ""))

    name = results[1].split('Code run by')[1].strip()

    solutions = []
    with open('testSolution.txt') as f:
        tmp = f.readlines()
        for line in tmp:
            solutions.append(line.rstrip().replace("\r", ""))

    for i in range(len(solutions)):
        if (i == 4) or (i ==11): #ignore version of mingw and visual studio
            continue
        line = solutions[i].replace('**INSERT YOUR NAME HERE**', name)

        if not ( results[i] == line):
            print(results[i], line)

def test_hw1_3_2():
    hello_world_results = []
    with open('HelloWorld.txt') as f:
        tmp = f.readlines()
        for line in tmp:
            hello_world_results.append(line.rstrip().replace("\r", ""))

    results = []
    with open('testOutput.txt') as f:
        tmp = f.readlines()
        for line in tmp:
            results.append(line.rstrip().replace("\r", ""))

    assert hello_world_results[0] == results[-2]
    assert hello_world_results[1] == results[-1]

def test_hw1_4():
    print('Check tag homework1')
    from git import Repo
    repo = Repo('../../')

    assert 'homework1' in repo.tags

if __name__ == "__main__":
    print("Running test... ")
    test_hw1_2()
    test_hw1_3_1()
    test_hw1_4()
    test_hw1_3_2()

