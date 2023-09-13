from copy import deepcopy

class Solution:

    def __DFSHelp(self, node, neighbors, visited, targetNode, distance):
        if visited[node] == False:
            visited[node] = True
            for u, weight in neighbors[node]:
                if u == targetNode:
                    return distance * weight
                else:
                    target_distance = self.__DFSHelp(u, neighbors, visited, targetNode, distance * weight)
                    if target_distance != -1 and target_distance is not None:
                        return target_distance
            return -1

    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:

        V = set()
        for (u, v) in equations:
            V |= {u, v}
        V = list(V)

        neighbors = {v: [] for v in V}
        
        for (u, v), weight in zip(equations, values):
            neighbors[u] += [(v, 1/weight)]
            neighbors[v] += [(u, weight)]
            
        returnVals = []
        for (w, z) in queries:
            if (w not in neighbors) or (z not in neighbors):
                returnVals.append(-1)
            elif w == z:
                returnVals.append(1)
            else:
                visited = {v: False for v in V}
                distance = 1.0
                target_distance = self.__DFSHelp(z, neighbors, visited, w, distance)
                returnVals.append(target_distance)

        return returnVals        