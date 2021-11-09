# This Makefile generates the cellular automata framework and supporting examples
# for MSSE Chem 274B - Fall Semester
# University of California, Berkeley
# 
# Creator:  Anna Weber
# Date Created: Nov 08, 2021

# This is the main build makefile
UTILS_DIR = utils/
TEST_DIR = tests/

all:
	cd $(UTILS_DIR); make all
	cd $(TEST_DIR); make all

testall:
	cd $(UTILS_DIR); make test
	cd $(TEST_DIR); make test

cleanall:	
	cd $(UTILS_DIR); make cleanall
	cd $(TEST_DIR); make cleanall