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




