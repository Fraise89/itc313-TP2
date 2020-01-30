
#include "client.h"
#include "produit.h"

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

vector<Product*> Client::getPanier(){
	return m_panier;
}

void Client::setId(int id){
	m_id = id;
}

void Client::addOrder(int idOrder){
	m_idOrder.push_back(idOrder);
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

void Client::printPanier(){
	int i = 0;
	vector<Product*>::iterator it;
	for(it=m_panier.begin(); it!=m_panier.end(); it++){
		cout<<"x"<<m_panier[i]->getQuantity()<<" "<<m_panier[i]->getTitle()<<endl;
	}
}
int Client::getQuantity(string name){
	vector<Product*>::iterator it;
	int i = 0;
	for(it=m_panier.begin(); it!=m_panier.end();it++){
		if(m_panier[i]->getTitle() == name){
			return m_panier[i]->getQuantity();
		}

		i++;
	}
	return -1;
}
//Question 4.b
void Client::addProduct(Product *products, int quantity){
	Product *newProducts = new Product(products->getTitle(), products->getDesc(), quantity, products->getPrice());
	m_panier.push_back(newProducts);
}

//Question 4.c
void Client::clearPanier(){
	m_panier.clear();

}
vector<int> Client::getIdOrder(){
	return m_idOrder;
}

//Question 4.d
void Client::changeQuantity(int quantity, string name){

	vector<Product*>::iterator it;
	int i=0;
    for(it = m_panier.begin(); it!=m_panier.end();it++){
            if(name == m_panier[i]->getTitle()){
                    break;
            }
            i++;
    }
    if(m_panier[i]->getTitle() == name){
    	m_panier[i]->setQuantity(quantity);
    }else{
    	cout<<"Ce produit n'est pas dans votre panier !"<<endl;
    }
}
//Question 4.e
void Client::deleteProduct(string name){

	vector<Product*>::iterator it;
	int i=0;
    for(it = m_panier.begin(); it!=m_panier.end();it++){
            if(name == m_panier[i]->getTitle()){
                    break;
            }
            i++;
    }
    if(m_panier[i]->getTitle() == name){
    	m_panier.erase(m_panier.begin()+i);
    }else{
    	cout<<"Ce produit n'est pas dans votre panier !"<<endl;
    }
}

ostream& operator<<(ostream &flux, Client *client){
		 flux<<"========================================================================================================================"<<endl;
 		 flux<<"Nom: "<< client->getNom()<<"  Prenom: "<< client->getPrenom()<<"   Identifiant: "<<client->getId()<< "   Panier d'achat: "<<endl;
 		 int i = 0;
 		 vector<Product*>::iterator it;
 		 for(it=client->getPanier().begin(); it!=client->getPanier().end();it++){
 		 	flux<<"	"<<client->getPanier()[i];
 		 	i++;
 		 }
 		 flux<<"========================================================================================================================"<<endl;
    	return flux;
}
