// Generated by cpp11: do not edit by hand
// clang-format off


#include "cpp11/declarations.hpp"
#include <R_ext/Visibility.h>

// code.cpp
cpp11::strings hash_table();
extern "C" SEXP _stringpool_hash_table() {
  BEGIN_CPP11
    return cpp11::as_sexp(hash_table());
  END_CPP11
}

extern "C" {
static const R_CallMethodDef CallEntries[] = {
    {"_stringpool_hash_table", (DL_FUNC) &_stringpool_hash_table, 0},
    {NULL, NULL, 0}
};
}

extern "C" attribute_visible void R_init_stringpool(DllInfo* dll){
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
  R_forceSymbols(dll, TRUE);
}
