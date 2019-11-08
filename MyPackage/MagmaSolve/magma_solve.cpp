// This is a simple standalone example. See README.txt

#include<iostream>
#include "cublas_v2.h"
#include <stdio.h>
#include <stdlib.h>
#include "magma_v2.h"      // also includes cublas_v2.h
#include "magma_lapack.h"  // if you need BLAS & LAPACK
#include<magma_operators.h>
#include <cstdlib>
#include<fstream>



// set to 1 if debug information is desired
#define DEBUG 1



/***************************************************************************//**
 * Macros 
 */

#define PRINT(x)  \
     std::cout << x << std::endl

#define CHECK_MALLOC( err )                                                                        \
    if (err != MAGMA_SUCCESS){                                                                     \
        std::cout << "\nError: Eigenvalue calculation has failed due to failure of memory allocation.\n" << std::endl;  \
     }

#define CHECK_GPU( err )   \
   if (err != MAGMA_SUCCESS ){                         \
       std::cout <<"\n" << std::endl;    \
       std::cout << "\nError:    " << std::endl;    \
       std::cout << "  Eigenvalue calculation has failed. " << std::endl;  \
       std::cout << "  Things to try to solve this problem are:            " << std::endl;  \
       std::cout << "    1. Reduce the number of individuals to see if this is a GPU memory issue. " << std::endl; \
       std::cout << "    2. Ensure that you do not have perfectly correlated fixed effects in the model. " << std::endl; \
       std::cout << "       This will cause collinearity between columns in the model matrix. \n\n " << std::endl;     \
   }



/*
 Command line parameters
--------------------------
std::string  X  
long  numrows, 
int numgpus, 
bool printInfo, 
std::string fnamevec,  
*/



int main( int argc, char** argv )
{

 // Input received from command line
 std::string X = argv[1];  // name of binary file with data
 int numrows = atoi(argv[2]); // number of rows 
 int numgpus = atoi(argv[3]); // number of gpu 

 bool printInfo = (bool) atoi(argv[4]); // printInfo value (0 no print, 1 print)
 std::string fnamevec = argv[5];  // name of binary file containing eigenvector answers 



 // Initialize Magma and print GPU environment
 magma_init (); 

 if (printInfo)
       magma_print_environment();











  magma_int_t n, n2, lwork, info = 0;  // define MAGMA_ILP64 to get these as 64 bit integers
   n = numrows ;   // this is X.rows() but passed in from command line
   n2     = n*n;


  double * h_vectors;
  if (  MAGMA_SUCCESS !=   magma_dmalloc_cpu(&h_vectors, n2) )
  {
    std::cout << " Error: magma_eigen() magma_dmalloc_cpu failed for h_vectors. Need more memory" << std::endl;
    return -1;
  }

  // X matrix being passed in as a binary file
  std::streampos size;
  char * memblock;

  std::ifstream bfile ( X.c_str() , std::ios::in|std::ios::binary|std::ios::ate);


//size = bfile.tellg();
//    std::cout << "size=" << size << "\n";


  if(printInfo){
     std::cout << "About to begin reading in the X matrix data ... " << std::endl;
  }

  size = n * n * sizeof(double);
  memblock = new char [size];
  bfile.seekg (0, std::ios::beg);
  bfile.read (memblock, size);
  bfile.close();

  h_vectors =  (double*)memblock;  //reinterpret as doubles

  if(printInfo){
     std::cout << "Reading of X  matrix data complete.  " << std::endl;
  }

  if (printInfo){
     std::cout << " First 5 rows and columns of the  X matrix " << std::endl;
     magma_dprint(5,5, h_vectors, n);
  }


   magma_dpotrf( MagmaLower, n, h_vectors, n, &info );
    std::cout << "after  magma_dpotrf" << std::endl;
     magma_dprint(5,5, h_vectors, n);
   magma_dpotri( MagmaLower, n, h_vectors, n, &info );
    std::cout << "after  magma_dpotri" << std::endl;
     magma_dprint(5,5, h_vectors, n);




   if( printInfo){
       std::cout << " About to write inverse to binary file. " << std::endl;
    }



    if (fnamevec.empty()){
      std::cout << " Error: in magma_eigen. Name of binary file for the eigenvectors has not been specified. \n" << std::endl;
      return -1;
    }

    FILE* file = fopen(fnamevec.c_str() , "wb");
    if (file == NULL){
       std::cout << " Error: in magma_eigen. Binary file for eigenvectors has failed to open." << std::endl;
       return -1;
    } else {
       fwrite(&h_vectors[0], 1 , n*n*sizeof(double) , file);
       fclose(file);
    }
 

  // tidying up 
  magma_free_cpu (h_vectors)  ;

 magma_finalize();
  
 return 0;


}
                       
  


