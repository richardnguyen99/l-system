# Core CMake for the L-System Rewriting
# Copyright (C) 2023 Richard H. Nguyen
#
# This file is a part of the L-System Project
#
# This program is free software: you can redistribute it and/or modify it under
# the terms of the GNU General Public License as published by the Free Software
# Foundation, either version 3 of the License, or (at your option) any later
# version.
#
# This program is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of  MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along with
# this program.  If not, see <http://www.gnu.org/licenses/>.
#
# Written by Richard H. Nguyen <richard@richardhnguyen.com>

# Require the minimum version of CMake to be 3.16
cmake_minimum_required(VERSION 3.16)

# Initialize the project
project(l-system VERSION 0.1 LANGUAGES CXX)

# Enable C++ project
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

add_compile_definitions(QT_USE_STRING_BUILDER)

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
    src/LSystemPoint.cpp
    src/LSystemDrawer.cpp
    src/LSystemQueue.cpp
    src/LSystemStack.cpp
    src/LSystemRewriter.cpp
)

# Set the header files
set(HEADERS
    include/LSystemCore.h
    include/LSystemDrawer.h
    include/LSystemPoint.h
    include/LSystemQueue.h
    include/LSystemStack.h
    include/LSystemRewriter.h
)

# Set the QML files
set(QML
    qml/Main.qml
    qml/LSCanvas.qml
)

# The logic of the project will be built into one binary object, `lsystemapp`.
# Then, the main will link it to build a complete executable
add_library(lsystemapp STATIC)
target_include_directories(lsystemapp PUBLIC src/ include)

# Add necessary files to the library
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

# Link the object with Qt Core libraries
target_link_libraries(lsystemapp
    PUBLIC 	Qt6::Quick
            Qt6::Gui
            Qt6::Core
            Qt6::QuickControls2
)

qt_standard_project_setup()

# The main executable of the L-System Project
qt_add_executable(lsystem
    src/main.cpp
)

# Link with `lsystemapp` to create a complet app
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
