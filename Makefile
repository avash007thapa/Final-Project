#compile and link the application
all: main

#run the application
run: main
	./main

#link main.o and student.o internationalStudent.o domesticStudent.o toefl.o to executable main
main: main.o student.o internationalStudent.o internationalStudentNode.o domesticStudent.o domesticStudentNode.o toefl.o studentNode.o 
	g++ -g -o main main.o student.o internationalStudent.o internationalStudentNode.o domesticStudent.o domesticStudentNode.o toefl.o studentNode.o

#compile the main.cpp to main.o
main.o: main.cpp
	g++ -g -c main.cpp -std=c++11

#compile the student.cpp to student.o
student.o: student.cpp
	g++ -g -c student.cpp -std=c++11

#compile the internationalStudent.cpp to internationalStudent.o
internationalStudent.o: internationalStudent.cpp
	g++ -g -c internationalStudent.cpp -std=c++11

#compile the internationalStudent.cpp to internationalStudent.o
internationalStudentNode.o: internationalStudentNode.cpp
	g++ -g -c internationalStudentNode.cpp -std=c++11

#compile the domesticStudent.cpp to domesticStudent.o
domesticStudent.o: domesticStudent.cpp
	g++ -g -c domesticStudent.cpp -std=c++11

#compile the domesticStudent.cpp to domesticStudent.o
domesticStudentNode.o: domesticStudentNode.cpp
	g++ -g -c domesticStudentNode.cpp -std=c++11

#compile the toefl.cpp to toefl.o
toefl.o: toefl.cpp
	g++ -g -c toefl.cpp -std=c++11

#compile the node.cpp to domesticStudent.o
node.o: studentNode.cpp
	g++ -g -c studentNode.cpp -std=c++11

#remove built files
clean:
	del main.exe main.o student.o internationalStudent.o internationalStudentNode.o domesticStudent.o domesticStudentNode.o toefl.o studentNode.o *~
