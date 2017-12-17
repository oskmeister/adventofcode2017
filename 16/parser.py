import sys

ops = sys.stdin.readline().strip().split(",")
for x in ops:
    if x[0] == 's':
        a = int(x[1:])
        print "spin", a
    if x[0] == 'x':
        a, b = map(int,x[1:].split('/'))
        print "swap", a, b
    if x[0] == 'p':
        a, b = x[1:].split('/')
        print "swapname", a, b
