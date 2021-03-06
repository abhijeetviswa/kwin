if (XCB_ICCCM_FOUND)
    set(normalhintsbasesizetest_SRCS normalhintsbasesizetest.cpp)
    add_executable(normalhintsbasesizetest ${normalhintsbasesizetest_SRCS})
    target_link_libraries(normalhintsbasesizetest XCB::XCB XCB::ICCCM KF5::WindowSystem)
endif()

# next target
set(screenedgeshowtest_SRCS screenedgeshowtest.cpp)
add_executable(screenedgeshowtest ${screenedgeshowtest_SRCS})
target_link_libraries(screenedgeshowtest Qt::Widgets Qt::X11Extras KF5::ConfigCore KF5::WindowSystem KF5::WaylandClient ${XCB_XCB_LIBRARY})
target_include_directories(screenedgeshowtest PRIVATE ${CMAKE_SOURCE_DIR}/src)

set(libinputtest_SRCS
    ${KWin_SOURCE_DIR}/src/libinput/connection.cpp
    ${KWin_SOURCE_DIR}/src/libinput/context.cpp
    ${KWin_SOURCE_DIR}/src/libinput/device.cpp
    ${KWin_SOURCE_DIR}/src/libinput/events.cpp
    ${KWin_SOURCE_DIR}/src/libinput/libinput_logging.cpp
    ${KWin_SOURCE_DIR}/src/logind.cpp
    ${KWin_SOURCE_DIR}/src/udev.cpp
    libinputtest.cpp
)
add_executable(libinputtest ${libinputtest_SRCS})
add_definitions(-DKWIN_BUILD_TESTING)
target_link_libraries(libinputtest Qt::Core Qt::DBus Libinput::Libinput UDev::UDev KF5::ConfigCore KF5::GlobalAccel KF5::WindowSystem)
target_include_directories(libinputtest PRIVATE ${CMAKE_SOURCE_DIR}/src)

add_executable(x11shadowreader x11shadowreader.cpp)
target_link_libraries(x11shadowreader XCB::XCB Qt::Widgets Qt::X11Extras KF5::ConfigCore KF5::WindowSystem)
target_include_directories(x11shadowreader PRIVATE ${CMAKE_SOURCE_DIR}/src)

add_executable(pointerconstraints pointerconstraintstest.cpp)
add_definitions(-DDIR="${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(pointerconstraints XCB::XCB Qt::Gui Qt::Quick KF5::WaylandClient)

add_executable(pointergestures pointergesturestest.cpp)
add_definitions(-DDIR="${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(pointergestures Qt::Gui Qt::Quick KF5::WaylandClient)

add_executable(cursorhotspottest cursorhotspottest.cpp)
target_link_libraries(cursorhotspottest Qt::Widgets)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
