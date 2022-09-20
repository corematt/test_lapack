#include <iostream>
#include <vector>
#include <mkl.h>

using namespace std;

int main()
{
	vector<double> a = {68.8915, -52.4488, 0, -79.4537, 88.7629, 0, 58.6154, -35.4198, 0};
	vector<double> s(3);
	vector<double> u(9);
	vector<double> vh(9);

	// Check version of MKL
	cout << "Checking MKL Version" << endl;
	MKLVersion Version;
	mkl_get_version(&Version);
	cout << "Major version:           " << Version.MajorVersion << endl;
	cout << "Minor version:           " << Version.MinorVersion << endl;
	cout << "Update version:          " << Version.UpdateVersion << endl;
	cout << "Product status:          " << Version.ProductStatus << endl;
	cout << "Build:                   " << Version.Build << endl;
	cout << "Platform:                " << Version.Platform << endl;
	cout << "Processor optimization:  " << Version.Processor << endl;
	cout << "================================================================" << endl;

	cout << endl << "Running SVD" << endl;
	lapack_int result = LAPACKE_dgesdd(LAPACK_ROW_MAJOR, 'A', //'A', // if using LAPACKE_dgesvd
									   static_cast<lapack_int>(3),
									   static_cast<lapack_int>(3),
									   a.data(),
									   static_cast<lapack_int>(3),
									   s.data(),
									   u.data(),
									   static_cast<lapack_int>(3),
									   vh.data(),
									   static_cast<lapack_int>(3));

	cout << "Success" << endl;

    std::cout << s[0] << std::endl;
    std::cout << s[1] << std::endl;
    std::cout << s[2] << std::endl;

	return 0;
}
