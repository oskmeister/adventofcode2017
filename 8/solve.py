import sys
def fix(s): return 'd.get("' + s + '", 0)'
d = {}
totmax = 0
for line in sys.stdin.readlines():
    l = line.strip().split()
    l[1] = '+' if l[1] == 'inc' else '-'
    l[4] = fix(l[4])
    cond = eval("".join(l[4:]))
    varname = l[0]
    l[0] = fix(l[0])
    if cond: d[varname] = eval("".join(l[:3]))
    totmax = max(totmax, d.get(max(d, key=d.get)))
print d.get(max(d, key=d.get))
print "Total max: ", totmax
