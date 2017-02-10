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

  #ifdef _OPENMP
  std::cout << "  omp_get_num_procs() : " << omp_get_num_procs() << std::endl;
  std::cout << "omp_get_max_threads() : " << omp_get_max_threads() << std::endl;
  #endif

  #ifdef _OPENMP
  #pragma omp parallel for
  #endif
  for(int i = 0; i < 100; i++) {
    std::cout << "omp_get_thread_num() : " << omp_get_thread_num() << std::endl;
  }

  std::cout << "==== end ====" << std::endl;
}
