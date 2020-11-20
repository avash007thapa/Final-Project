#compile and link the application
all: main

#run the application
run: main
	./main

#link main.o and student.o internationalStudent.o domesticStudent.o toefl.o to executable main
main: main.o studentList.o toefl.o
	g++ -g -o main main.o studentList.o toefl.o

#compile the main.cpp to main.o
main.o: main.cpp
	g++ -g -c main.cpp -std=c++11

#compile the student.cpp to student.o
studentList.o: studentList.cpp
	g++ -g -c studentList.cpp -std=c++11

# #compile the internationalStudent.cpp to internationalStudent.o
# internationalStudent.o: internationalStudent.cpp
# 	g++ -g -c internationalStudent.cpp -std=c++11

# #compile the domesticStudent.cpp to domesticStudent.o
# domesticStudent.o: domesticStudent.cpp
# 	g++ -g -c domesticStudent.cpp -std=c++11

#compile the toefl.cpp to toefl.o
toefl.o: toefl.cpp
	g++ -g -c toefl.cpp -std=c++11

#compile the node.cpp to domesticStudent.o
node.o: studentNode.cpp
	g++ -g -c studentNode.cpp -std=c++11

#remove built files
clean:
	del main.exe main.o studentList.o toefl.o studentNode.o *~
