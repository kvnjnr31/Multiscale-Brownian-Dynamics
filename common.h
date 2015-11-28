#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include <math.h>
#include <fstream>
#include <vector>
#include <set>
#include <string>

using namespace std;

extern double lx, ly;
extern double x_0, y_0;

extern unsigned int no_of_particles;
extern double Time;
extern ofstream fphase;
extern ofstream fenergy;

void step();
void make_forces();
void integrate();
void init_algorithm();
void phase_plot(ostream & os);
#endif // COMMON_H_INCLUDED
