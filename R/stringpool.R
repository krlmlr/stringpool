#' R's global string pool
#'
#' Returns a character vector of all strings currently known to R, sorted.
#'
#' @export
stringpool <- function() {
  sort(hash_table())
}
