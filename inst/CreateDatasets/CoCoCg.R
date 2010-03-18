
# library(CoCo);

"makeCoCoCg"<- function(...) {
    make.cococg(...)
  }

.First.lib <- function(lib, pkg) {
    require(methods)
    require(CoCoCore)
    require(CoCoObjects)
    require(CoCoRaw)
    require(CoCo)
    library.dynam("CoCoCg", pkg, lib)
  }

".onLoad" <- function (lib, pkg) {
    library.dynam("CoCoCg", pkg, lib)
     # .First.lib.CoCoCore(lib, pkg)          # Done in CoCo
     # .First.lib.CoCoObjects(lib, pkg)       # Done in CoCoObjects
     # .First.lib.CoCoDynamicGraph(lib, pkg)  # Done in CoCoObjects
  }

".onAttach" <- function (lib, pkg) {
     require(tcltk)
     require(dynamicGraph)
     # .First.lib.CoCoCore(lib, pkg)
     # .First.lib.CoCoObjects(lib, pkg)
     # .First.lib.CoCoDynamicGraph(lib, pkg)
  }

# package.skeleton("CoCoCg", list = ls(all.names = TRUE))

# q()
