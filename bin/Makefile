#
# This Makefile generates Message Passing Interface (MPI) examples programs
# for MSSE Chem 274B - Fall Semester
# University of California, Berkeley
# 
# Creator:  L. A. Drummond, PhD.  Faculty
# Date Created: Oct 5, 2021
#
# This makefile can run different program in the /bin directory
# It provides examples on how the different executable program should be run from
# the command line

EXECUTABLES = mainfactorials test_spyargsv test_factorials

TEST_SUITE = run_test1_spyargs run_test2_spyargs run_test3_spyargs 
	     run_mainfactorials1 run_mainfactorials2 run_mainfactorials3 
	     run_testfac1, run_testfac2


# run test_spyargs
run_test1_spyargs: test_spyargsv
	./test_spyargsv

run_test2_spyargs: test_spyargsv
	./test_spyargsv -n 9 -p 15

run_test3_spyargs: test_spyargsv
	./test_spyargsv -n 9 -p 15 -nrect 1000000

# run mainfactorials
run_mainfactorials1: mainfactorials
	./mainfactorials -rfactorial

run_mainfactorials2: mainfactorials
	./mainfactorials -n 12 -pfactorial 

run_mainfactorials3: mainfactorials
	./mainfactorials -n 20 -pfactorial

# run test_factorials
run_testfac1: test_factorials
	./test_factorials -n 12 -pfactorial -rfactorial

run_testfac2: test_factorials
	./test_factorials -n 20 -pfactorial

all: $(TEST_SUITE)

cleanall:	
	rm $(EXECUTABLES)
