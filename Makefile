all: compiler

compiler: 
	mkdir -p build
	cd build && cmake ../ && make

.PHONY: clean
clean:
	rm -rf build
