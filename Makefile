CC = g++
BUILD_FLAGS = -I Include -L Lib -l SDL2-2.0.0 -framework OpenGL
COMPILE_FLAGS = -I Include


play.out: build/main.o build/window.o build/renderer.o build/physics.o
	${CC} -std=c++17 build/main.o build/window.o build/renderer.o build/physics.o -o play.out ${BUILD_FLAGS}
	chmod +x play.out

build/main.o: src/main.cpp
	${CC} -std=c++17 -c src/main.cpp -o main.o ${COMPILE_FLAGS}
	mv main.o build

build/window.o: src/window.cpp
	${CC} -std=c++17 -c src/window.cpp -o window.o ${COMPILE_FLAGS}
	mv window.o build

build/renderer.o: src/renderer.cpp
	${CC} -std=c++17 -c src/renderer.cpp -o renderer.o ${COMPILE_FLAGS}
	mv renderer.o build

build/physics.o: src/physics.cpp
	${CC} -std=c++17 -c src/physics.cpp -o physics.o ${COMPILE_FLAGS}
	mv physics.o build
