#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mpi.h"
#include <fstream>
#include <sstream>

using namespace std;
double gsf(double x, double mu, double s);

int main(int argc,char ** argv)
{
    MPI_Init(&argc, &rgv)
    int rank, size;
    MPI_Comm_rank (MPI_COMM_WORLD, &rank);
    MPI_Comm_size (MPI_COMM_WORLD, &size);
	srand(time(NULL));
	int N = atof(argv[1]);
    int n = N/size;
	double mu = atof(argv[2]);
	double s = atof(argv[3]);
	double * gs = new double[n];
	int mn = mu - 4*s;
	int mx = mu + 4*s;
	gs[0]=0.1;

	for(int i=1;i<n;i++)
	{
		
		double t = double(rand()) / double(RAND_MAX) ;
		t = ( mx-mn ) * t + mn;
		double alfa = double( rand() ) / double(RAND_MAX);
		double gs_i = gs[i-1] +  t;
		double r = gsf(gs_i,mu,s) / gsf(gs[i-1],mu,s);
		if (alfa < r)
		{
			gs[i]=gs_i;
		}
		else
		{
			gs[i]=gs[i-1];
		}
		cout<<gs[i]<<endl;
	}
    char buffer [50];
    ofstream f_w;
    stringstream ss;
    sprintf(buffer,"%d",rank+1);
    ss << buffer;
    string s;
    ss >> s;
    string fil = "sample_" + s + ".dat";
    fw.open(fil.c_str());
    for(int i=0;i<n;i++)
    {
        f_w << gs[i] << endl ;
    }
        f_w.close();

    MPI_Finalize();

return 0;
}
double gsf(double x, double mu, double s)
{
	double pi = acos(-1);
	return 1.0/( s * sqrt(2 * pi) ) * exp( - ( x - mu ) * ( x - mu) / ( 2.0 * s * s ) );
	
}
