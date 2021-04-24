#!/bin/env python
# -*- coding: utf-8 -*-
#
# Chromatic.py

from random import *
from time import *
from graph import *
from pol import *
from chr_pol import *

graph_output = 1
# 髫｣謗･陦悟�繧貞�蜉帙☆繧� : 1 / 縺励↑縺� : 0

"""
g =CompleteGraph(5)
g = Cycle(7)
g = PetersenGraph()
g =CompleteBipartiteGraph(3,7)
"""

print u"繝ｩ繝ｳ繝繝�縺ｪ繧ｰ繝ｩ繝輔�蠖ｩ濶ｲ螟夐��ｼ上�蠖ｩ濶ｲ謨ｰ繧呈ｱゅａ縺ｾ縺吶�"
print u"繧ｰ繝ｩ繝輔�鬆らせ謨ｰ繧貞�蜉帙＠縺ｦ縺上□縺輔＞縲�"
n = input()
print u"霎ｺ謨ｰ繧貞�蜉帙＠縺ｦ縺上□縺輔＞縲�"
m = input()

print u"繧ｰ繝ｩ繝穂ｽ懈�荳ｭ ..."
t0 = time()
g = RandomGraphOfGivenSize(n, m)
t1 = time()

if graph_output:
	WriteGraph(g)
print u"繧ｰ繝ｩ繝穂ｽ懈�譎る俣 =", t1 - t0

t0 = time()
print u"險育ｮ嶺ｸｭ ..."
[k, f, remainfactor, linearfactors] = ChromaticInformation(g)
t1 = time()

print u"蠖ｩ濶ｲ謨ｰ =", k
print u"蠖ｩ濶ｲ螟夐��ｼ� =",
polwriteln(f)
print u"縲縲縲縲縲 =",
for i in range(0, len(linearfactors)):
    if i > 0:
        if linearfactors[i] > 1:
            print u" * (x - %d)^%d" % (i, linearfactors[i]),
        else:
            print u" * (x - %d)" % i,
    else:
        if linearfactors[0] > 1:
            print u"x^%d" % linearfactors[0],
        else:
            print u"x",
        
if poldeg(remainfactor) > 0: 
    print u" * (",
    polwrite(remainfactor),
    print u")",
print

print u"鬆らせ謨ｰ =", n
print u"霎ｺ謨ｰ   =", CountEdges(g)
print u"險育ｮ玲凾髢� =", t1 - t0




