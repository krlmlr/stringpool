// #define R_NO_REMAP
// #define STRICT_R_HEADERS
// #include <Rinternals.h>

#include <cpp11.hpp>
using namespace cpp11;

extern SEXP R_StringHash;

[[cpp11::register]]
cpp11::strings hash_table() {
  cpp11::writable::strings out;

  for (size_t i = 0; i < LENGTH(R_StringHash); ++i) {
    for (SEXP chain = VECTOR_ELT(R_StringHash, i); chain != R_NilValue; chain = ATTRIB(chain)) {
      out.push_back(chain);
    }
  }

  return out;
}
