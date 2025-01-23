build:
	mkdir -p ./src/bin && g++ -std=c++2b -L ../include -fPIC -shared ./src/script.cpp -o ./src/bin/index.so