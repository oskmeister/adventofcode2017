import sys

def dfs(i, j, grid, vis):
    if i < 0 or j < 0 or i >= 128 or j >= 128: return
    if grid[i][j] == '0': return
    if vis[i][j]: return
    vis[i][j] = True
    dr = [1, 0, -1, 0]
    dc = [0, 1, 0, -1]
    for di in xrange(4):
        nr = i + dr[di]
        nc = j + dc[di]
        dfs(nr, nc, grid, vis)

count = 0
grid = [];
for line in sys.stdin.readlines():
    count += line.count('1')
    grid.append(line)
print "Set bits: ", count
vis = [[False for i in xrange(128)] for i in xrange(128)]
regions = 0
for i in xrange(128):
    for j in xrange(128):
        if grid[i][j] == '1' and not vis[i][j]:
            regions += 1
            dfs(i,j,grid,vis)
print "Regions: ", regions

