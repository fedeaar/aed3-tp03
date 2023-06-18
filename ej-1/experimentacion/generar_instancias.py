import numpy as np
import os


#
# VARIABLES
#

SEED = 11037
MIN = 15000
MAX = 112492500
STEP = 11247750


#
# MAIN
#

if __name__ == "__main__":

    np.random.seed(SEED)
    rng = np.random.default_rng()

    
    if not os.path.exists("./inputs/"):
        os.mkdir("./inputs/")

    n = 15000
    for m in range(MIN, MAX+1, STEP):
        a = rng.choice(n, size=m)
        b = rng.choice(n, size=m)
        dist = rng.choice(1000, size=m)
        f = open("./inputs/input_" + str(m), "w")
        f.write(str(n) + " " + str(m) + " " + "0 " +  "1 " + "2 ")
        for i in range(0, m):
            f.write(str(a[i]+1) + " " + str(b[i]+1) + " " + str(dist[i]+1) + " ")
        f.close()
