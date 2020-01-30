
#include "produit.h"

Product::Product(string title, string desc, int quantity, double price){
	m_title = title;
	m_desc = desc;
	m_quantity = quantity;
	m_price = price;
}

string Product::getTitle(){
	return m_title;
}

string Product::getDesc(){
	return m_desc;
}

int Product::getQuantity(){
	return m_quantity;
}

double Product::getPrice(){
	return m_price;
}

void Product::setQuantity(int newQuantity){
	m_quantity = newQuantity;
}

ostream& operator<<(ostream &flux, Product *produit){
    flux<<"Nom: "<< produit->getTitle()<<"  description: "<< produit->getDesc()<<"   quantité: "<<produit->getQuantity()<< "   Prix: "<< produit->getPrice()<<"€"<<endl;
    return flux;
}
