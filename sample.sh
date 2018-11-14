!/bin/bash

#PBS -l nodes=1:ppn=4,mem=32gb,walltime=00:10:00
#PBS -M da.garzon1@uniandes.edu.co
#PBS -m abe
#PBS -N ejercicio27


module load anaconda/python3
cd $PBS_O_WORKDIR 
mpic++ sample.c -o sample
mpiexec -np 4 ./sample 2000 5 1
python sample.py