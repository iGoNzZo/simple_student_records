#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct StudentInfo	{
	string name;
	int grade;
};

StudentInfo calcMin(vector<StudentInfo> info)	{
	StudentInfo temp;
	StudentInfo minner;
	vector<StudentInfo>:: iterator p;
	int tempMin = 100;
	
	for(p = info.begin(); p != info.end(); p++)	{
		temp = *p;
		if(temp.grade < tempMin)	{
			tempMin = temp.grade;
			minner = temp;
		}
	}
	
	return minner;
}

StudentInfo calcMax(vector<StudentInfo> info)	{
	StudentInfo temp;
	StudentInfo maxxer;
	vector<StudentInfo>:: iterator p;
	int tempMax = 0;
	
	for(p = info.begin(); p != info.end(); p++)	{
		temp = *p;
		if(temp.grade > tempMax)	{
			tempMax = temp.grade;
			maxxer = temp;;
		}
	}
	
	return maxxer;
}

double calcAverage(vector<StudentInfo> info)	{
	StudentInfo temp;
	vector<StudentInfo>:: iterator p;
	int total = 0;
	int numStudents = 0;
	
	for(p = info.begin(); p != info.end(); p++)	{
		temp = *p;
		total = total + temp.grade;
		numStudents++;
	}
	
	double ave = total/(numStudents * 100.0);

	return ave;
}

void printer(vector<StudentInfo> info)	{
	StudentInfo temp;
	vector<StudentInfo>:: iterator p;
	cout << "\nNAME ------ GRADE" << endl;
	for(p = info.begin(); p != info.end(); p++)	{
		temp = *p;
		cout << temp.name << "\t\t" << temp.grade << endl;
	}
}

bool sorter(const StudentInfo& a, const StudentInfo& b)	{
	string one = a.name;
	string two = b.name;
	
	string sOne = one.substr(0, 1);
	string sTwo = two.substr(0, 1);
	
	return sOne < sTwo;
}

int main()	{
	vector<StudentInfo> container;
	
	StudentInfo record1;
	cout << "\tEnter name for student 1: ";
	cin >> record1.name;
	cout << "\tEnter Student 1's grade in percent: ";
	cin >> record1.grade;
	container.push_back(record1);
	
	StudentInfo record2;
	cout << "\tEnter name for student 2: ";
	cin >> record2.name;
	cout << "\tEnter grade for student 2 in percent: ";
	cin >> record2.grade;
	container.push_back(record2);
	
	StudentInfo record3;
	cout << "\tEnter name for student 3: ";
	cin >> record3.name;
	cout << "\tEnter student 3's grade in percent: ";
	cin >> record3.grade;
	container.push_back(record3);
	
	StudentInfo record4;
	cout << "\tEnter name for student 4: ";
	cin >> record4.name;
	cout << "\tEnter student 4's grade in percent: ";
	cin >> record4.grade;
	container.push_back(record4);
	
	StudentInfo record5;
	cout << "\tEnter name for student 5: ";
	cin >> record5.name;
	cout << "\tEnter student 5's grade in percent: ";
	cin >> record5.grade;
	container.push_back(record5);
	
	StudentInfo record6;
	cout << "\tEnter name for student 6: ";
	cin >> record6.name;
	cout << "\tEnter student 6's grade in percent: ";
	cin >> record6.grade;
	container.push_back(record6);	
	
	sort(container.begin(), container.end(), sorter);
	
	cout << "\nClass Minimum Grade: " << calcMin(container).grade << endl;
	cout << "Class Maximum Grade: " << calcMax(container).grade << endl;
	cout << "Class Average Grade: " << calcAverage(container) << endl;
	
	printer(container);
}