kmeans: parser.o main.o kmeans.o sample.o
	g++ -O2 -g -std=c++11 parser.o main.o kmeans.o sample.o -o kmeans

parser.o: parser.cc parser.h
	g++ -O2 -g -std=c++11 -c parser.cc -o parser.o

sample.o: sample.cc sample.h
	g++ -O2 -g -std=c++11 -c sample.cc -o sample.o

kmeans.o: kmeans.cc kmeans.h
	g++ -O2 -g -std=c++11 -c kmeans.cc -o kmeans.o

main.o: main.cc
	g++ -O2 -g -std=c++11 -c main.cc -o main.o

clean:
	rm *.o kmeans
