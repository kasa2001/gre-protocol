cmake_minimum_required(VERSION 3.19)
project(GRE)

set(CMAKE_CXX_STANDARD 14)

add_executable(GRE main.cpp src/cpp/GRE.cpp src/hpp/GRE.h src/cpp/Conetion.cpp src/hpp/Conetion.h src/cpp/Image.cpp src/hpp/Image.h src/cpp/addElement.cpp src/hpp/addElement.h src/cpp/Other.cpp src/hpp/Other.h src/cpp/Simulation.cpp src/hpp/Simulation.h  src/cpp/Router.cpp src/hpp/Router.h src/cpp/Network.cpp src/hpp/Network.h src/cpp/package/Package.cpp src/hpp/package/Package.h src/cpp/Transport.cpp src/hpp/Transport.h src/cpp/package/StartControlConnecting.cpp src/hpp/package/StartControlConnecting.h src/cpp/package/StartControlConnectingReply.cpp src/hpp/package/StartControlConnectingReply.h src/cpp/package/OutgoingCallRequest.cpp src/hpp/package/OutgoingCallRequest.h src/cpp/package/OutgoingCallReply.cpp src/hpp/package/OutgoingCallReply.h src/cpp/package/IncomingCallRequest.cpp src/hpp/package/IncomingCallRequest.h src/cpp/package/IncomingCallReply.cpp src/hpp/package/IncomingCallReply.h src/cpp/package/IncomingCallConnected.cpp src/hpp/package/IncomingCallConnected.h src/cpp/package/EchoRequest.cpp src/hpp/package/EchoRequest.h src/cpp/package/EchoReply.cpp src/hpp/package/EchoReply.h src/cpp/package/StopControlConnectionRequest.cpp src/hpp/package/StopControlConnectionRequest.h src/cpp/package/StopControlConnectionReply.cpp src/hpp/package/StopControlConnectionReply.h src/cpp/package/PackageFactory.cpp src/hpp/package/PackageFactory.h src/cpp/exception/CannotCreatePackage.cpp src/hpp/exception/CannotCreatePackage.h src/cpp/routerFunction.cpp src/hpp/routerFunction.h src/cpp/package/NoResponseServer.cpp src/hpp/package/NoResponseServer.h)

if (WIN32)
    target_link_libraries(GRE wsock32 ws2_32)
endif ()