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
	int i=0;
	for(it = m_products.beginn(); it!=m_products.end();it++){
		cout<<"     "<<m_products[i].getName()<<endl;
		i++;
	}
}
void Magasin::printInfo(string nameProduct){
	vector<Product*>::iterator it;
	int i=0;

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
        int i=0;

        for(it = m_products.beginn(); it!=m_products.end();it++){
                if(nameProduct == m_Products[i].getName()){
                        break;
                }
                i++;
        }
        m_products[i].setQuantity = quantity;
}
//question 5
void Magasin::addClient(Client* client){
	m_clients.push_back(client);
}
void Magasin::printAllClient(){
	vector<Client*>::iterator it;
	int i=0;
	for(it = m_clients.beginn(); it!=m_clients.end();it++)'
		cout<<"     "<<m_clients[i].getName()<<endl;
		i++;
	}
}
void Magasin::printClient(string nameClient){
	vector<Client*>::iterator it;
	int i=0;

	for(it = m_clients.beginn(); it!=m_clients.end();it++){
		if(m_clients[i].getName == nameClient){
			break
		}
		i++;
	}
	cout<<"nom: "<<m_client[i].getName()<<", ID: "<<m_client[i].getID()<<endl;
}
void Magasin::printClient(int idClient){
	vector<Client*>::iterator it;
	int i=0;

	for(it = m_clients.beginn();it!=m_clients.end();it++){
		if(m_clients[i].getID()==idClient){
			break;
		}
		i++;
	}
	cout<<"nom: "<<m_client[i].getName()<<", ID: "<<m_client[i].getID()<<endl;
}
void Magasin::addProductToPanier(string nameProduct, nameClient){
	vector<Client*>::iterator i1;
	vector<Product*>::iterator it2;
	i=0;
	j=0;
	for(it2=m_products.beginn();it2!=m_products.end();it2++){
		if(m_products[i].getName()==nameProducts){
			break;
		}
		i++;
	}
	for(it1=m_client.beginn();it1!=m_client.end();it1++){
		if(m_client[j].getName()==nameClient){
			break;
		}
		j++
	}
	m_client[j].addProduct(m_product[i]);
}
void Magasin::delProductOfPanier(string nameProduct, nameClient){
        vector<Client*>::iterator i2;
        vector<Product*>::iterator it1;
        i=0;
        j=0;
        for(it1=m_products.beginn();it1!=m_products.end();it1++){
                if(m_products[i].getName()==nameProducts){
                        break;
                }
                i++;
        }
        for(it2=m_client.beginn();it2!=m_client.end();it2++){
                if(m_client[j].getName()==nameClient){
                        break;
                }
                j++
        }
        m_client[j].deleteProduct(m_products[i]);
}

void Magasin::setQuantityOfPanier(string nameProduct, nameClient, int quantity){
        vector<Client*>::iterator i2;
        vector<Product*>::iterator it1;
        i=0;
        j=0;
        for(it1=m_products.beginn();it1!=m_products.end();it1++){
                if(m_products[i].getName()==nameProducts){
                        break;
                }
                i++;
        }
        for(it2=m_client.beginn();it2!=m_client.end();it2++){
                if(m_client[j].getName()==nameClient){
                        break;
                }
                j++
        }
	//à changer en fonction de la question 4
        m_client[j].changeQuantity(m_products[i],quantity);
}








