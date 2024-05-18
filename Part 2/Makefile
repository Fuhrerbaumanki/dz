# Название исполняемого файла
TARGET = program

# Список исходных файлов
SOURCES = main.cpp Application.cpp Hex.cpp Octal.cpp Array.cpp

# Компилятор и флаги компиляции
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

.PHONY: clean

clean:
	rm -f $(TARGET)
