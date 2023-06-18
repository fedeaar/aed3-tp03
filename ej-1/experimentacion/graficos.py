import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

#
# GLOBAL
#

plt.rcParams["font.family"] = "serif"
plt.rcParams["font.serif"] = ["Times New Roman"]
config = {"fontsize":20, "labelpad":20}

FN_HEAP = "./out/runtime_djikstra_fast.csv"
FN_QUEUE = "./out/runtime_djikstra_queue.csv"
FN_INGENUO = "./out/runtime_djikstra_slow.csv"
FN_HEAP_RALO = "./out/runtime_djikstra_fast_ralo.csv"
FN_QUEUE_RALO = "./out/runtime_djikstra_queue_ralo.csv"
FN_INGENUO_RALO = "./out/runtime_djikstra_slow_ralo.csv"
FN_HEAP_RALO_SMALL = "./out/runtime_djikstra_fast_ralo_small.csv"
FN_QUEUE_RALO_SMALL = "./out/runtime_djikstra_queue_ralo_small.csv"
#
# DSU original
#

def comparacion_triple():

    heap = pd.read_csv(FN_HEAP)
    queue = pd.read_csv(FN_QUEUE)
    ingenuo = pd.read_csv(FN_INGENUO)

    f, ax = plt.subplots(figsize=(10, 10))
    ax.scatter(heap["m"], heap["time"], color='orange')
    ax.plot(heap["m"], heap["time"], color='orange', label='heap')
    ax.scatter(queue["m"], queue["time"])
    ax.plot(queue["m"], queue["time"], color='red', label='queue')
    ax.scatter(ingenuo["m"], ingenuo["time"])
    ax.plot(ingenuo["m"], ingenuo["time"], label='ingenuo')

    ax.set_xscale("linear")
    ax.set_yscale("linear")
    ax.set_xlabel("tamaño de la entrada", **config)
    ax.set_ylabel("tiempo (segundos)", **config)
    ax.tick_params(labelsize=16, size=10)
    ax.grid()
    ax.legend(fontsize="xx-large")

    f.savefig("./out/comparacion_triple.png", bbox_inches='tight')

    # r = np.corrcoef(df['time'], df['n'])[0][1]
    # print("El coeficiente de correlación de Pearson para la muestra optimizada es: r="+str(r))

def comparacion_rala():

    heap = pd.read_csv(FN_HEAP_RALO)
    queue = pd.read_csv(FN_QUEUE_RALO)
    ingenuo = pd.read_csv(FN_INGENUO_RALO)

    f, ax = plt.subplots(figsize=(10, 10))
    ax.scatter(heap["n"], heap["time"], color='orange')
    ax.plot(heap["n"], heap["time"], color='orange', label='heap ralo')
    ax.scatter(queue["n"], queue["time"])
    ax.plot(queue["n"], queue["time"], color='red', label='queue ralo')
    ax.scatter(ingenuo["n"], ingenuo["time"])
    ax.plot(ingenuo["n"], ingenuo["time"], label='ingenuo ralo')

    ax.set_xscale("linear")
    ax.set_yscale("linear")
    ax.set_xlabel("tamaño de la entrada", **config)
    ax.set_ylabel("tiempo (segundos)", **config)
    ax.tick_params(labelsize=16, size=10)
    ax.grid()
    ax.legend(fontsize="xx-large")

    f.savefig("./out/comparacion_rala.png", bbox_inches='tight')

    # r = np.corrcoef(df['time'], df['n'])[0][1]
    # print("El coeficiente de correlación de Pearson para la muestra optimizada es: r="+str(r))


def comparacion_doble():

    heap = pd.read_csv(FN_HEAP_RALO)
    queue = pd.read_csv(FN_QUEUE_RALO)

    f, ax = plt.subplots(figsize=(10, 10))
    ax.scatter(heap["n"], heap["time"], color='orange')
    ax.plot(heap["n"], heap["time"], color='orange', label='heap ralo')
    ax.scatter(queue["n"], queue["time"])
    ax.plot(queue["n"], queue["time"], color='red', label='queue ralo')
    
    
    ax.set_xscale("linear")
    ax.set_yscale("linear")
    ax.set_xlabel("tamaño de la entrada", **config)
    ax.set_ylabel("tiempo (segundos)", **config)
    ax.tick_params(labelsize=16, size=10)
    ax.grid()
    ax.legend(fontsize="xx-large")

    f.savefig("./out/comparacion_rala_doble.png", bbox_inches='tight')

    # r = np.corrcoef(df['time'], df['n'])[0][1]
    # print("El coeficiente de correlación de Pearson para la muestra optimizada es: r="+str(r))

def comparacion_small():

    heap = pd.read_csv(FN_HEAP_RALO_SMALL)
    queue = pd.read_csv(FN_QUEUE_RALO_SMALL)
    ingenuo = pd.read_csv(FN_INGENUO_RALO)

    f, ax = plt.subplots(figsize=(10, 10))
    ax.scatter(heap["n"], heap["time"], color='orange')
    ax.plot(heap["n"], heap["time"], color='orange', label='heap ralo')
    ax.scatter(queue["n"], queue["time"])
    ax.plot(queue["n"], queue["time"], color='red', label='queue ralo small')
    ax.scatter(ingenuo["n"], ingenuo["time"])
    ax.plot(ingenuo["n"], ingenuo["time"], label='ingenuo ralo small')

    ax.set_xscale("linear")
    ax.set_yscale("log")
    ax.set_xlabel("tamaño de la entrada", **config)
    ax.set_ylabel("log(tiempo (segundos))", **config)
    ax.tick_params(labelsize=16, size=10)
    ax.grid()
    ax.legend(fontsize="xx-large")

    f.savefig("./out/comparacion_rala_small.png", bbox_inches='tight')

    # r = np.corrcoef(df['time'], df['n'])[0][1]
    # print("El coeficiente de correlación de Pearson para la muestra optimizada es: r="+str(r))


#
# MAIN
#

if __name__ == "__main__":

    comparacion_triple()
    comparacion_rala()
    comparacion_doble()
    comparacion_small()