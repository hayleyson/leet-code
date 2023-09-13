class GraphNode:
    def __init__(self, val):
        self.val = val
        self.neighbors = []
        self.visited = False

class Solution:

    def orangesRotting(self, grid: List[List[int]]) -> int:

        nRows = len(grid)
        nCols = len(grid[0])

        rottens = deque()
        nfresh = 0
        for i in range(nRows):
            for j in range(nCols):
                if grid[i][j] == 2:
                    rottens.append((i, j))
                elif grid[i][j] == 1:
                    nfresh += 1
        
        minute = 0
        while (len(rottens)>0 and nfresh >0):
            new_rottens = deque()
            minute += 1

            for x, y in rottens:
                for dx, dy in [(1,0), (-1,0), (0,1), (0,-1)]:
                    x_adj = x+dx
                    y_adj = y+dy
                    if 0<= x_adj and x_adj < nRows and 0 <=y_adj and y_adj < nCols:
                        if grid[x_adj][y_adj]==1:
                            new_rottens.append((x_adj, y_adj))
                            nfresh -= 1
                            grid[x_adj][y_adj] = 2
                            if nfresh == 0:
                                return minute
            rottens = new_rottens
        if nfresh == 0:
            return minute
        else:
            return -1