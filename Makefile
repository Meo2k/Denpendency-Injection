CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -m64 -g

SRC := $(shell find src -name "*.cpp") $(wildcard *.cpp)
OBJ := $(patsubst %.cpp, bin/%.o, $(SRC))

INCLUDE := -Iinclude
TARGET := dependency_inject

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile, tự tạo thư mục trong bin/ tương ứng
bin/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@


run: $(TARGET)
	@xfce4-terminal --hold --command "./$(TARGET)" 

clean:
	rm -rf $(OBJ) $(TARGET)

# $^ : danh sách file phụ thộc 
# $< : file phụ thuộc 
# $@ : danh sách file mục tiêu  
# patsubst : pattern substitution (thay thế theo mẫu ) 
