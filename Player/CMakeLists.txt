project(Player)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(
        "${CMAKE_SOURCE_DIR}/YUVLib/include"
)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5OpenGL REQUIRED)
find_package(OpenGL)

add_executable(Player main.cpp MainWindow.cpp ChangeParams.cpp GLWidget.cpp)

qt5_use_modules(Player Widgets OpenGL)
target_link_libraries(Player YUVLib ${QT_LIBRARIES} ${OPENGL_LIBRARIES})