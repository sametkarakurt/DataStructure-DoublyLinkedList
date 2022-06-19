/**
* @file			main.cpp
* @description	Programı başlatan yer..
* @course		2-A
* @assignment	1.Odev
* @date			14.11.2021
* @author		Samet KARAKURT  samet.karakurt@ogr.sakarya.edu.tr
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include "DoublyLinkedList.hpp"
using namespace std;

//Verinin uzunluğunu bulur.
int findLength(int startingIndex,int objectOfLoop ,string row,char character){
    for(int x = startingIndex; row[x] != character;x++){
            objectOfLoop++;
    }
    return objectOfLoop;
}

int main()
{
    DoublyLinkedList* list = new DoublyLinkedList();
    ifstream file;
    file.open("Commands.txt");
    string row;
    
    //Txt dosyasını okur.
    while(getline(file,row))
	{
        //Satırdaki index
        int index = 0;
        //İndexin uzunluğu
        int indexLength = 0;
        //Satırdaki veri
        string data;
        // 
        int dataLength = 0;

        //Ekleme işlemini başlatır.
        if(row[0] == 'E'){
            indexLength = findLength(2,indexLength,row,'#');
            dataLength = findLength(3+indexLength,dataLength,row,')');
            data = row.substr(3+indexLength,dataLength);
            index = stoi(row.substr(2,indexLength));
            list->insert(index,data);

        }else{
            //Silme işlemini başlatır.
            indexLength = findLength(2,indexLength,row,')');
            index = stoi(row.substr(2,indexLength));
            list->remove(index);
        }

	}

    //Bütün verileri ekrana yazar.
    list->print();

    delete list;
}














