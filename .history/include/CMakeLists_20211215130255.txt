find_package(Matplot++ REQUIRED)

add_executable(my_target ../output/test_CA_output.cxx)
target_link_libraries(my_target PUBLIC Matplot++::matplot)