# for MSSE Chem 274B - Fall Semester
# University of California, Berkeley
# 
# Creator: Anna Weber
# Date Created: Nov 08, 2021
#
# This makefile creates executable tests and runs them

# GNU C++ Compiler
CXX         = g++      

# compiler flags -g debug, -O3 optimized version -c create a library object
CXXFLAGS    = -std=c++11 -O3 -o

# The directory where the include files needed to create the library objects are
INC_DIR = ../include

# The directory where all object files are going to moved afer creation
LIB_DIR     = ../lib
BIN_DIR     = ../bin

# The next line contains the list of utility objects created by this Makefile.
EXECUTABLES = politics_example

politics_example: $(INC_DIR)/myutils.h $(INC_DIR)/CellularAutomata.h $(INC_DIR)/ComputeEngine.h
	$(CXX) $(CXXFLAGS) politics_example politics_example.cxx -I$(INC_DIR) $(LIB_DIR)/utils.o $(LIB_DIR)/CA_input.o $(LIB_DIR)/ComputeEngine.o $(LIB_DIR)/CA_output.o
	mv politics_example $(BIN_DIR)

all: $(EXECUTABLES)

examples:
	make all
	echo Politics Example
	$(BIN_DIR)/politics_example

cleanall:
	cd $(BIN_DIR); rm $(EXECUTABLES)
