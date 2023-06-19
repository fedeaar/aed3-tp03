import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker

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
# AUX
#

def expformat(x, pos):

        if x == 0: return "$0$"

        exponent = int(np.log10(x))
        coeff = x/10**exponent

        return r"${:2.0f} \times 10^{{ {:2d} }}$".format(coeff,exponent)


def comparacion_triple():

    heap = pd.read_csv(FN_HEAP)
    queue = pd.read_csv(FN_QUEUE)
    ingenuo = pd.read_csv(FN_INGENUO)
    
    size = heap["m"] / 112492500

    f, ax = plt.subplots(figsize=(5, 5))
    ax.scatter(size, heap["time"], color='orange')
    ax.plot(size, heap["time"], color='orange', label='heap')
    ax.scatter(size, queue["time"])
    ax.plot(size, queue["time"], color='red', label='queue')
    ax.scatter(size, ingenuo["time"])
    ax.plot(size, ingenuo["time"], label='ingenuo')

    ax.set_xscale("linear")
    ax.set_yscale("linear")
    ax.set_xlabel("densidad (cantidad de aristas)", **config)
    ax.set_ylabel("tiempo (segundos)", **config)
    ax.tick_params(labelsize=16, size=10)

    ax.text(-0.05, -0.1, r'$1.5 \times 10^4$', transform=ax.get_xaxis_transform(),
            ha='left', va='top', fontsize=12, fontfamily='serif')
    
    ax.text(1.05, -0.1, r'$\approx 1.1 \times 10^8$', transform=ax.get_xaxis_transform(),
            ha='right', va='top', fontsize=12, fontfamily='serif')

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

    f, ax = plt.subplots(figsize=(5, 5))
    ax.scatter(heap["n"], heap["time"], color='orange')
    ax.plot(heap["n"], heap["time"], color='orange', label='heap')
    ax.scatter(queue["n"], queue["time"])
    ax.plot(queue["n"], queue["time"], color='red', label='queue')
    
    
    ax.set_xscale("linear")
    ax.set_yscale("linear")
    ax.set_xlabel("tamaño de la entrada (vértices)", **config)
    ax.set_ylabel("tiempo (segundos)", **config)
    ax.tick_params(labelsize=16, size=10)
    ax.grid()
    ax.legend(fontsize="xx-large")
    #ax.xaxis.set_major_formatter(ticker.FuncFormatter(expformat))
    #ax.tick_params(axis='x', labelsize=14)
    
    f.savefig("./out/comparacion_rala_doble.png", bbox_inches='tight')

    # r = np.corrcoef(df['time'], df['n'])[0][1]
    # print("El coeficiente de correlación de Pearson para la muestra optimizada es: r="+str(r))

def comparacion_small():

    heap = pd.read_csv(FN_HEAP_RALO_SMALL)
    queue = pd.read_csv(FN_QUEUE_RALO_SMALL)
    ingenuo = pd.read_csv(FN_INGENUO_RALO)

    f, ax = plt.subplots(figsize=(5, 5))
    ax.scatter(heap["n"], heap["time"], color='orange')
    ax.plot(heap["n"], heap["time"], color='orange', label='heap')
    ax.scatter(queue["n"], queue["time"])
    ax.plot(queue["n"], queue["time"], color='red', label='queue')
    ax.scatter(ingenuo["n"], ingenuo["time"])
    ax.plot(ingenuo["n"], ingenuo["time"], label='ingenuo')

    ax.set_xscale("linear")
    ax.set_yscale("log")
    ax.set_xlabel("tamaño de la entrada (vértices)", **config)
    ax.set_ylabel("tiempo (segundos)", **config)
    ax.tick_params(labelsize=16, size=10)
    ax.grid()
    ax.legend(fontsize="xx-large", loc=(0.5, 0.55))
    #ax.xaxis.set_major_formatter(ticker.FuncFormatter(expformat))
    #ax.tick_params(axis='x', labelsize=14)

    f.savefig("./out/comparacion_rala_small.png", bbox_inches='tight')

    # r = np.corrcoef(df['time'], df['n'])[0][1]
    # print("El coeficiente de correlación de Pearson para la muestra optimizada es: r="+str(r))


#
# MAIN
#

if __name__ == "__main__":

    comparacion_triple()
    #comparacion_rala()
    comparacion_doble()
    comparacion_small()