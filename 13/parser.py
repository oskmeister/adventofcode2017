import sys
for line in sys.stdin.readlines():
    print " ".join(line.strip().split(": "))
