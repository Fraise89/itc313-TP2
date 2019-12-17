#include "magasin.h"

Magasin::Magasin(vector<Product*> products, vector<Client*> clients, vector<Order*> m_orders){
	m_products = products;
	m_clients = clients;
	m_orders = orders;
}

vector<Product*> Magasin::getProducts(){
	return m_products;
}
vector<Client*> Magasin::getClients(){
        return m_clients;
}

vector<Order*> Magasin::getOrder(){
        return m_orders;
}

void Magasin::setProducts(vector<Product*> products){
	m_product = products;
}
void Magasin::setClients(vector<Client*> clients){
        m_clients = clients;
}
void Magasin::setOrders(vector<Order*> orders){
        m_orders = orders;
}
//question 3a
void Magasin::addProduct(Product* products){
	m_products.push_back(products);
}
//question 3b
void Magasin::printAllProduct(){
	vector<Product*>::iterator it;
	int i;
	for(it = m_products.beginn(); it!=m_products.end();it++){
		cout<<"     "<<m_products[i].getName()<<endl;
		i++;
	}
}
void Magasin::printInfo(string nameProduct){
	vector<Product*>::iterator it;
	int i;

	for(it = m_products.beginn(); it!=m_products.end();it++){
		if(nameProduct == m_Products[i].getName()){
			break;
		}
		i++;
	}
	cout<<"Nom du produit: "<<m_products[i].getName()<<", Description: "<<m_products[i].getDescription()<<", Quantité disponible: "<<m_products[i].getQuantity()<<", prix: "<<m_products[i].getPrice()<<endl;
}
void Magasin::UpdateQuantityProduct(string NameProduct, int quantity){
	vector<Product*>::iterator it;
        int i;

        for(it = m_products.beginn(); it!=m_products.end();it++){
                if(nameProduct == m_Products[i].getName()){
                        break;
                }
                i++;
        }
        m_products[i].setQuantity = quantity;
}
