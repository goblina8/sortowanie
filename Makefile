CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++17

__start__: projekt2
	./projekt2

projekt2: obj obj/main.o obj/functions.o obj/scalanie.o obj/quicksort.o obj/kubelkowe.o 
	g++ -Wall -pedantic -std=c++0x -o projekt2 obj/main.o obj/functions.o obj/scalanie.o obj/quicksort.o obj/kubelkowe.o -lpthread
	
obj:
	mkdir obj
	
obj/main.o: src/main.cpp inc/functions.hh 
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/functions.o: src/functions.cpp inc/functions.hh inc/scalanie.hh inc/quicksort.hh inc/kubelkowe.hh
	g++ -c ${CXXFLAGS} -o obj/functions.o src/functions.cpp

obj/scalanie.o: src/scalanie.cpp inc/scalanie.hh 
	g++ -c ${CXXFLAGS} -o obj/scalanie.o src/scalanie.cpp

obj/quicksort.o: src/quicksort.cpp inc/quicksort.hh 
	g++ -c ${CXXFLAGS} -o obj/quicksort.o src/quicksort.cpp

obj/kubelkowe.o: src/kubelkowe.cpp inc/kubelkowe.hh 
	g++ -c ${CXXFLAGS} -o obj/kubelkowe.o src/kubelkowe.cpp

clean:
	rm -f obj/*.o projekt2
