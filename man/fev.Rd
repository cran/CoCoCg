\name{fev}
\alias{fev}
\docType{data}
\title{ Childhood Respiratory Disease }

\description{ FEV (forced expiratory volume) is an index of pulmonary function
	      that measures the volume of air expelled after one second of
	      constant effort. The data contains determinations of FEV on 654
	      children ages 6-22 who were seen in the Childhood Respiratory
	      Desease Study in 1980 in East Boston, Massachusetts. The data
	      are part of a larger study to follow the change in pulmonary
	      function over time in children. }

\usage{data(fev)}

\format{
  A data frame with 654 observations on the following 6 variables.
  \describe{
    \item{ID}{ ( ID number) , a numeric vector}
    \item{Age}{ ( Years) , a numeric vector}
    \item{FEV}{ ( Liters) , a numeric vector}
    \item{Height}{ ( Inches) , a numeric vector}
    \item{Sex}{ ( Male or Female) ,
                a factor with levels \code{Female} \code{Male}}
    \item{Smoker}{ ( Non = nonsmoker, Current = current smoke) ,
		  a factor with levels \code{Current} \code{Non}}
  }
}

% \details{  }

\source{ Gordon Smyth: http://www.isd.sdu.dk/~gks/data/general/fev.html }

\references{
 Tager, I. B., Weiss, S. T., Rosner, B., and Speizer, F. E. (1979). Effect of
 parental cigarette smoking on pulmonary function in children. American
 Journal of Epidemiology, 110, 15-26.  

 Rosner, B. (1990). Fundamentals of Biostatistics, 3rd Edition. PWS-Kent,
 Boston, Massachusetts. }

\examples{
data(fev);
FevObject <- makeCoCoCg();
result <- enterDataFrame(fev[,2:6], object = FevObject);
enterModel("*;", object = FevObject);
makeBase("current", object = FevObject);
showOptions(object = FevObject);
showModel("all", object = FevObject);
backward(only = TRUE, sorted = TRUE, decomposable.mode = TRUE,
         coherent = TRUE, headlong = TRUE, recursive = TRUE, follow = TRUE,
         object = FevObject);
makeCurrent("last", object = FevObject);
showModel("all", object = FevObject);
showModel("current", describe = TRUE, object = FevObject);
str(returnExpression(model = FALSE, type = "junction.tree.components", 
                   omit.prime.components = FALSE, omit.separators = FALSE,
                   omit.generators = FALSE, return.flags = TRUE,
                   object = FevObject));
endCoCo(object = FevObject)
}

\keyword{datasets}
