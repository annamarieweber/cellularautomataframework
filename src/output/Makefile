# for MSSE Chem 274B - Fall Semester
# University of California, Berkeley
# 
# Creator:  Anna Weber
# Date Created: Nov 08, 2021
#
# This makefile creates output processing objects in C++
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
OUTPUT_OBJS = CA_output.o

CA_output.o: $(INC_DIR)/myutils.h $(INC_DIR)/CellularAutomata.h
	$(CXX) $(CXXFLAGS) CA_output.cxx -I$(INC_DIR)
	mv CA_output.o $(LIB_DIR)
	
all: $(OUTPUT_OBJS)

cleanall:
	cd $(LIB_DIR); rm $(OUTPUT_OBJS)