class Solution:

    """ my solution using dfs -> didn't pass the time complexity """
    """
    def dfs(self, maze, curLoc, distance):
        curX, curY = curLoc
        for dx, dy in [[1,0], [-1,0], [0,1], [0,-1]]:
            if curX+dx >=0 and curX+dx < len(maze) and curY+dy >=0 and curY+dy < len(maze[0]) and self.cache.get((curX+dx, curY+dy), False) == False and maze[curX+dx][curY+dy] == '.':
                if curX + dx in [0, len(maze)-1] or curY + dy in [0, len(maze[0])-1]:
                    # print(curX+dx, curY+dy)
                    self.distances.append(distance+1)
                    return
                else:
                    self.cache[(curX+dx, curY+dy)] = True
                    self.dfs(maze, (curX+dx, curY+dy), distance+1)
                    self.cache[(curX+dx, curY+dy)] = False
        return


    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        self.cache = {tuple(entrance): True}
        self.distances = []
        self.dfs(maze, entrance, 0)
        if len(self.distances)==0:
            return -1
        return min(self.distances)
    """

    """ bfs solution by brushT"""
    """ the key is to loop over stepLengths and within that loop over directions """
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        dirs = [(0,1),(0,-1),(1,0),(-1,0)]
        entrance = (entrance[0],entrance[1])
        q = deque([entrance])
        visited = set()
        visited.add(entrance)
        step = 0
        while q:
            stepLength = len(q)
            for i in range(stepLength): # here, we can use length of the deque to iterate through level by level
                node = q.popleft()
                if node[0] == 0 or node[0] == len(maze) -1 or node[1] == 0 or node[1] == len(maze[0]) -1 :
                    if maze[node[0]][node[1]] == '.' and (node[0],node[1]) != entrance:
                        return step
                for d in dirs:
                    newD = (node[0] + d[0], node[1] + d[1])
                    if newD not in visited and 0<=newD[0]<len(maze) and 0<=newD[1]<len(maze[0]) and maze[newD[0]][newD[1]] == '.': # only add valid nodes to the queue!
                        visited.add(newD) # mark it as visited, so we don't loop forever
                        q.append(newD)
            step += 1 # after we finish with a level, increment step by one
        return -1