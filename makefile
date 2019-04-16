HEADERS = familyTree.h
OBJECTS = main.o familyTree.o
EXEC = Assignment3

$(EXEC): $(OBJECTS)
	g++ -Wall -std=c++11 $^ -o  $@

%.o: %.cpp $(HEADERS)
	g++ -Wall -c $< -o $@

run: $(EXEC)
	./$(EXEC) $(HEADERS) $(OBJECTS)
