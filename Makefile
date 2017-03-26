TARGET_NAME = gureyuu
CXX = clang++
CXXFLAGS = -Wall -Wextra -std=c++14 -O2

LDFLAGS = -L../mikayuu/build/
ifeq ($(OS), Windows_NT)
	LIBS = -lmikayuu -lglfw -lopengl32 -lglu32
else
	LIBS = -lmikayuu -lglfw -lGL -lGLU
endif

INCLUDE = -I./include -I../mikayuu

SRCDIR = ./src
SRC = $(wildcard $(SRCDIR)/*.cpp)

BUILD_DIR = ./build
TARGET = $(BUILD_DIR)/$(TARGET_NAME)

OBJ = $(addprefix $(BUILD_DIR)/obj/, $(notdir $(SRC:.cpp=.o)))
DEPEND = $(OBJ:.o=.d)

all: $(TARGET)

-include $(DEPEND)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS) $(LIBS)


$(BUILD_DIR)/obj/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c -MMD -MP $<


.PHONY: clean
clean:
	-rm -f $(OBJ) $(DEPEND) $(TARGET)

run: $(TARGET)
	$(TARGET)

