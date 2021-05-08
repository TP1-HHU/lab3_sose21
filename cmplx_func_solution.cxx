// Complex functions
#include <iostream>
#include <fstream>
#include <complex>

using namespace std;

// Prototype
complex<double> f(double phi);

int main()
{
    const int N = 100;
    complex<double> z[N];
    const double dphi = 2*M_PI/(N-1);
    ofstream out("output");

    for(int i=0; i<N; i++)
	   z[i] = f(dphi*i-M_PI);

    for(int i=0; i<N; i++)
      out << i*dphi-M_PI << "\t" << real(z[i]) << "\t"
          << imag(z[i]) << "\t"  << abs(z[i]) << endl;

    out.close();

    return 0;
}


complex<double> f(double phi)
{
   return( tan(phi * complex<double>(1,1)) );
}
