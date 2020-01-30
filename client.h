
#ifndef DEF_CLIENT
#define DEF_CLIENT

#include <string>
#include <vector>
#include <iostream>
#include "produit.h"

using namespace std;

class Client{
 public:
 	Client(int id, string prenom, string nom, vector <Product*> panier);
 	int getId();
 	string getPrenom();
 	string getNom();
 	vector<Product*> getPanier();
 	vector<int> getIdOrder();
 	
 	void setPanier(vector<Product*> panier);
 	void setId(int id);
 	void setPrenom(string prenom);
 	void setNom(string nom);
 	void addOrder(int idOrder);
 	void addProduct(Product *products, int quantity);
 	void clearPanier();
 	void changeQuantity(int quantity, string name);
 	void deleteProduct(string name);
 	void printPanier();
 	int getQuantity(string name);

 	friend ostream& operator<<(ostream &flux, Client *client);
 	
 private:
 	int m_id;
 	vector<int> m_idOrder;
 	string m_prenom;
 	string m_nom;
 	vector<Product*> m_panier;

 }; 
#endif
