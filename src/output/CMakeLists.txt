find_package(Matplot++ REQUIRED)

add_executable(my_target main.cpp)
target_link_libraries(my_target PUBLIC Matplot++::matplot)