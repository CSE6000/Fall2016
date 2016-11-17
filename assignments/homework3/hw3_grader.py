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

def test_hw3_1():
    print('3_1 Check OpenCV output')

    result = []
    with codecs.open(os.path.join('AffineTransform', 'x64', 'Debug', 'output.txt'), encoding='utf-8') as f:
        result = f.readlines()

    expected = []
    with codecs.open(os.path.join('AffineTransform', 'x64', 'Debug', 'solution.txt'), encoding='utf-8') as f:
        expected = f.readlines()

    for i in range(13, 16):
        assert result[i] == expected[i]

def test_hw3_2():
    print('3_2 Check MKL output')
    result = []
    with codecs.open(os.path.join('AffineTransform', 'x64', 'Debug', 'output.txt'), encoding='utf-8') as f:
        result = f.readlines()

    expected = []
    with codecs.open(os.path.join('AffineTransform', 'x64', 'Debug', 'solution.txt'), encoding='utf-8') as f:
        expected = f.readlines()

    import re
    from nose.tools import assert_almost_equal
    for i in range(18, 20):
        # print(i)
        result_nums = [float(re.sub('[^a-zA-Z0-9-_*.]', '', my_str))  for my_str in result[i].strip().split(",")]
        expected_nums = [float(re.sub('[^a-zA-Z0-9-_*.]', '', my_str))  for my_str in expected[i].strip().split(",")]
        
        for x in range(3):
            if (result_nums[x] - expected_nums[x]) > 1e-6:
                print(result_nums[x] - expected_nums[x])
            assert_almost_equal(result_nums[x], expected_nums[x], 6)

def test_hw3_3():
    print('3_3 Check output.txt')
    compare_file(os.path.join('AffineTransform', 'x64', 'Debug', 'output.txt'), 'output.txt')    

def test_hw3_4():
    print('3_4 Check files')
    tmp = []
    with codecs.open(os.path.join('file_list.txt'), encoding='utf-8') as f:
        tmp = f.readlines()

    file_list = [item.strip() for item in tmp]

    expected = [unicode(os.path.join('.', 'AffineTransform', 'AffineTransform.sln'), 'utf-8'),
                unicode(os.path.join('.', 'AffineTransform', 'AffineTransform', 'AffineTransform.vcxproj'), 'utf-8'),
                unicode(os.path.join('.', 'AffineTransform', 'AffineTransform', 'AffineTransform.vcxproj.filters'), 'utf-8'),
                unicode(os.path.join('.', 'AffineTransform', 'AffineTransform', 'AffineTransform.cpp'), 'utf-8'),
                unicode(os.path.join('.', 'AffineTransform', 'AffineTransform', 'HappyFish.jpg'), 'utf-8'),
                unicode(os.path.join('.', 'output.txt'), 'utf-8'),
                ]

    with open('expected_file_list.txt', 'w') as f:
        f.write("\n".join(expected))

    for file in expected:
        assert (file in file_list)

def test_hw3_5():
    print('3_5 Check tag homework3')
    from git import Repo
    import pytz
    import datetime
    repo = Repo('../../')

    assert 'homework3' in repo.tags
    hw2_tag = repo.tags['homework3']
    
    commit_datetime = hw2_tag.commit.committed_datetime
    due_date = datetime.datetime(2016, 11, 16, 0, 0, 0)

    assert commit_datetime.replace(tzinfo=None) < due_date


if __name__ == "__main__":
    print("Running test... ")
    test_hw3_1()
    test_hw3_2()
    test_hw3_3()
    test_hw3_4()
    test_hw3_5()