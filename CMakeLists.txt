CMAKE_MINIMUM_REQUIRED(VERSION 2.8.12)
PROJECT(sys_chart)

#set build mode;
#=================================================================
#SET(CMAKE_BUILD_TYPE DEBUG)
SET(CMAKE_BUILD_TYPE RELEASE)
#=================================================================

#Qt5 settings
#=================================================================
FIND_PACKAGE(Qt5Widgets)
FIND_PACKAGE(Qt5Network)
FIND_PACKAGE(Qt5Gui)
FIND_PACKAGE(Qt5Xml)
FIND_PACKAGE(Qt5PrintSupport)
FIND_PACKAGE(Qt5OpenGL)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(CMAKE_AUTOMOC ON)
#=================================================================

#Boost
#=================================================================
FIND_PACKAGE(Boost 1.54 COMPONENTS thread system filesystem timer chrono REQUIRED)
#=================================================================

#cmake settings
#=================================================================
#set include files;
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/include/ ../../atd-d2d-integration/include)

#set include files: *.h, *.hpp, *.hh;
FILE(GLOB_RECURSE PROJECT_HEADERS "include/*.h" "include/*.hpp" "include/*.hh" "../include/*.h" "../include/*.hh" "../include/*.hpp")

#set source files:*.cpp, *.c, *.cc;
FILE(GLOB_RECURSE PROJECT_SOURCES "src/*.cpp" "src/*.c" "src/*.cc" "../src/*.cpp" "../src/*.cc" "../src/*.c")
#AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/src/ PROJECT_SOURCES)

#set library files: *.lib
FILE(GLOB_RECURSE PROJECT_LIBRARIES "lib/*.a")

#set library files path;
LINK_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/lib/)

#set library output directory;
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

#set executable output directory;
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#=================================================================


#set qt wrap files;
#=================================================================
#qt moc headers;
QT5_WRAP_CPP(PROJECT_MOC_HEADERS ${PROJECT_HEADERS})

#qt moc ui;
FILE(GLOB_RECURSE PROJECT_UIS "ui/*.ui")
QT5_WRAP_UI(PROJECT_MOC_UIS ${PROJECT_UIS})

#qt moc qrc;
FILE(GLOB_RECURSE PROJECT_QRCS "ui/*.qrc")
QT5_ADD_RESOURCES(PROJECT_MOC_QRCS ${PROJECT_QRCS})
#=================================================================


#build release executable and library
if(${CMAKE_BUILD_TYPE} MATCHES "RELEASE")
    #build executable
    ADD_EXECUTABLE(app_sys_chart ${PROJECT_SOURCES} ${PROJECT_HEADERS} ${PROJECT_MOC_UIS} ${PROJECT_MOC_UIS_HEADERS} ${PROJECT_MOC_QRCS})
    TARGET_LINK_LIBRARIES(app_sys_chart ${PROJECT_LIBRARIES} Qt5::Network Qt5::Widgets QGLViewer Qt5::Xml Qt5::OpenGL GL 3ds Qt5::Gui Qt5::PrintSupport lcm ${Boost_LIBRARIES} gthread-2.0 glib-2.0)

    #build library
    #ADD_LIBRARY(sys_chart STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/test.cpp)

    #install built executable and library;
    INSTALL(TARGETS app_sys_chart#chart
            #PERMISSIONS OWNER_EXECUTE
            RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../applications/bin#executable;
            ARCHIVE DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../applications/lib#dynamic lib, *.a;
            LIBRARY DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../applications/lib#static lib, *.so;
    )
#build debug executable and library
else()
    #build executable
    ADD_EXECUTABLE(app_sys_chart_d ${PROJECT_SOURCES} ${PROJECT_HEADERS} ${PROJECT_MOC_UIS} ${PROJECT_MOC_UIS_HEADERS} ${PROJECT_MOC_QRCS})
    TARGET_LINK_LIBRARIES(app_sys_chart_d ${PROJECT_LIBRARIES} Qt5::Network Qt5::Widgets QGLViewer Qt5::Xml Qt5::OpenGL GL 3ds Qt5::Gui Qt5::PrintSupport lcm ${Boost_LIBRARIES}gthread-2.0 glib-2.0)

    #build library
    #ADD_LIBRARY(chart_d STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/test.cpp)

    #install built executable and library;
    INSTALL(TARGETS app_sys_chart_d#chart_d
            #PERMISSIONS OWNER_EXECUTE
            RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../applications/bin#executable;
            ARCHIVE DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../applications/lib#dynamic lib, *.a;
            LIBRARY DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../applications/lib#static lib, *.so;
    )
endif()
