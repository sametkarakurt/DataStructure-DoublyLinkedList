/**
* @file			DoublyLinkedList.cpp
* @description	İki yönlü bağıl listenin metodlarının tanımlamalarının bulunduğu yer.
* @course		2-A
* @assignment	1.Odev
* @date			14.11.2021
* @author		Samet KARAKURT  samet.karakurt@ogr.sakarya.edu.tr
*/

#include "DoublyLinkedList.hpp"
#include "iomanip"
#include <string>
using namespace std;


DoublyLinkedList::DoublyLinkedList()
{
    this->head = NULL;
    this->size = 0;
}

DoublyLinkedList::~DoublyLinkedList(){
    Node* temp = head;

    //Liste sonuna kadar ilerler.
    while(temp!=NULL){
        
        Node* deletedItem = temp;

        temp = temp->next;

        delete deletedItem;
        
    }

}

//Verilen indexteki düğümü döndürür.
Node* DoublyLinkedList::FindPreviousByPosition(int index){
    int i=1;
    Node *prv = head;
    //İstenilen indexteki düğümü bulana kadar ilerler.
	for(Node *itr = head; itr->next != NULL && i != index; itr=itr->next,i++){
		prv = prv->next;
	}
	return prv;

}

//İki yönlü bağıl listeye ekleme yapar.
void DoublyLinkedList::insert(int index ,string item){
  
    //Liste boş değilse
    if(size != 0){
        if(index >= size || index<0){
            Node *prv = FindPreviousByPosition(size);
            prv->next = new Node(item,NULL,prv);
            size++;

        }else{
            //Sona düğüm eklenir ve bir öncekinin datası ona aktarıldı.
            Node *prv = FindPreviousByPosition(size);
            prv->next = new Node(prv->data,NULL,prv);
            size++;

            //Düğümdeki veriler ilerisindeki düğüme aktarılıyor.
            Node* prv2 =FindPreviousByPosition(size);
            for(int i=2;i<(size-index);i++){
            
                prv2 = prv2->prev;
                prv2->data = prv2->prev->data;
                
            }
            prv2->prev->data = item;       
        }
 
        
    }else{
        //Liste boş olduğundan listenin başına ekler
        head = new Node(item,NULL,NULL);;
        size++;

    }

}
//İki yönlü bağıl listeden eleman siler.
void DoublyLinkedList::remove(int index){
    
    index ++ ;

    //Listede tek eleman varsa baştaki elemanı siler.
    if(head->next == NULL){
        delete head;
        size--;
        head = NULL;
    }
     //Liste boş değilse
    if(size != 0){

        //Girilen index yok ise listenin sonundan siler.
        if(index >= size || index<=0){
            Node *prv = FindPreviousByPosition(size);
            delete prv;
            prv->prev->next = 0;
            size--;
        }else{
                  
            Node* prv2 =FindPreviousByPosition(index);
            //Silinecek düğümün verisine soldaki düğümün verisi aktarılır.
            for(int i=0;i<(size-index);i++){
                prv2->data = prv2->next->data;
                prv2 = prv2->next;                    
            }

            //Sondaki eleman silindi.
            Node* deletedItem = FindPreviousByPosition(size);
            delete deletedItem;
            deletedItem->prev->next = 0;  
            size--;
        }
   
    }

}

//Liste elemanlarını ekrana yazar.
void DoublyLinkedList::print(){

    Node* temp = head;

    //Liste sonuna kadar ilerler.
    while(temp!=NULL){
        
        if(temp != head){
            cout << " <--> ";
        }
        
        cout <<temp->data;
        temp = temp->next;
        
    }
    cout <<endl;
}
    

