
project(App)

add_executable(${PROJECT_NAME} Source/main.cpp
        Source/GameLayer.cpp
        Include/GameLayer.h
        Source/Player.cpp
        Include/Player.h
        Source/InputHandler.cpp
        Include/InputHandler.h
        Source/Asteroid.cpp
        Include/Asteroid.h)

target_link_libraries(${PROJECT_NAME} PRIVATE Juno)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Include)