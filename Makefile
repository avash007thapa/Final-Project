#compile and link the application
all: main

#run the application
run: main
	./main

#link main.o and student.o internationalStudent.o domesticStudent.o toefl.o linkedList.o to executable main
main: main.o helper.o student.o internationalStudent.o domesticStudent.o toefl.o linkedList.o
	g++ -g -o main main.o helper.o student.o internationalStudent.o domesticStudent.o toefl.o linkedList.o

#compile the main.cpp to main.o
main.o: main.cpp
	g++ -g -c main.cpp -std=c++11

#compile the helper.cpp to helper.o
helper.o: helper.cpp
	g++ -g -c helper.cpp -std=c++11

#compile the linkedList.cpp to linkedList.o
linkedList.o: linkedList.cpp
	g++ -g -c linkedList.cpp -std=c++11

#compile the student.cpp to student.o
student.o: student.cpp
	g++ -g -c student.cpp -std=c++11

#compile the internationalStudent.cpp to internationalStudent.o
internationalStudent.o: internationalStudent.cpp
	g++ -g -c internationalStudent.cpp -std=c++11

#compile the domesticStudent.cpp to domesticStudent.o
domesticStudent.o: domesticStudent.cpp
	g++ -g -c domesticStudent.cpp -std=c++11

#compile the toefl.cpp to toefl.o
toefl.o: toefl.cpp
	g++ -g -c toefl.cpp -std=c++11

#remove built files
clean:
	del main.exe main.o helper.o student.o internationalStudent.o domesticStudent.o toefl.o linkedList.o main.exe *~
