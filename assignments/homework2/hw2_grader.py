#!/usr/bin/python
# -*- coding: utf-8 -*-
import os
from pprint import pprint
import codecs

def compare_file(file1, file2, file1_encoding='utf-8', file2_encoding='utf-8'):
    result = []
    with codecs.open(file1, encoding=file1_encoding) as f:
        result = f.readlines()

    expected = []
    with codecs.open(file2, encoding=file2_encoding) as f:
        expected = f.readlines()

    for i in range(len(result)):
        line =result[i].strip()
        expected_line = expected[i].strip()
        expected_line = expected_line.replace('-nan(ind)', 'nan')
        if not(line == expected_line):
            print(line, type(line))
            print(expected_line, type(expected_line))
        assert line == expected_line

def test_hw2_1():
    print('Check .gitignore')
    assert os.path.isfile('../../.gitignore') == True

    compare_file('../../.gitignore', 'VisualStudio.gitignore')

def test_hw2_2_1():
    print('Check output1.txt')
    compare_file(os.path.join('Taylor', 'Taylor', 'output1.txt'), 'output1.txt')
    print('Check output2.txt')
    compare_file(os.path.join('Taylor', 'Taylor', 'output2.txt'), 'output2.txt')

def test_hw2_2_2():
    compare_file(os.path.join('Taylor', 'Taylor', 'output1.txt'), 'solution1.txt')

def test_hw2_2_3():
    compare_file(os.path.join('Taylor', 'Taylor', 'output2.txt'), 'solution2.txt')

def test_hw2_3():
    file_list = []
    for root, dirs, files in os.walk(".", topdown=False):
        for name in files:
            file_list.append(os.path.join(root, name))

    expected = [os.path.join('.', 'Taylor', 'Taylor.sln'),
                os.path.join('.', 'Taylor', 'Taylor', 'Taylor.vcxproj'),
                os.path.join('.', 'Taylor', 'Taylor', 'Taylor.vcxproj.filters'),
                os.path.join('.', 'Taylor', 'Taylor', 'TaylorMain.c'),
                os.path.join('.', 'Taylor', 'Taylor', 'TaylorMath.c'),
                os.path.join('.', 'Taylor', 'Taylor', 'TaylorMath.h'),
                os.path.join('.', 'output1.txt'),
                os.path.join('.', 'output2.txt'),]

    for file in expected:
        assert (file in file_list)

def test_hw2_4():
    print('Check tag homework2')
    from git import Repo
    import pytz
    import datetime
    repo = Repo('../../')

    assert 'homework2' in repo.tags
    hw2_tag = repo.tags['homework2']
    
    commit_datetime = hw2_tag.commit.committed_datetime
    due_date = datetime.datetime(2016, 10, 13, 0, 0, 0)

    assert commit_datetime.replace(tzinfo=None) < due_date


if __name__ == "__main__":
    print("Running test... ")
    test_hw2_1()
    test_hw2_2_1()
    test_hw2_2_2()
    test_hw2_2_3()
    test_hw2_3()
    test_hw2_4()