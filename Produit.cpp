#include "Produit.h"

using namespace std;

string Produit::getName(){
	return m_name;
}
string Produit::getDescription(){
	return m_description;
}
int Produit::getQuantity(){
	return m_quantity;
}
float Produit::getPrice(){
	return m_price;
}

void Produit::setName(string name){
	m_name = name;
}

void Produit::setDescription(string description){
	m_description = description;
}

void Produit::setQuantity(int quantity){
	m_quantity = quantity;
}

void Produit::setPrice(float price){
	m_price = price;
}
Produit::Produit(string name, string description, int quantity, int price){
	m_name = name;
	m_description = description;
	m_quantity = quantity;
	m_price = price;
}
ostream& operator<<(ostream &flux, Produit *produit){

    flux<<"Nom: "<< produit->getName()<<"  description: "<< produit->getDescription()<<"   quantité disponible: "<<produit->getQuantity()<< "   Prix: "<< produit->getPrice()<<"€";

    return flux;

}
