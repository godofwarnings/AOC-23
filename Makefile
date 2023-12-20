CXX = g++
# CXXFLAGS = -Wall -Wextra -fsanitize=address,undefined
CXXFLAGS = -fsanitize=address,undefined

# Replace 'test' with the name of your C++ source file (without the .cpp extension)
TARGET = q

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)