#include"project.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main() {
    createDataBase("Info.csv");
    ListEmployee* ls = emptyList();
    welcomePage();
    mainLogin(ls);

    return 0;
}

