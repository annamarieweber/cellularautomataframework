# for MSSE Chem 274B - Fall Semester
# University of California, Berkeley
# 
# Creator:  Anna Weber
# Date Created: Dec 15, 2021
#
# This makefile creates compute processing objects in C++
# after creation the objects are relocated to the ../lib directory

# GNU C++ Compiler
CXX         = g++      

# compiler flags -g debug, -O3 optimized version -c create a library object
CXXFLAGS    = -std=c++11 -O3 -c    

# The directory where the include files needed to create the library objects are
INC_DIR = ../../include

# The directory where all object files are going to moved afer creation
LIB_DIR     = ../../lib

# targets this makefile builds
COMPUTE_OBJS = ComputeEngine.o

ComputeEngine.o: $(INC_DIR)/myutils.h $(INC_DIR)/CellularAutomata.h $(INC_DIR)/ComputeEngine.h 
	$(CXX) $(CXXFLAGS) ComputeEngine.cxx -I$(INC_DIR)
	mv ComputeEngine.o $(LIB_DIR)

all: $(COMPUTE_OBJS)

cleanall:
	cd $(LIB_DIR); rm $(COMPUTE_OBJS)