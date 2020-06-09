// [[Rcpp::depends(RcppEigen)]]
#include <RcppEigen.h>

#ifdef _OPENMP
#include <omp.h>
//   [[Rcpp::plugins(openmp)]]
#endif






// [[Rcpp::export]]
Eigen::MatrixXd  ReadBlock(std::string tmpfname,
                           long start_row,
                           long numcols,
                           long numrows_in_block)

{
 // reads in data from ASCII file 
 // to form M Eign double matrix 
std::ostringstream
      os;
std::string
   line;


long
  // coli = 0, 
  rowi = 0;


Eigen::MatrixXd
      M(numrows_in_block, numcols) ;


// Open no-space ASCII file
   std::ifstream fileIN(tmpfname.c_str(), std::ios::in );

    if(!fileIN.good()) {
      os << "ERROR: Could not open  " << tmpfname << std::endl;
      Rcpp::stop(os.str() );
     }
   Rcpp::Rcout << " This should be paralleized .... -- REadblock " << std::endl;
   for(long rr=0; rr < (start_row + numrows_in_block) ; rr++){
      // read a line of data from ASCII file
      getline(fileIN, line);
      if(rr >= start_row){
          std::istringstream streamA(line);
          {
#if defined(_OPENMP)
     #pragma omp for 
#endif
          for(long ii=0; ii < numcols  ; ii++){
            int tmp  = line[ii] - '0'; // trick to removes ASCII character offset for numbers
            M(rowi, ii) = (double) tmp - 1;   // converting data to -1, 0, 1 
          }
          } // end pragma omp parallel
          rowi++;
      } // end if rr
   } // end for(rr



// Close the input  file
   fileIN.close();


 return M;

}


