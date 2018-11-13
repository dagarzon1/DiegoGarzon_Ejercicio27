!/bin/bash

#PBS -l nodes=1:ppn=1,mem=1gb,walltime=00:10:00
#PBS -M da.garzon1@uniandes.edu.co
#PBS -m abe
#PBS -N ejercicio27


module load anaconda/python3
cd $PBS_O_WORKDIR # este es el directorio desde donde se ejecuto qsub
make

mpirun -np 4 ./list1.x
mpirun -np 2 ./list2.x