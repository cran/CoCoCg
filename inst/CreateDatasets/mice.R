
require(CoCoCg)

Mice <- read.table("mice.txt", header = TRUE)

Mice; dimnames(Mice); class(Mice); dim(Mice)

library(CoCoCg)

MiceObject <- makeCoCoCg(title = "Source: Morrison (1976). Multivariate Statistical Methods, McGraw-Hill.")

result <- enterDataFrame(Mice, to.factor = 1)
Mice[,1] <- as.factor(Mice[,1])

miceMainFull <- makeModel("*;")

dynamic.Graph(miceMainFull, 
              vertexColor = "black", title = "miceMainFull")

miceHomogene <- makeModel("a,xyz")
dynamic.Graph(miceHomogene, 
              vertexColor = "blue", title = "miceHomogene")


showTest()
showTest(miceHomogene, miceMainFull)

returnTable("moment")$SSD.t
returnTable("ms", model = 1)$Variance.t
returnTable("ms", model = 2)$Variance.t

miceModel3 <- makeModel("axy,xyz")
dynamic.Graph(miceModel3, 
              vertexColor = "blue", title = "model3")

showTest(miceModel3, miceMainFull)
returnTable("ms", model = 2)$Variance.t
returnTable("ms", model = 3)$Variance.t

endCoCo()
