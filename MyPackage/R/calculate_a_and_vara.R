calculate_a_and_vara <- function(geno=NULL, maxmemGb=8,
                         selectedloci = NA,
                         invMMtsqrt=NULL, transformed_a=NULL, transformed_vara=NULL,
                         quiet = TRUE, message=message)
{
 ## internal function to AM
 ## an Rcpp function to take dimension reduced a (BLUP) values 
 ## and transform them into the original a (BLUP) values and their variances 
 ## Args:
 ##   maxmemGb         maximum available memory (in Gigabytes) that are available for use
 ##   dims             a 2 element numeric vector with the number of rows,columns in M 
 ##   invMMtsqrt       a matrix object of the form (M %*% M^T)^{-0.5}
 ##   transformed_a    a numeric vector of the dimension reduced BLUP or a values
 ##   transformed_vara a numeric matrix of dimension dims(1) x dims(1) for the dimension reduced BLUPs (or a) values. 
 ##   selectedloci     an integer vector that gives the column number (0- L-1 ) of the loci that
 ##                    have been selected to act as fixed QTL effects in the model. 



  fnameMt <- geno[["asciifileMt"]]
  dimsMt <- c(geno[["dim_of_ascii_M"]][2], geno[["dim_of_ascii_M"]][1])

  if(!any(is.na(selectedloci))) selectedloci <- selectedloci-1

  calculate_a_and_vara_rcpp(f_name_ascii=fnameMt,
                    selected_loci = selectedloci,
                    inv_MMt_sqrt=invMMtsqrt,
                    dim_reduced_vara = transformed_vara,
                    max_memory_in_Gbytes=maxmemGb,
                    dims=dimsMt,
                    a = transformed_a,
                    quiet = quiet, message=message)


}


