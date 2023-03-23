all: 
	clear
	g++ -O3 -g main.cpp component.cpp container_component.cpp frame.cpp label.cpp clickable.cpp button.cpp list_component.cpp panel.cpp -o main

clear:
	rm main