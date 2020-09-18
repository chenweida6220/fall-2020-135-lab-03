main: main.o reservoir.o
	g++ -o main main.o reservoir.o

main.o: main.cpp reservoir.h
	g++ -c main.cpp

reservoir.o: reservoir.cpp reservoir.h
	g++ -c reservoir.cpp

reverseorder.io: reverseorder.cpp reverseorder.h
	g++ -c reverseorder.cpp

clean:
	rm -f main.o reservoir.o
