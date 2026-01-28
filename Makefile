all:
	g++ main.cpp list.cpp -o snake -g
	./snake
	make clean

clean:
	rm snake