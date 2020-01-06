// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppEigen.h>
#include <Rcpp.h>
using namespace Rcpp ; 

// ReadBlock
Eigen::MatrixXd ReadBlock(std::string asciifname, long start_row, long numcols, long numrows_in_block);
RcppExport SEXP _Eagle_ReadBlock(SEXP asciifnameSEXP, SEXP start_rowSEXP, SEXP numcolsSEXP, SEXP numrows_in_blockSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type asciifname(asciifnameSEXP);
    Rcpp::traits::input_parameter< long >::type start_row(start_rowSEXP);
    Rcpp::traits::input_parameter< long >::type numcols(numcolsSEXP);
    Rcpp::traits::input_parameter< long >::type numrows_in_block(numrows_in_blockSEXP);
    rcpp_result_gen = Rcpp::wrap(ReadBlock(asciifname, start_row, numcols, numrows_in_block));
    return rcpp_result_gen;
END_RCPP
}
// ReadBlockBin
Eigen::MatrixXd ReadBlockBin(std::string binfname, long start_row, long numcols, long numrows_in_block);
RcppExport SEXP _Eagle_ReadBlockBin(SEXP binfnameSEXP, SEXP start_rowSEXP, SEXP numcolsSEXP, SEXP numrows_in_blockSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type binfname(binfnameSEXP);
    Rcpp::traits::input_parameter< long >::type start_row(start_rowSEXP);
    Rcpp::traits::input_parameter< long >::type numcols(numcolsSEXP);
    Rcpp::traits::input_parameter< long >::type numrows_in_block(numrows_in_blockSEXP);
    rcpp_result_gen = Rcpp::wrap(ReadBlockBin(binfname, start_row, numcols, numrows_in_block));
    return rcpp_result_gen;
END_RCPP
}
// ReshapeM_rcpp
std::vector <long> ReshapeM_rcpp(Rcpp::CharacterVector fnameM, Rcpp::CharacterVector fnameMt, std::vector <long> indxNA, std::vector <long> dims);
RcppExport SEXP _Eagle_ReshapeM_rcpp(SEXP fnameMSEXP, SEXP fnameMtSEXP, SEXP indxNASEXP, SEXP dimsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type fnameM(fnameMSEXP);
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type fnameMt(fnameMtSEXP);
    Rcpp::traits::input_parameter< std::vector <long> >::type indxNA(indxNASEXP);
    Rcpp::traits::input_parameter< std::vector <long> >::type dims(dimsSEXP);
    rcpp_result_gen = Rcpp::wrap(ReshapeM_rcpp(fnameM, fnameMt, indxNA, dims));
    return rcpp_result_gen;
END_RCPP
}
// calculateMMt_rcpp
Eigen::MatrixXd calculateMMt_rcpp(Rcpp::CharacterVector f_name_ascii, double max_memory_in_Gbytes, int num_cores, Rcpp::NumericVector selected_loci, std::vector<long> dims, bool quiet, Rcpp::Function message);
RcppExport SEXP _Eagle_calculateMMt_rcpp(SEXP f_name_asciiSEXP, SEXP max_memory_in_GbytesSEXP, SEXP num_coresSEXP, SEXP selected_lociSEXP, SEXP dimsSEXP, SEXP quietSEXP, SEXP messageSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type f_name_ascii(f_name_asciiSEXP);
    Rcpp::traits::input_parameter< double >::type max_memory_in_Gbytes(max_memory_in_GbytesSEXP);
    Rcpp::traits::input_parameter< int >::type num_cores(num_coresSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type selected_loci(selected_lociSEXP);
    Rcpp::traits::input_parameter< std::vector<long> >::type dims(dimsSEXP);
    Rcpp::traits::input_parameter< bool >::type quiet(quietSEXP);
    Rcpp::traits::input_parameter< Rcpp::Function >::type message(messageSEXP);
    rcpp_result_gen = Rcpp::wrap(calculateMMt_rcpp(f_name_ascii, max_memory_in_Gbytes, num_cores, selected_loci, dims, quiet, message));
    return rcpp_result_gen;
END_RCPP
}
// calculate_a_and_vara_batch_rcpp
Rcpp::List calculate_a_and_vara_batch_rcpp(long numreps, Rcpp::CharacterVector f_name_ascii, Rcpp::NumericVector selected_loci, Eigen::Map<Eigen::MatrixXd> inv_MMt_sqrt, Eigen::Map<Eigen::MatrixXd> dim_reduced_vara, double max_memory_in_Gbytes, std::vector <long> dims, Eigen::Map<Eigen::MatrixXd> a, bool quiet, Rcpp::Function message);
RcppExport SEXP _Eagle_calculate_a_and_vara_batch_rcpp(SEXP numrepsSEXP, SEXP f_name_asciiSEXP, SEXP selected_lociSEXP, SEXP inv_MMt_sqrtSEXP, SEXP dim_reduced_varaSEXP, SEXP max_memory_in_GbytesSEXP, SEXP dimsSEXP, SEXP aSEXP, SEXP quietSEXP, SEXP messageSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< long >::type numreps(numrepsSEXP);
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type f_name_ascii(f_name_asciiSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type selected_loci(selected_lociSEXP);
    Rcpp::traits::input_parameter< Eigen::Map<Eigen::MatrixXd> >::type inv_MMt_sqrt(inv_MMt_sqrtSEXP);
    Rcpp::traits::input_parameter< Eigen::Map<Eigen::MatrixXd> >::type dim_reduced_vara(dim_reduced_varaSEXP);
    Rcpp::traits::input_parameter< double >::type max_memory_in_Gbytes(max_memory_in_GbytesSEXP);
    Rcpp::traits::input_parameter< std::vector <long> >::type dims(dimsSEXP);
    Rcpp::traits::input_parameter< Eigen::Map<Eigen::MatrixXd> >::type a(aSEXP);
    Rcpp::traits::input_parameter< bool >::type quiet(quietSEXP);
    Rcpp::traits::input_parameter< Rcpp::Function >::type message(messageSEXP);
    rcpp_result_gen = Rcpp::wrap(calculate_a_and_vara_batch_rcpp(numreps, f_name_ascii, selected_loci, inv_MMt_sqrt, dim_reduced_vara, max_memory_in_Gbytes, dims, a, quiet, message));
    return rcpp_result_gen;
END_RCPP
}
// calculate_a_and_vara_rcpp
Rcpp::List calculate_a_and_vara_rcpp(Rcpp::CharacterVector f_name_ascii, Rcpp::NumericVector selected_loci, Eigen::Map<Eigen::MatrixXd> inv_MMt_sqrt, Eigen::Map<Eigen::MatrixXd> dim_reduced_vara, double max_memory_in_Gbytes, std::vector <long> dims, Eigen::VectorXd a, bool quiet, Rcpp::Function message);
RcppExport SEXP _Eagle_calculate_a_and_vara_rcpp(SEXP f_name_asciiSEXP, SEXP selected_lociSEXP, SEXP inv_MMt_sqrtSEXP, SEXP dim_reduced_varaSEXP, SEXP max_memory_in_GbytesSEXP, SEXP dimsSEXP, SEXP aSEXP, SEXP quietSEXP, SEXP messageSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type f_name_ascii(f_name_asciiSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type selected_loci(selected_lociSEXP);
    Rcpp::traits::input_parameter< Eigen::Map<Eigen::MatrixXd> >::type inv_MMt_sqrt(inv_MMt_sqrtSEXP);
    Rcpp::traits::input_parameter< Eigen::Map<Eigen::MatrixXd> >::type dim_reduced_vara(dim_reduced_varaSEXP);
    Rcpp::traits::input_parameter< double >::type max_memory_in_Gbytes(max_memory_in_GbytesSEXP);
    Rcpp::traits::input_parameter< std::vector <long> >::type dims(dimsSEXP);
    Rcpp::traits::input_parameter< Eigen::VectorXd >::type a(aSEXP);
    Rcpp::traits::input_parameter< bool >::type quiet(quietSEXP);
    Rcpp::traits::input_parameter< Rcpp::Function >::type message(messageSEXP);
    rcpp_result_gen = Rcpp::wrap(calculate_a_and_vara_rcpp(f_name_ascii, selected_loci, inv_MMt_sqrt, dim_reduced_vara, max_memory_in_Gbytes, dims, a, quiet, message));
    return rcpp_result_gen;
END_RCPP
}
// calculate_reduced_a_rcpp
Eigen::MatrixXd calculate_reduced_a_rcpp(Rcpp::CharacterVector f_name_ascii, double varG, Eigen::Map<Eigen::MatrixXd> P, Eigen::Map<Eigen::MatrixXd> y, double max_memory_in_Gbytes, std::vector <long> dims, Rcpp::NumericVector selected_loci, bool quiet, Rcpp::Function message);
RcppExport SEXP _Eagle_calculate_reduced_a_rcpp(SEXP f_name_asciiSEXP, SEXP varGSEXP, SEXP PSEXP, SEXP ySEXP, SEXP max_memory_in_GbytesSEXP, SEXP dimsSEXP, SEXP selected_lociSEXP, SEXP quietSEXP, SEXP messageSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type f_name_ascii(f_name_asciiSEXP);
    Rcpp::traits::input_parameter< double >::type varG(varGSEXP);
    Rcpp::traits::input_parameter< Eigen::Map<Eigen::MatrixXd> >::type P(PSEXP);
    Rcpp::traits::input_parameter< Eigen::Map<Eigen::MatrixXd> >::type y(ySEXP);
    Rcpp::traits::input_parameter< double >::type max_memory_in_Gbytes(max_memory_in_GbytesSEXP);
    Rcpp::traits::input_parameter< std::vector <long> >::type dims(dimsSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type selected_loci(selected_lociSEXP);
    Rcpp::traits::input_parameter< bool >::type quiet(quietSEXP);
    Rcpp::traits::input_parameter< Rcpp::Function >::type message(messageSEXP);
    rcpp_result_gen = Rcpp::wrap(calculate_reduced_a_rcpp(f_name_ascii, varG, P, y, max_memory_in_Gbytes, dims, selected_loci, quiet, message));
    return rcpp_result_gen;
END_RCPP
}
// createM_ASCII_rcpp
bool createM_ASCII_rcpp(Rcpp::CharacterVector f_name, Rcpp::CharacterVector f_name_ascii, Rcpp::CharacterVector type, std::string AA, std::string AB, std::string BB, double max_memory_in_Gbytes, std::vector <long> dims, bool quiet, Rcpp::Function message, std::string missing);
RcppExport SEXP _Eagle_createM_ASCII_rcpp(SEXP f_nameSEXP, SEXP f_name_asciiSEXP, SEXP typeSEXP, SEXP AASEXP, SEXP ABSEXP, SEXP BBSEXP, SEXP max_memory_in_GbytesSEXP, SEXP dimsSEXP, SEXP quietSEXP, SEXP messageSEXP, SEXP missingSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type f_name(f_nameSEXP);
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type f_name_ascii(f_name_asciiSEXP);
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type type(typeSEXP);
    Rcpp::traits::input_parameter< std::string >::type AA(AASEXP);
    Rcpp::traits::input_parameter< std::string >::type AB(ABSEXP);
    Rcpp::traits::input_parameter< std::string >::type BB(BBSEXP);
    Rcpp::traits::input_parameter< double >::type max_memory_in_Gbytes(max_memory_in_GbytesSEXP);
    Rcpp::traits::input_parameter< std::vector <long> >::type dims(dimsSEXP);
    Rcpp::traits::input_parameter< bool >::type quiet(quietSEXP);
    Rcpp::traits::input_parameter< Rcpp::Function >::type message(messageSEXP);
    Rcpp::traits::input_parameter< std::string >::type missing(missingSEXP);
    rcpp_result_gen = Rcpp::wrap(createM_ASCII_rcpp(f_name, f_name_ascii, type, AA, AB, BB, max_memory_in_Gbytes, dims, quiet, message, missing));
    return rcpp_result_gen;
END_RCPP
}
// createM_BIN_rcpp
bool createM_BIN_rcpp(Rcpp::CharacterVector f_name, Rcpp::CharacterVector f_name_bin, Rcpp::CharacterVector type, std::string AA, std::string AB, std::string BB, double max_memory_in_Gbytes, std::vector <long> dims, bool quiet, Rcpp::Function message, std::string missing);
RcppExport SEXP _Eagle_createM_BIN_rcpp(SEXP f_nameSEXP, SEXP f_name_binSEXP, SEXP typeSEXP, SEXP AASEXP, SEXP ABSEXP, SEXP BBSEXP, SEXP max_memory_in_GbytesSEXP, SEXP dimsSEXP, SEXP quietSEXP, SEXP messageSEXP, SEXP missingSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type f_name(f_nameSEXP);
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type f_name_bin(f_name_binSEXP);
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type type(typeSEXP);
    Rcpp::traits::input_parameter< std::string >::type AA(AASEXP);
    Rcpp::traits::input_parameter< std::string >::type AB(ABSEXP);
    Rcpp::traits::input_parameter< std::string >::type BB(BBSEXP);
    Rcpp::traits::input_parameter< double >::type max_memory_in_Gbytes(max_memory_in_GbytesSEXP);
    Rcpp::traits::input_parameter< std::vector <long> >::type dims(dimsSEXP);
    Rcpp::traits::input_parameter< bool >::type quiet(quietSEXP);
    Rcpp::traits::input_parameter< Rcpp::Function >::type message(messageSEXP);
    Rcpp::traits::input_parameter< std::string >::type missing(missingSEXP);
    rcpp_result_gen = Rcpp::wrap(createM_BIN_rcpp(f_name, f_name_bin, type, AA, AB, BB, max_memory_in_Gbytes, dims, quiet, message, missing));
    return rcpp_result_gen;
END_RCPP
}
// createMt_ASCII_rcpp
void createMt_ASCII_rcpp(Rcpp::CharacterVector f_name, Rcpp::CharacterVector f_name_ascii, Rcpp::CharacterVector type, double max_memory_in_Gbytes, std::vector <long> dims, bool quiet, Rcpp::Function message);
RcppExport SEXP _Eagle_createMt_ASCII_rcpp(SEXP f_nameSEXP, SEXP f_name_asciiSEXP, SEXP typeSEXP, SEXP max_memory_in_GbytesSEXP, SEXP dimsSEXP, SEXP quietSEXP, SEXP messageSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type f_name(f_nameSEXP);
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type f_name_ascii(f_name_asciiSEXP);
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type type(typeSEXP);
    Rcpp::traits::input_parameter< double >::type max_memory_in_Gbytes(max_memory_in_GbytesSEXP);
    Rcpp::traits::input_parameter< std::vector <long> >::type dims(dimsSEXP);
    Rcpp::traits::input_parameter< bool >::type quiet(quietSEXP);
    Rcpp::traits::input_parameter< Rcpp::Function >::type message(messageSEXP);
    createMt_ASCII_rcpp(f_name, f_name_ascii, type, max_memory_in_Gbytes, dims, quiet, message);
    return R_NilValue;
END_RCPP
}
// createMt_BIN_rcpp
void createMt_BIN_rcpp(Rcpp::CharacterVector f_name_in, Rcpp::CharacterVector f_name_out, Rcpp::CharacterVector type, double max_memory_in_Gbytes, std::vector <long> dims, bool quiet, Rcpp::Function message);
RcppExport SEXP _Eagle_createMt_BIN_rcpp(SEXP f_name_inSEXP, SEXP f_name_outSEXP, SEXP typeSEXP, SEXP max_memory_in_GbytesSEXP, SEXP dimsSEXP, SEXP quietSEXP, SEXP messageSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type f_name_in(f_name_inSEXP);
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type f_name_out(f_name_outSEXP);
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type type(typeSEXP);
    Rcpp::traits::input_parameter< double >::type max_memory_in_Gbytes(max_memory_in_GbytesSEXP);
    Rcpp::traits::input_parameter< std::vector <long> >::type dims(dimsSEXP);
    Rcpp::traits::input_parameter< bool >::type quiet(quietSEXP);
    Rcpp::traits::input_parameter< Rcpp::Function >::type message(messageSEXP);
    createMt_BIN_rcpp(f_name_in, f_name_out, type, max_memory_in_Gbytes, dims, quiet, message);
    return R_NilValue;
END_RCPP
}
// create_vcf_BIN_rcpp
Rcpp::NumericVector create_vcf_BIN_rcpp(Rcpp::CharacterVector f_name, Rcpp::CharacterVector f_name_bin_M, Rcpp::CharacterVector f_name_bin_Mt, double max_memory_in_Gbytes, bool quiet, Rcpp::Function message);
RcppExport SEXP _Eagle_create_vcf_BIN_rcpp(SEXP f_nameSEXP, SEXP f_name_bin_MSEXP, SEXP f_name_bin_MtSEXP, SEXP max_memory_in_GbytesSEXP, SEXP quietSEXP, SEXP messageSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type f_name(f_nameSEXP);
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type f_name_bin_M(f_name_bin_MSEXP);
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type f_name_bin_Mt(f_name_bin_MtSEXP);
    Rcpp::traits::input_parameter< double >::type max_memory_in_Gbytes(max_memory_in_GbytesSEXP);
    Rcpp::traits::input_parameter< bool >::type quiet(quietSEXP);
    Rcpp::traits::input_parameter< Rcpp::Function >::type message(messageSEXP);
    rcpp_result_gen = Rcpp::wrap(create_vcf_BIN_rcpp(f_name, f_name_bin_M, f_name_bin_Mt, max_memory_in_Gbytes, quiet, message));
    return rcpp_result_gen;
END_RCPP
}
// extract_geno_Mt_rcpp
Eigen::VectorXi extract_geno_Mt_rcpp(Rcpp::CharacterVector f_name, long selected_locus, std::vector<long> dims);
RcppExport SEXP _Eagle_extract_geno_Mt_rcpp(SEXP f_nameSEXP, SEXP selected_locusSEXP, SEXP dimsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type f_name(f_nameSEXP);
    Rcpp::traits::input_parameter< long >::type selected_locus(selected_locusSEXP);
    Rcpp::traits::input_parameter< std::vector<long> >::type dims(dimsSEXP);
    rcpp_result_gen = Rcpp::wrap(extract_geno_Mt_rcpp(f_name, selected_locus, dims));
    return rcpp_result_gen;
END_RCPP
}
// extract_geno_rcpp
Eigen::VectorXi extract_geno_rcpp(Rcpp::CharacterVector f_name_ascii, double max_memory_in_Gbytes, long selected_locus, std::vector<long> dims);
RcppExport SEXP _Eagle_extract_geno_rcpp(SEXP f_name_asciiSEXP, SEXP max_memory_in_GbytesSEXP, SEXP selected_locusSEXP, SEXP dimsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type f_name_ascii(f_name_asciiSEXP);
    Rcpp::traits::input_parameter< double >::type max_memory_in_Gbytes(max_memory_in_GbytesSEXP);
    Rcpp::traits::input_parameter< long >::type selected_locus(selected_locusSEXP);
    Rcpp::traits::input_parameter< std::vector<long> >::type dims(dimsSEXP);
    rcpp_result_gen = Rcpp::wrap(extract_geno_rcpp(f_name_ascii, max_memory_in_Gbytes, selected_locus, dims));
    return rcpp_result_gen;
END_RCPP
}
// fasttimer
double fasttimer();
RcppExport SEXP _Eagle_fasttimer() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(fasttimer());
    return rcpp_result_gen;
END_RCPP
}
// getRowColumn
std::vector<long> getRowColumn(std::string fname);
RcppExport SEXP _Eagle_getRowColumn(SEXP fnameSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type fname(fnameSEXP);
    rcpp_result_gen = Rcpp::wrap(getRowColumn(fname));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_Eagle_ReadBlock", (DL_FUNC) &_Eagle_ReadBlock, 4},
    {"_Eagle_ReadBlockBin", (DL_FUNC) &_Eagle_ReadBlockBin, 4},
    {"_Eagle_ReshapeM_rcpp", (DL_FUNC) &_Eagle_ReshapeM_rcpp, 4},
    {"_Eagle_calculateMMt_rcpp", (DL_FUNC) &_Eagle_calculateMMt_rcpp, 7},
    {"_Eagle_calculate_a_and_vara_batch_rcpp", (DL_FUNC) &_Eagle_calculate_a_and_vara_batch_rcpp, 10},
    {"_Eagle_calculate_a_and_vara_rcpp", (DL_FUNC) &_Eagle_calculate_a_and_vara_rcpp, 9},
    {"_Eagle_calculate_reduced_a_rcpp", (DL_FUNC) &_Eagle_calculate_reduced_a_rcpp, 9},
    {"_Eagle_createM_ASCII_rcpp", (DL_FUNC) &_Eagle_createM_ASCII_rcpp, 11},
    {"_Eagle_createM_BIN_rcpp", (DL_FUNC) &_Eagle_createM_BIN_rcpp, 11},
    {"_Eagle_createMt_ASCII_rcpp", (DL_FUNC) &_Eagle_createMt_ASCII_rcpp, 7},
    {"_Eagle_createMt_BIN_rcpp", (DL_FUNC) &_Eagle_createMt_BIN_rcpp, 7},
    {"_Eagle_create_vcf_BIN_rcpp", (DL_FUNC) &_Eagle_create_vcf_BIN_rcpp, 6},
    {"_Eagle_extract_geno_Mt_rcpp", (DL_FUNC) &_Eagle_extract_geno_Mt_rcpp, 3},
    {"_Eagle_extract_geno_rcpp", (DL_FUNC) &_Eagle_extract_geno_rcpp, 4},
    {"_Eagle_fasttimer", (DL_FUNC) &_Eagle_fasttimer, 0},
    {"_Eagle_getRowColumn", (DL_FUNC) &_Eagle_getRowColumn, 1},
    {NULL, NULL, 0}
};

RcppExport void R_init_Eagle(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
