# Compiler and flags for compiling the source code
CXX = g++
CXXFLAGS = -Wall -std=c++17
LDFLAGS = -lfltk -lfltk_images -lX11

# Target output file
TARGET = text_editor

# Source files and headers
SOURCES = src/main.cpp src/EditorWindow.cpp
HEADERS = src/EditorWindow.h

# Build the target from source files
$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET) $(LDFLAGS)

# Clean the build files
clean:
	rm -f $(TARGET)	# Remove the target executable
