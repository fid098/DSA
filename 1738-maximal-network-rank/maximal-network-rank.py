class Solution:
    def maximalNetworkRank(self, n: int, roads: list[list[int]]) -> int:
        
        """
        
        i need to know the edges each node has 
        i need to know if 2 edges are connected 
        
        
        if we get the number of edges for each node 
        get the top two/three nodes with the top number of edges
        if they share a road, add both number of edges and take one out because they share a road
        
        
        
        """
        
    
        # roads = [[0,1],[0,3],[1,2],[1,3]]
        edges = [0 for i in range(n)]
        for a, b in roads:
            edges[a] +=1
            edges[b] +=1
        
        
        res = 0
        for i in range(n):
            for j in range(i+1, n):
                sumn = edges[i] + edges[j]
                if [i, j] in roads or [j, i] in roads:
                    sumn -=1
                res = max(res, sumn)
        return res
        