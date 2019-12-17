#include <string>
#include <vector>
#include "magasin.h"
#include "Produit.h"

using namespace std;

class Client{
 public:
 	Client(int id, string prenom, string nom, vector <Product*> panier);
 	int getId();
 	string getPrenom();
 	string getNom();
 	vector<Product*> getPanier();
 	void setPanier(vector<Product*> panier);
 	void setId(int id);
 	void setPrenom(string prenom);
 	void setNom(string nom);
 	void Client::addProduct(Product* products);
 	void Client::clearPanier();
 	void Client::changeQuantity(vector<Product*> quantity);
 	void Client::deleteProduct(Product* products);

 	friend ostream& operator<<(ostream &flux, Client *client);

 private:
 	int m_id;
 	string m_prenom;
 	string m_nom;
 	vector<Product*> m_panier;

 	
 }; 