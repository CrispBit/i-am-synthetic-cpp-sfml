.PHONY: clean

linux: $(wildcard *.cpp)
	g++ -std=c++14 -v -lGLEW -lGL -lboost_filesystem -lboost_system -lyaml-cpp -lsfml-window -lsfml-system -lsfml-audio -lsfml-graphics -lassimp src/*.cpp src/*/*.cpp src/*/*/*.cpp -o bin/i-am-synthetic

clean:
	rm -f bin/i-am-synthetic
