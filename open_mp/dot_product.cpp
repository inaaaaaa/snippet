#include <iostream>
#include <libiomp/omp.h>

/**
 * MacOSX10.11
 * Compile
 * $ clang-omp++ -fopenmp -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.11.sdk/usr/include <this_file>
 * Run
 * $ export OMP_NUM_THREADS=2; ./a.out
 */

int main() {

  std::cout << "==== start ====" << std::endl;

  int _size = 1000;
  int a[_size], b[_size];
  for(int i = 0; i < _size; i++) {
    a[i] = b[i] = i;
  }

  #ifdef _OPENMP
  std::cout << "  omp_get_num_procs() : " << omp_get_num_procs() << std::endl;
  std::cout << "omp_get_max_threads() : " << omp_get_max_threads() << std::endl;
  #endif

  int ddot = 0;
  #ifdef _OPENMP
  #pragma omp parallel for reduction(+ : ddot) // For reduce
  #endif
  for(int i = 0; i < _size; i++) {
    ddot += a[i] * b[i];
  }

  int ddot_error = 0;
  #ifdef _OPENMP
  #pragma omp parallel for
  #endif
  for(int i = 0; i < _size; i++) {
    ddot_error += a[i] * b[i];
  }

  std::cout << "ddot is " << ddot << std::endl;
  std::cout << "ddot_error is " << ddot_error << std::endl;
  std::cout << "==== end ====" << std::endl;
}
