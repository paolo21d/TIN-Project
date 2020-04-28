cmake_minimum_required(VERSION 3.15)
project(server)
set(CMAKE_CXX_STANDARD 20)

include_directories(server C:/oracle/instantclient_12_2/sdk/include)
link_directories(server C:/oracle/instantclient_12_2/sdk/lib/msvc)
add_executable(server src/main.cpp src/SensorConnectionHandler.cpp src/ConnectionsManager.cpp src/ISensorConnectionHandler.cpp src/DatabaseManager.cpp ../Common/ConnectionException.cpp ../Common/NetworkUtils.cpp)

target_include_directories(server PRIVATE ../Common)

if(WIN32)
    target_link_libraries(server wsock32 ws2_32)
endif()

if(_WIN64)
    target_link_libraries(server wsock32 ws2_32)
endif()

target_link_libraries(server C:/oracle/instantclient_12_2/sdk/lib/msvc/oraocci12.lib)
target_link_libraries(server C:/oracle/instantclient_12_2/sdk/lib/msvc/oraocci12d.lib)
target_link_libraries(server C:/oracle/instantclient_12_2/sdk/lib/msvc/oci.lib)
