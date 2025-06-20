CXX = g++
CXXFLAGS = -std=c++17 -Wall \
	-I/usr/local/include \
	-Ilibs/imgui \
	-Ilibs/imgui-sfml

LDFLAGS = -L/usr/local/lib \
	-lsfml-graphics -lsfml-window -lsfml-system -lGL -lbox2d

SOURCES = \
	main.cpp \
	game.cpp \
	physics/physics.cpp \
	input/input_manager.cpp \
	debugger/debugger.cpp \
	ecs/ecs.cpp \
	engine/engine.cpp \
	libs/imgui/imgui.cpp \
	libs/imgui/imgui_draw.cpp \
	libs/imgui/imgui_tables.cpp \
	libs/imgui/imgui_widgets.cpp \
	libs/imgui/imgui_demo.cpp \
	libs/imgui-sfml/imgui-SFML.cpp

OBJECTS = $(SOURCES:.cpp=.o)
TARGET = main

all:
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET) $(OBJECTS)