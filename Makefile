play:
	g++ -std=c++17 VerletIntegration/main.cpp VerletIntegration/window.cpp VerletIntegration/renderer.cpp VerletIntegration/physics.cpp -o play -I Include -L Lib -l SDL2-2.0.0 -framework OpenGL
