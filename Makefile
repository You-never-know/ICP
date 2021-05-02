all: build

.PHONY: build
BUILD_DIR = build/
QM = qmake
CC = g++


build: 
	cd $(BUILD_DIR) && $(QM) ../src/Microscopy.pro -spec linux-g++ CONFIG-=qml_debug CONFIG-=separate_debug_info  && make qmake_all && make -j8 && cd ..

clean:
	rm build/*
