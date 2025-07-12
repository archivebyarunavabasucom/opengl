CC = clang++
CFLAGS = -std=c++17 -Wall -I/opt/homebrew/Cellar/glfw/3.4/include
LDFLAGS = -L/opt/homebrew/Cellar/glfw/3.4/lib -lglfw -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

SRC = src/App.cpp
OUT = app

all:
	$(CC) $(SRC) -o $(OUT) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(OUT)
