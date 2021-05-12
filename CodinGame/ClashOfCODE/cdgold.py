import sys
import math
from collections import deque



# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

number_of_cells = int(input())  # 37
cells = [list(map(int, input().split())) for _ in range(number_of_cells)]
# for i in range(number_of_cells):
#     # index: 0 is the center cell, the next cells spiral outwards
#     # richness: 0 if the cell is unusable, 1-3 for usable cells
#     # neigh_0: the index of the neighbouring cell for each direction
#     index, richness, neigh_0, neigh_1, neigh_2, neigh_3, neigh_4, neigh_5 = [int(j) for j in input().split()]

def search_seedable(t):
    st = t[0]
    dist = [float('inf')] * number_of_cells
    dist[st] = 0
    q = deque()
    q.append(st)
    while(len(q) != 0):
        v = q.popleft()

        for nv in cells[v][2: ]:
            if nv == -1: continue
            if dist[nv] != float('inf'): continue

            dist[nv] = dist[v] + 1
            q.append(nv)
    # print(dist, file=sys.stderr, flush=True)
    ret = []
    for i in range(number_of_cells):
        if dist[i] == t[1]:
            ret.append(i)
        
    return ret

# game loop
while True:
    day = int(input())  # the game lasts 24 days: 0-23
    nutrients = int(input())  # the base score you gain from the next COMPLETE action
    # sun: your sun points
    # score: your current score
    sun, score = [int(i) for i in input().split()]
    inputs = input().split()
    opp_sun = int(inputs[0])  # opponent's sun points
    opp_score = int(inputs[1])  # opponent's score
    opp_is_waiting = inputs[2] != "0"  # whether your opponent is asleep until the next day
    number_of_trees = int(input())  # the current amount of trees

    trees = [list(map(int, input().split())) for _ in range(number_of_trees)]
    # for i in range(number_of_trees):
    #     inputs = input().split()
    #     cell_index = int(inputs[0])  # location of this tree
    #     size = int(inputs[1])  # size of this tree: 0-3
    #     is_mine = inputs[2] != "0"  # 1 if this is your tree
    #     is_dormant = inputs[3] != "0"  # 1 if this tree is dormant
    number_of_possible_actions = int(input())  # all legal actions
    possible_actions = [input().split() for _ in range(number_of_possible_actions)]
    # for i in range(number_of_possible_actions):
    #     possible_action = input()  # try printing something from here to start with

    # Write an action using print
    # To debug: print("Debug messages...", file=sys.stderr, flush=True)

    # First WAIT
    if day == 0:
        print("WAIT")
        continue

    tree_exsists = [False] * number_of_cells
    for tree in trees:
        tree_exsists[tree[0]] = True


    action = "WAIT"

    cnt = [0] * 4
    mytree = 0
    for tree in trees:
        if tree[2] == 0: continue
        # if tree[3] == 1: continue
        cnt[tree[1]] += 1
        mytree += 1
    
    # case1: few trees -> firstly seed
    if mytree < 7:
        # case1-1: few origin trees -> firstly gro
        if cnt[2] == 0 and cnt[3] == 0:
            candidate = []
            for tree in trees:
                if tree[2] == 0: continue
                if tree[3] == 1: continue
                
                candidate.append([1-tree[1], tree[0]])
            candidate.sort()

            if(len(candidate) != 0):
                action = "GROW " + str(candidate[0][1])
        
        # case1-2: seed
        # from the tree its size of 2 or 3, to the cell "no tree", "more richness", "less neighbors"
        else:
            for tree in trees:
                if tree[2] == 0: continue
                if tree[3] == 1: continue

                seedable = search_seedable(tree)

                candidate = []

                for to in seedable:
                    if tree_exsists[to]: continue
                
                    cnt_neighbor = 0
                    for nei in cells[to][2: ]:
                        if tree_exsists[nei]: cnt_neighbor += 1
                    
                    candidate.append([-cells[to][1], cnt_neighbor, to])
                
                candidate.sort()

                if len(candidate) != 0:
                    action = "SEED " + str(tree[0]) + " " + str(candidate[0][2])
                    break
    
    # enough trees, just grow or complete!!
    else:
        # more than 3 biggest trees or last of game, complete biggest tree
        if cnt[3] > 3 or day > 20:
            target = -1
            for tree in trees:
                if tree[2] == 0: continue
                if tree[3] == 1: continue

                if tree[1] == 3:
                    target = tree[0]
                    break
            if target != -1:
                action = "COMPLETE " + str(target)
        
        # prefer smaller trees
        else:
            candidate = []
            for tree in trees:
                if tree[2] == 0: continue
                if tree[3] == 1: continue

                candidate.append([tree[1], tree[0]])
            
            reverse = False
            candidate.sort(reverse=reverse)

            if len(candidate) > 0:
                action = "GROW " + str(candidate[0][1])
                


    # GROW cellIdx | SEED sourceIdx targetIdx | COMPLETE cellIdx | WAIT <message>
    print(action)
