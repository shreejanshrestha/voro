// Single Voronoi cell example code
//
// Author   : Chris H. Rycroft (LBL / UC Berkeley)
// Email    : chr@alum.mit.edu
// Date     : October 19th 2007

#include "cell.cc"

const double pi=3.1415926535897932384626433832795;
const int n=32;
const double theta=pi/4-0.25;
const double step=2*pi/n;

int main() {
	double x,y,z,rsq,r,phi;
	voronoicell v;

	// Initialize the Voronoi cell to be a cube of side length 2, centered on
	// the origin
	v.init(-1,1,-1,1,-1,1);

	// Output the initial cell	
	ofstream file;
	file.open("intest",ofstream::out|ofstream::trunc);
	v.dumpgnuplot(file,0.0,0.0,0.0);
	file.close();
	
	// Plane cutting
	for(phi=0;phi<2*pi-0.5*step;phi+=step) {
		x=cos(theta);y=cos(phi)*sin(theta);z=sin(phi)*sin(theta);
		v.plane(x,y,z,1);
		v.plane(-x,y,z,1);
		v.plane(y,x,z,1);
		v.plane(y,-x,z,1);
		v.plane(y,z,x,1);
		v.plane(y,z,-x,1);
		v.relcheck();
	}

	// Output the Voronoi cell to a file, in the gnuplot format
	file.open("test",ofstream::out|ofstream::trunc);
	v.dumpgnuplot(file,0.0,0.0,0.0);
	file.close();
}
