/**
* @file			DoublyLinkedList.hpp
* @description	DoublyLinkedList Class'ı burada bulunur.
* @course		2-A
* @assignment	1.Odev
* @date			14.11.2021
* @author		Samet KARAKURT  samet.karakurt@ogr.sakarya.edu.tr
*/

#ifndef DOUBLYLINKEDLIST_HPP_
#define DOUBLYLINKEDLIST_HPP_
#include "Node.hpp"
#include <iostream>
using namespace std;

	class DoublyLinkedList
	{
		public:
		    Node* head;
            int size;
        	DoublyLinkedList();
			~DoublyLinkedList();
			Node* FindPreviousByPosition(int index);
			void insert(int index, string item);
			void remove(int index);
			void print();

	};

#endif