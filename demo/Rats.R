
# Attach data:
data(Rats);

# Create a CoCoCg-object:
CoCoObject <- makeCoCoCg();

# Enter the table of counts into the CoCo-object:
enterDataFrame(Rats, object = CoCoObject);

# Do the EH-procedure:
eh(object = CoCoObject);

# Enter the saturated model into the CoCo-object, and return a model object:
fullModel <- makeModel(enterModel("*", object = CoCoObject));

# Display a graph of the model (requires 'library(CoCoGraph)'):
fullGraph <- dG(fullModel, title = "Full", vertexColor = "blue",
                width = 300, height = 300, returnLink = TRUE);
# fullGraph <- dg(fullModel, title = "Full", vertexColor = "blue",
#                 width = 300, height = 300, returnLink = TRUE);

# Do a backward elimination of edges:
backward(recursive = TRUE, headlong = TRUE, coherent = TRUE,
         follow = TRUE, object = CoCoObject);

# Display the result of the backward elimination:
lastModel <- makeModel("last", object = CoCoObject);
backwardGraph <- dG(lastModel, title = "Last",
                    dynamicGraph = fullGraph, slave = TRUE);
# backwardGraph <- dg(lastModel, title = "Last",
#                     dynamicGraph = fullGraph, slave = TRUE);

# Terminate the CoCo-object with disposing temporary files:
# endCoCo(object = CoCoObject);
