CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -g

SRCS = Die.cpp Game.cpp Idol.cpp Jungle.cpp Linked.cpp mainGame.cpp Space.cpp Temple.cpp Utilities.cpp 
HDRS = Utilities.hpp Die.hpp Game.hpp Idol.hpp Jungle.hpp Linked.hpp Space.hpp Temple.hpp 

Final: ${SRCS} ${HDRS}
	${CXX} ${CXXFLAGS} ${SRCS} -o Final

clean:
	rm Final
