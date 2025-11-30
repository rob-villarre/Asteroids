
project(App)

add_executable(${PROJECT_NAME} Source/main.cpp
        Source/TestLayer.cpp
        Include/TestLayer.h)

target_link_libraries(${PROJECT_NAME} PRIVATE Juno)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Include)