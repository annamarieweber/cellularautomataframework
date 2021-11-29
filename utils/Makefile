# MSSE Chem 274B - Fall Semester
# University of California, Berkeley
# 
# Creator:  U Jamshed, Student
# Date Created: Nov 17th, 2021
#
# This makefile creates objects from utility functions in C++
# after creation the objects are relocated to the ../lib directory

# GNU C++ Compiler
CXX         = g++      

# compiler flags -g debug, -O3 optimized version -c create a library object
CXXFLAGS    = -O3 -c 

# The directory where the include files needed to create the library objects are
INC_DIR = ../include
# The directory where all object files are going to moved afer creation
LIB_DIR     = ../lib

# The next line contains the list of utility objects created by this Makefile.
UTILS_OBJS = utils.o

utils.o: $(INC_DIR)/myutils.h
	$(CXX) $(CXXFLAGS) utils.cxx -I$(INC_DIR)
	mv utils.o $(LIB_DIR)

all: $(UTILS_OBJS)

cleanall:
	cd $(LIB_DIR); rm $(UTILS_OBJS)