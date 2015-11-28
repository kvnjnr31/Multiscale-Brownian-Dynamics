#include <fstream.h>
#include <stdlib.h>

void dump_particle(ostream & os,
                   double x, double y, double vx, double vy,
                   double radius, double mass, int type)
{ os << x << "\t" << y << "\t0\t" << vx << "\t" << vy << "\t0\t"
   << radius << "\t" << mass << "\t"
   << type << "\t0\t0\t0\t0\t0\t0\t0\t0\t0\n";
}

int main()
{
    ofstream fout("closed_hopper.random");
    fout << "#gravity: 0 -9.81 0\n";
    fout << "#timestep: 1e-6\n";
    fout << "#nstep: 5000000\n";
    fout << "#nprint: 1000\n";
    fout << "#nenergy: 1000\n";
    fout << "#Time: 0\n";
    for(int i=0; i<11;i++)
        dump_particle(fout,0.45+i*0.01,0.19,0,0,0.005,1,1);

    for(int i=0;i<50;i++){
        dump_particle(fout,0.55+(i+0.5)*0.005,i*0.01+0.2,0,0,0.005,1,1);
        dump_particle(fout,0.45+(i+0.5)*0.005,i*0.01+0.2,0,0,0.005,1,1);
    }
    const double Rmax=0.006, Rmin=0.004;

    for(int i=0;i<67;i++){
        for(int k=0;k<30;k++){
           double centerx=0.3115+0.013*i;
           double centery=0.6+0.013*k;
           double z=drand48();
           double r=Rmin*Rmax/(Rmax-z*(Rmax-Rmin));
           dump_particle(fout,centerx,centery,0,0,r,r*r/(Rmax*Rmax),0);
          }
    }
}
