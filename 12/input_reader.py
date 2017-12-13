import re
import sys
lines = sys.stdin.readlines()
for l in lines:
    numbers = filter(lambda x: x.isdigit(), re.split(r'(\d+)', l))
    print len(numbers)-1, " ".join(numbers[1:])
