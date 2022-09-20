#include <complex>
#define lapack_complex_float std::complex<float>
#define lapack_complex_double std::complex<double>
#include <lapacke.h>

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<double> a = {68.8915, -52.4488, 0, -79.4537, 88.7629, 0, 58.6154, -35.4198, 0};
    vector<double> s(3);
    vector<double> u(9);
    vector<double> vh(9);

    for(int ix=0; ix<9; ++ix) {
        u[ix]=0;
        vh[ix]=0;
        if (ix<3) {
            s[ix]=0;
        }
    }

    std::cout << "i'm here" << std::endl;

    lapack_int result;
    try {
        result = LAPACKE_dgesdd(LAPACK_ROW_MAJOR, 'A', //'A', // if using LAPACKE_dgesvd
                                           static_cast<lapack_int>(3),
                                           static_cast<lapack_int>(3),
                                           a.data(),
                                           static_cast<lapack_int>(3),
                                           s.data(),
                                           u.data(),
                                           static_cast<lapack_int>(3),
                                           vh.data(),
                                           static_cast<lapack_int>(3));
    }
    catch (const std::exception& e) {
        std::cout << "exception: " << e.what() << std::endl;
    }

    std::cout << s[0] << std::endl;
    std::cout << s[1] << std::endl;
    std::cout << s[2] << std::endl;

    return 0;
}
