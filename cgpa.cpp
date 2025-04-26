#include<bits/stdc++.h>
using namespace std;

double CGPA(double sumOfGradeCredit,int TotalCredit) {
  try {
    if(TotalCredit == 0) {
      throw "Total credits cannot be zero";
    }
    else {
      return sumOfGradeCredit/TotalCredit;
    }
  } catch(string e) {
    cout<<e<<endl;
  }
}

int main() {
  double gradePoints;
  int credit,marks,totalCredit = 0,sum = 0;
  int totalNoOfSubjects;
  cout<<"Enter the total number of subjects: "<<endl;
  cin>>totalNoOfSubjects;
  string* arr = new string[totalNoOfSubjects];
  string subjects;
  cout<<"Enter All the subjects name : "<<endl;
  for(int i=0;i<totalNoOfSubjects;i++) {
    cin>>subjects;
    arr[i] = subjects;
  }
  cout<<"Please Enter the marks scored and credits allocated in All subjects: "<<endl;
  for(int i=0;i<totalNoOfSubjects;i++) {
    cout<<arr[i]<<" : "<<"[Marks (space) credit]";
    cin>>marks>>credit;
    if(marks > 100) {
      cout<<"Please enter the marks for 100"<<endl;
    }
    else if(marks >= 90) {
      gradePoints = 10;
    }
    else if(marks >= 80) {
      gradePoints = 9;
    }
    else if(marks >= 70) {
      gradePoints = 8;
    }
    else if(marks >= 60) {
      gradePoints = 7;
    }
    else if(marks >= 50) {
      gradePoints = 6;
    }
    else if(marks >= 40) {
      gradePoints = 5;
    }
    else if(marks < 40) {
      gradePoints = 0;
    }
    else {
      cout<<"Please enter the valid marks"<<endl;exit(1);
    }
    
    
    sum = sum + (gradePoints * credit);
    totalCredit = totalCredit + credit;
  }
  double cgpa = CGPA(sum,totalCredit);
  cout<<"Congrajulations!!! You scored "<<cgpa<<" CGPA"<<endl;
  return 0;
}