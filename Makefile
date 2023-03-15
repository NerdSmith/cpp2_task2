all: 
	clear
	g++ -O3 -g main.cpp component.cpp container_component.cpp -o main

clear:
	rm main