\name{Rats}
\alias{Rats}
\docType{data}

\title{ Rats' Weights }

\description{ Drug trail on rats: Weight loss. }

\usage{data(Rats)}

\format{
  A data frame with 24 observations on the following 4 variables.
  \describe{
    \item{a}{Sex        : a factor with levels \code{1} \code{2}}
    \item{b}{Drug       : a factor with levels \code{1} \code{2} \code{3}}
    \item{x}{Wt. loss 1 : a numeric vector}
    \item{y}{Wt. loss 2 : a numeric vector}
  }
 }

\details{ Page 75 of Edwards (2000): The data stem from another drug trail, in
	  which the weight losses of male and female rats under three drug
	  treatments are studied. Four rats of each sex are assigned at random
	  to each drug. Weight losses are observed after one and two weeks. }

\source{
  Edwards, David (2000). Introduction to Graphical modelling, Springer.
}

\references{
  Morrison (1976). Multivariate Statistical Methods, McGraw-Hill.
  Mardia, Kent, and Bibby (1979). Multivariate Analysis, Academic Press.
}

\examples{
data(Rats);
CoCoObject <- makeCoCoCg();
enterDataFrame(Rats, object = CoCoObject);
fullModel <- makeModel(enterModel("*", object = CoCoObject));
eh(object = CoCoObject);
eh(sub.class = "hierarchical", object = CoCoObject);
endCoCo(object = CoCoObject);
}

\keyword{datasets}
