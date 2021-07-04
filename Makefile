all: compiler

compiler: 
	mkdir -p build
	cd build && cmake ../ && make
