
fev <- read.table("fev.txt", header = TRUE)

fev; dimnames(fev); class(fev); dim(fev)

library(CoCoCg)

fevObject <- makeCoCoCg()

result <- enterDataFrame(fev)

enterModel(".;")

showTable("observed", ":Sex:Smoker")
showTable("canonical", ":Age:FEV:Height", table = TRUE)
showTable("canonical", ":Age:FEV:Height", matrix = TRUE)

showOptions()

exportCoCo("fev.xpt")

endCoCo();
