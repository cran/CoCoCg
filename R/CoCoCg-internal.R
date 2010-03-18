".packageName" <- "CoCoCg"

".First.lib" <-
function (lib, pkg) 
{
    require(methods)
#    require(CoCoObjects)
#    require(CoCoCore)
#    require(CoCoRaw)
    # require(CoCo)

    library.dynam("CoCoCg", pkg, lib)
}

".onAttach" <-
function (lib, pkg) 
{
#    require(CoCoRaw)
    # require(CoCo)
}

".onLoad" <-
function (lib, pkg) 
{
#    require(CoCoRaw)
    # require(CoCo)

    library.dynam("CoCoCg", pkg, lib)

}

# 'require(CoCo)' does not agree with 'R CMD check' (> 2.9.0).
# 'dG' will be missing after library(CoCoCg)!