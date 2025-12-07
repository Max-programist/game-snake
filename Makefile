all:
	g++ main.cpp list.cpp -o snake 
	./snake
	make clean

clean:
	rm snake