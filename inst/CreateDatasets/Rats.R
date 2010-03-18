

require(CoCoCg)

Rats <- read.table("rats.txt", header = TRUE)

Rats; dimnames(Rats); class(Rats); dim(Rats)

library(CoCoCg)

RatsObject <- makeCoCoCg(title = "Source: Morrison (1976). Multivariate Statistical Methods, McGraw-Hill. a: Sex; b: Treatment; x: Wt loss 1; y: Wt loss 2")

result <- enterDataFrame(Rats, to.factor = 1:2)

# ratsMainEffects <- makeModel(".;")
# ratsMainFull <- makeModel("*;")

# dynamic.Graph(ratsMainEffects, 
#               vertexColor = "blue", title = "ratsMainEffects")
# dynamic.Graph(ratsMainFull, 
#               vertexColor = "black", title = "ratsMainFull")

Rats[,1] <- as.factor(Rats[,1])
Rats[,2] <- as.factor(Rats[,2])

endCoCo()
