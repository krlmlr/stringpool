#' Write R's global string pool to a file
#'
#' Writes all strings currently known to R to a plain text file, newline-delimited.
#' @inheritParams base::writeLines
#' @export
write_stringpool <- function(con, sep = "\n") {
  writeLines(stringpool(), con, sep = sep)
}
