#include <iostream>
#include <complex>

using namespace std;

int main(){

    double tol = 1e-10;
    int Nmax = 400;
    int Nx = 2000;
    complex<double> z, dz;


    // z_{n+1} = z_n - f(z_n) / f'(z_n)
    // f(z) = z^3 - 1
    int i = 0;

    double rmin = -2;
    double rmax = 2;
    double imin = rmin;
    double imax = rmax;

    double dx = (rmax-rmin)/(Nx-1);
    
    for(double re = rmin; re<rmax; re += dx)
      for(double im = imin; im <imax; im +=dx)
      {
          complex<double> z0 = complex<double>(re,im);
          z = z0;
          i = 0;
          do {
            dz = (z*z*z + 2.0*(z-1.0) - 1.0 )/(3.0*z*z + 2.0);
            z -= dz;
            i++;
          } while (( i < Nmax) && (abs(dz) > tol));
          cout << real(z0) << "\t" << imag(z0) << "\t" << i << endl;
      }
       
    return 0;
}