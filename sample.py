import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
import glob

k = sorted(glob.glob("*.dat"))
dat = []

for i in k:
    d = np.loadtxt(i)
    dat.append(d)
_ = plt.hist(dat)
plt.savefig("sample.pdf")
