/**
* @file			Node.hpp
* @description	Node Class'ı burada bulunur
* @course		2-A
* @assignment	1.Odev
* @date			14.11.2021
* @author		Samet KARAKURT  samet.karakurt@ogr.sakarya.edu.tr
*/

#ifndef NODE_HPP_
#define NODE_HPP_
#include <iostream>
using namespace std;

class Node{
    public:
		string data;
		Node *next, *prev;
		Node();
		Node(string item ,Node* newNext, Node* newPrev);
};

#endif