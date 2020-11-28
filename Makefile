#compile and link the application
all: main

#run the application
run: main
	./main

#link to executable main
main: main.o studentList.o domStuList.o toefl.o
	g++ -g -o main main.o studentList.o domStuList.o toefl.o

#compile the main.cpp to main.o
main.o: main.cpp
	g++ -g -c main.cpp -std=c++11

#compile the student.cpp to student.o
studentList.o: studentList.cpp
	g++ -g -c studentList.cpp -std=c++11

# #compile the internationalStudent.cpp to internationalStudent.o
# internationalStudent.o: internationalStudent.cpp
# 	g++ -g -c internationalStudent.cpp -std=c++11

#compile the domesticStudent.cpp to domesticStudent.o
domStuList.o: domStuList.cpp
	g++ -g -c domStuList.cpp -std=c++11

#compile the toefl.cpp to toefl.o
toefl.o: toefl.cpp
	g++ -g -c toefl.cpp -std=c++11

#remove built files
clean:
	del main.exe studentList.exe main.o studentList.o domStuList.o toefl.o *~
