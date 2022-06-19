/**
* @file			Node.cpp
* @description	Düğümün tanımlamalarının bulunduğu yer.
* @course		2-A
* @assignment	1.Odev
* @date			14.11.2021
* @author		Samet KARAKURT  samet.karakurt@ogr.sakarya.edu.tr
*/

#include "Node.hpp"
#include <iostream>
using namespace std;

Node::Node()
{
    this->data = "";
    this->next = NULL;
    this->prev = NULL;
}


Node::Node(string item ,Node* newNext, Node* newPrev)
{
	this->data = item;
	this->next = newNext;
	this->prev = newPrev;
}

