#!/usr/bin/env python3

import random
def mk():
    v=0.4
    for k in range(0,20):
        print(5+random.randrange(0,2)*3+(random.random()-0.5)*v)
mk()
