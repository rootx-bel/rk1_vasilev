#include <iostream>
#include <cstring>
#include <clocale>
using namespace std;

int main(){
    char buffer[100];
    setlocale(LC_ALL,"ru");
    int size = 1;
    int counter = 0;
    char**zadacha = new char*[size];
    int*prior = new int[size];
    char**dedline = new char*[size];
    while(strcmp(buffer,"нет")!=0 or strcmp(buffer,"да")==0){
        cout << "Введите вашу задачу:" << endl;
        cin.getline(buffer,  100);
        zadacha[counter] = new char[strlen(buffer)];
        strcpy(zadacha[counter], buffer);
        cout << "Введите дедлайн:" << endl;
        cin.getline(buffer,  100);
        dedline[counter] = new char[strlen(buffer)];
        strcpy(dedline[counter], buffer);
        cout << "Введите приоритет(1-10):" << endl;
        cin >> prior[counter];
        cin.ignore();
        cout << "Задача добавлена" << endl;
        cout << "Дальше?(да/нет):" << endl;
        cin.getline(buffer, 100);
        counter++;
    }
    int temp;
    for (int i = 0; i<counter; ++i){
		for (int j = 0; j<counter-1; ++j){
			if (prior[j]>prior[j+1]){
                temp = prior[j];
				prior[j] = prior[j+1];
                prior[j+1] = temp;
				swap(zadacha[j], zadacha[j+1]);
				swap(dedline[j], dedline[j+1]);
			}
		}
	}
    for (int i = 0; i<counter; i++){
		cout  << i+1 << ". " << "Задача - " << zadacha[i] << " Дедлайн - " << dedline[i] << " Приоритет - " << prior[i] << endl; 
	}
}