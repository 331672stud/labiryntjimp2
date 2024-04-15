CC = gcc

all: Preprocessor Solver

Preprocessor: compressedReader.o Errormsg.o getoptt.o graphDivider.o graphWriter.o LabSolverPreprocessor.o matrixGraphConverter.o textReader.o valconvert.o
	$(CC) -o Preprocessor compressedReader.o Errormsg.o getoptt.o graphDivider.o graphWriter.o LabSolverPreprocessor.o matrixGraphConverter.o textReader.o valconvert.o

compressedReader.o: compressedReader.c adjacencyMatrix.h valconvert.h matrixGraphConverter.h
	$(CC) -c compressedReader.c

Errormsg.o: Errormsg.c
	$(CC) -c Errormsg.c

getoptt.o: getoptt.c Errormsg.h
	$(CC) -c getoptt.c

graphDivider.o: graphDivider.c adjacencyMatrix.h graphWriter.h valconvert.h
	$(CC) -c graphDivider.c

graphWriter.o: graphWriter.c Errormsg.h adjacencyMatrix.h
	$(CC) -c graphWriter.c

LabSolverPreprocessor.o: LabSolverPreprocessor.c getoptt.h compressedReader.h textReader.h adjacencyMatrix.h graphDivider.h
	$(CC) -c LabSolverPreprocessor.c

matrixGraphConverter.o: matrixGraphConverter.c adjacencyMatrix.h Errormsg.h valconvert.h
	$(CC) -c matrixGraphConverter.c

textReader.o: textReader.c adjacencyMatrix.h Errormsg.h matrixGraphConverter.h valconvert.h
	$(CC) -c textReader.c

valconvert.o: valconvert.c adjacencyMatrix.h
	$(CC) -c valconvert.c


Solver: Errormsg.o FileList.o getoptt.o LabSolver.o PathFinder.o writer.o
	$(CC) -o Solver Errormsg.o FileList.o getoptt.o LabSolver.o PathFinder.o writer.o

FileList.o: FileList.c
	$(CC) -c FileList.c

LabSolver.o: LabSolver.c getoptt.h PathFinder.h FileList.h writer.h adjacencyMatrix.h 
	$(CC) -c LabSolver.c

PathFinder.o: PathFinder.c FileList.h
	$(CC) -c PathFinder.c

writer.o: writer.c FileList.h
	$(CC) -c writer.c

clean:
	rm -f Preprocessor Solver *.o
