'''
Created on 3/05/2014

@author: milderhc
'''
import sys

def make_link(G, node1, node2):
    if node1 not in G:
        G[node1] = {}
    if node2 not in G:
        G[node2] = {}
    G[node1][node2] = 1
    G[node2][node1] = 1

def kick(G):
    to_kick = []
    
    def dfs(G, node, marked):
        marked[node] = 1
        stack = [node]
        while stack <> []:
            current = stack.pop()
            if current not in G:
                continue
            if len(G[current].keys()) == 1:
                to_kick.append(current)
            for neighbor in G[current]:
                if neighbor not in marked:
                    marked[neighbor] = 1
                    stack.append(neighbor)
    
    marked = {}
    for node in G:
        if node not in marked:
            dfs(G, node, marked)
            
    for node in to_kick:
        for neighbor in G[node]:
            del G[neighbor][node]
        del G[node]
            
    return len( to_kick )

input = sys.stdin.readline().strip().split()
n = int( input[0] )
m = int( input[1] )
G = {}
while m > 0:
    input = sys.stdin.readline().strip().split()
    a = int( input[0] )
    b = int( input[1] )
    make_link(G, a, b)
    m -= 1

count = 0
while kick(G) > 0:
    count += 1
    
print count