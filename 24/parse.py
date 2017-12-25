import sys

printed_lines = []
for line in sys.stdin.readlines():
    printed_lines.append(" ".join(line.strip().split('/')))
print len(printed_lines)
for l in printed_lines:
    print l
