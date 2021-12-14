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
CXXFLAGS    = -O3 -o

# The directory where the include files needed to create the library objects are
INC_DIR = ../include

# The directory where all object files are going to moved afer creation
LIB_DIR     = ../lib
BIN_DIR     = ../bin

# The next line contains the list of utility objects created by this Makefile.
EXECUTABLES = test_CA_input

test_CA_input: $(INC_DIR)/myutils.h $(INC_DIR)/CellularAutomata.h
	$(CXX) $(CXXFLAGS) test_CA_input test_CA_input.cxx -I$(INC_DIR) $(LIB_DIR)/utils.o $(LIB_DIR)/CA_input.o
	mv test_CA_input $(BIN_DIR)

all: $(EXECUTABLES)

test: $(EXECUTABLES)
	echo Testing Input Functionality
	$(BIN_DIR)/test_CA_input
	echo Testing Compute Functionality
	$(BIN_DIR)/test_CA_compute

cleanall:
	cd $(BIN_DIR); rm $(EXECUTABLES)
