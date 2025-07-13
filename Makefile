CC = g++-14
CFLAGS = -std=c++17 -Wall \
  -I/opt/homebrew/Cellar/glfw/3.4/include \
  -I/opt/homebrew/Cellar/glew/2.2.0_1/include

LDFLAGS = \
  -L/opt/homebrew/Cellar/glfw/3.4/lib \
  -L/opt/homebrew/Cellar/glew/2.2.0_1/lib \
  -lglfw -lGLEW \
  -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

SRC = src/App.cpp
OUT = app

all:
	$(CC) $(SRC) -o $(OUT) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(OUT)
