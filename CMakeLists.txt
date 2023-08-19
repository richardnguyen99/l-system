# Require the minimum version of CMake to be 3.16
cmake_minimum_required(VERSION 3.16)

# Initialize the project
project(l-system VERSION 0.1 LANGUAGES CXX)

# Enable C++ project
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

# Enable auto config for QRC and MOC files
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Find all required packages from Qt6
find_package(
    Qt6 6.4
    REQUIRED COMPONENTS Core
                        Quick
                        QuickControls2
                        Gui
                        Test)

# Set the implementation source files
set(SOURCES
    # src/app.cpp
)

# Set the header files
set(HEADERS
    include/ls_core.h
)

# Set the QML files
set(QML
    qml/Main.qml
)

add_library(lsystemapp STATIC)
target_include_directories(lsystemapp PUBLIC src/ include)

qt_add_qml_module(lsystemapp
    URI lsystemapp
    VERSION
        0.1
    QML_FILES
        ${QML}
    SOURCES
        ${SOURCES}
        ${HEADERS}
    RESOURCES lsystem.qrc
)

target_link_libraries(lsystemapp
    PUBLIC 	Qt6::Quick
            Qt6::Gui
            Qt6::Core
            Qt6::QuickControls2
)

qt_standard_project_setup()

qt_add_executable(lsystem
    src/main.cpp
    src/README.md
)

target_link_libraries(lsystem PRIVATE lsystemapp)

target_include_directories(lsystemapp
    PUBLIC include/
    PRIVATE src/
)
# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(lsystem PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appl-system
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS lsystem
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
