.PHONY: all clean

GCC := g++

FLAGS := -I./include/ -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

BUILD_DIR   := build
SRC_DIR     := src
INCLUDE_DIR := include

SRC_FILES = $(SRC_DIR)/List.cpp $(SRC_DIR)/main.cpp $(SRC_DIR)/InitDtor.cpp $(SRC_DIR)/FillHashTable.cpp
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES))

TARGET := $(BUILD_DIR)/hash_table.out

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(GCC) $(OBJ_FILES) -o $@ $(FLAGS)


$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDE_DIR)/*.h
	$(GCC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)/ *.o *.out
