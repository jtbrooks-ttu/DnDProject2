
output: driver.cpp Character.h LinkedList.tpp LinkedList.h
	g++ -c driver.cpp -o output

clean:
	rm *.o output


