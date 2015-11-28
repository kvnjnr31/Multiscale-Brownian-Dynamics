#include "common.h"
#include "Sphere.h"

using namespace std;

extern vector<Sphere> particle;
void int_algorithm()
{
}

void step()
{
    integrate()
}
void make_forces()
{
    for(unsigned int i=0; i<particle.size()-1;i++){
        for(unsigned int k=i+1;k<particle.size();k++){
            if((particle[i].ptype()==0 || (particle[k].ptype()==0)){
               force(particle[i], particle[k],lx,ly);
            }
        }
    }
}
