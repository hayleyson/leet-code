class Solution(object):

    def __DFSHelp(self, node, neighbors, visited):
        if visited[node] == False:
            visited[node] = True
            for u in neighbors[node]:
                self.__DFSHelp(u, neighbors, visited)

    def canVisitAllRooms(self, rooms):
        """
        :type rooms: List[List[int]]
        :rtype: bool
        """

        V = range(len(rooms))
        neighbors={}
        visited={}
        
        for v in V:
            neighbors[v] = rooms[v]
            visited[v] = False

        self.__DFSHelp(0, neighbors, visited)

        for v in V:
            if not visited[v]:
                return False
        return True

        
        