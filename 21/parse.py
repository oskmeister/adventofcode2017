import sys

lines = []

for line in sys.stdin.readlines():
    lines.append(line)

print len(lines)
for line in lines:
    pat_from, pat_to = line.strip().split(" => ")
    list_from = pat_from.split("/")
    list_to = pat_to.split("/")
    print len(list_from[0]), " ".join(list_from), " ".join(list_to)
