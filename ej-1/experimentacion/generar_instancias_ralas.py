import numpy as np
import os


#
# VARIABLES
#

SEED = 11037
MIN = 10000
MAX = 100000
STEP = 10000


#
# MAIN
#

if __name__ == "__main__":

    np.random.seed(SEED)
    rng = np.random.default_rng()

    
    if not os.path.exists("./inputs/"):
        os.mkdir("./inputs/")

    for n in range(MIN, MAX+1, STEP):
        m = 2*n
        a = rng.choice(n, size=m)
        b = rng.choice(n, size=m)
        dist = rng.choice(1000, size=m)
        f = open("./inputs/input_" + str(n), "w")
        f.write(str(n) + " " + str(m) + " " + "0 " +  "1 " + "2 ")
        for i in range(0, 15000):
            f.write(str(a[i]+1) + " " + str(b[i]+1) + " " + str(dist[i]+1) + " ")
        f.close()
