class Solution:

    def __DFSHelp(self, node, neighbors, visited):
        if visited[node] == False:
            visited[node] = True
            for u in neighbors[node]:
                self.__DFSHelp(u, neighbors, visited)

    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        """
        :type isConnected: List[List[int]]
        :rtype: int
        """
        V = range(len(isConnected))
        neighbors={}
        visited={}

        for v in V:
            neighbors[v]=[]
            visited[v]=False

        for v in V:
            for i, u in enumerate(isConnected[v]):
                if u == 1:
                    neighbors[v].append(i)
        
        count = 0
        for v in V:
            if not visited[v]:
                count+=1
                self.__DFSHelp(v, neighbors, visited)

        return count
        