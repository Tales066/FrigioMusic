# Nome do executável
TARGET = FrigioMusic

# Diretórios
SRC_DIR = src
EXEC_DIR = Executar
BUILD_DIR = build

# Fontes e objetos
SRCS = $(wildcard $(EXEC_DIR)/*.cpp)
OBJS = $(patsubst $(EXEC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Compilador
CXX = g++

# Flags comuns
INCLUDES = -I$(SRC_DIR)
CXXFLAGS_COMMON = -Wall -Wextra -std=c++17 $(INCLUDES)

# Flags para modos
CXXFLAGS_DEBUG = $(CXXFLAGS_COMMON) -g
CXXFLAGS_RELEASE = $(CXXFLAGS_COMMON) -O2

# Default: release
all: release

# Release build
release: CXXFLAGS = $(CXXFLAGS_RELEASE)
release: $(TARGET)

# Debug build
debug: CXXFLAGS = $(CXXFLAGS_DEBUG)
debug: $(TARGET)

# Executável
$(TARGET): $(OBJS)
	@echo "Linkando $(TARGET)..."
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilar cada .cpp em .o na pasta build/
$(BUILD_DIR)/%.o: $(EXEC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	@echo "Compilando $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza
clean:
	@echo "Limpando arquivos temporários..."
	rm -rf $(BUILD_DIR) $(TARGET)

# Recompilar completamente
rebuild: clean all

.PHONY: all release debug clean rebuild