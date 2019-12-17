#include "client.h"
#include "magasin.h"
#include "Produit.h"
#include <iostream>
using namespace std;

Client::Client(int id, string prenom, string nom, vector<Product*> panier){
	m_id = id;
	m_prenom = prenom;
	m_nom = nom;
	m_panier = panier;
}

int Client::getId(){
	return m_id;
}

string Client::getPrenom(){
	return m_prenom;
}

string Client::getNom(){
	return m_nom;
}

vector<Panier*> Client::getPanier(){
	return m_panier;
}

void Client::setId(int id){
	m_id = id;
}

void Client::setPrenom(string prenom){
	m_prenom = prenom;
}

void Client::setNom(string nom){
	m_nom = nom;
}

void Client::setPanier(vector<Product*> panier){
	m_panier = panier;
}

//Question 4.b
void Client::addProduct(Product* products){
	m_panier.push_back(products);
}

//Question 4.c
void Client::clearPanier(){
	m_panier.clear();

}

//Question 4.d
void Client::changeQuantity(vector<Product*> quantity){
	n = m_panier.size();
	
	cout << "Changer la quantité du produit numéro :" << endl;
	cin >> x;
	for (int i = 0; i < n; ++i)
	{
		if (i==x)
		{
			cout << "Nouvelle quantité!" << endl;
			cin>>q;
			q = quantity; 
		}
	}
}

//Question 4.e
void Client::deleteProduct(Product* products){
	n=m_panier.size();
	for (int i = 0; i < n; ++i)
	{
		if (n==x)
		{
			m_panier.erase(m_panier[x])
		}
	}
}

ostream& operator<<(ostream &flux, Client *client){

    flux<<"Nom: "<< client->getNom()<<"  Prenom: "<< client->getPrenom()<<"   Identifiant: "<<client->getId()<< "   Panier d'achat: "<< client->getPanier();

    return flux;

}