
#include "magasin.h"

Magasin::Magasin(vector<Product*> products, vector<Client*> clients, vector<Order*> orders){
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
vector<Order*> Magasin::getOrders(){
	return m_orders;
}
void Magasin::setProducts(vector<Product*> products){
	m_products = products;
}
void Magasin::setClients(vector<Client*> clients){
	m_clients = clients;
}
void Magasin::setOrders(vector<Order*> orders){
	m_orders = orders;
}

void Magasin::addProduct(Product *products){
	m_products.push_back(products);
}
//affiche les produit du magasin
void Magasin::printProducts(){
	vector<Product*>::iterator it;
	int i=0;
	for(it = m_products.begin(); it!=m_products.end();it++){
		//cout<<"     "<<m_products[i]->getTitle()<<endl;
		cout<<m_products[i];
		i++;
	}
}
//affiche un produit du magasin
void Magasin::printProduct(string nameProduct){
	vector<Product*>::iterator it;
	int i=0;
	for(it = m_products.begin(); it!=m_products.end();it++){
		if(nameProduct == m_products[i]->getTitle()){
			break;
		}
		i++;
	}
	//cout<<"Nom du produit: "<<m_products[i]->getTitle()<<", Description: "<<m_products[i]->getDesc()<<", Quantité disponible: "<<m_products[i]->getQuantity()<<", prix: "<<m_products[i]->getPrice()<<endl;
	cout<<m_products[i];
}

//change la quantité d'un produit du magasin
void Magasin::updateQuantityProduct(string nameProduct, int quantity){
	vector<Product*>::iterator it;
        int i=0;

        for(it = m_products.begin(); it!=m_products.end();it++){
                if(nameProduct == m_products[i]->getTitle()){
                        break;
                }
                i++;
        }
        if(m_products[i]->getTitle() == nameProduct){
     		m_products[i]->setQuantity(quantity);
    	}else{
    		cout<<"Ce produit n'est pas disponible"<<endl;
    	}
}

void Magasin::addClient(Client *client){
	m_clients.push_back(client);
}
//affiche tout les clients
void Magasin::printClients(){
	vector<Client*>::iterator it;
	int i=0;
	
	for(it = m_clients.begin(); it!=m_clients.end();it++){
		/*if(i==0){
			cout<<"ID 			Nom"<<endl;
		}
		cout<<m_clients[i]->getId()<<"			"<<m_clients[i]->getNom()<<" "<<m_clients[i]->getPrenom()<<endl;*/
		cout<<m_clients[i];
		i++;
	}
	if(i==0){
		cout<<"Il n'y a aucun clients d'enregistré ..."<<endl;
	}
}

void Magasin::printClient(int idClient){
	vector<Client*>::iterator it;
	int i=0;
	for(it = m_clients.begin();it!=m_clients.end();it++){
		if(m_clients[i]->getId()==idClient){
			break;
		}
		i++;
	}
	if(m_clients[i]->getId() == idClient){
		//cout<<"nom: "<<m_clients[i]->getNom()<<" prenom: "<<m_clients[i]->getPrenom()<<", ID: "<<m_clients[i]->getId()<<endl;
		cout<<m_clients[i];
	}else{
		cout<<"Le client n'existe pas"<<endl;
	}
}
void Magasin::printClient(string nameClient){
	vector<Client*>::iterator it;
	int i=0;
	for(it = m_clients.begin();it!=m_clients.end();it++){
		if(m_clients[i]->getNom()==nameClient){
			break;
		}
		i++;
	}
	if(m_clients[i]->getNom() == nameClient){
		//cout<<"nom: "<<m_clients[i]->getNom()<<" prenom: "<<m_clients[i]->getPrenom()<<", ID: "<<m_clients[i]->getId()<<endl;
		cout<<m_clients[i];
	}else{
		cout<<"Le client n'existe pas"<<endl;
	}
}
//on ajoute un produit au panier du client
void Magasin::addProductToPanier(string nameProduct, int idClient, int quantity){
	vector<Client*>::iterator it1;
	vector<Product*>::iterator it2;
	int i=0;
	int j=0;
	//on regarde si le magasin contien des objets
	if(m_products.size() == 0 or m_clients.size() == 0){
		cout<<"Impossible, aucun client ou aucun produit enregistré dans le magasin"<<endl;
	}else{
		//on recherche le produit
		for(it2=m_products.begin();it2!=m_products.end();it2++){
			if(m_products[i]->getTitle()==nameProduct){
				break;
			}
			i++;
		}
		if(m_products[i]->getTitle() == nameProduct){
			//on recherche le client
			for(it1=m_clients.begin();it1!=m_clients.end();it1++){
				if(m_clients[j]->getId()==idClient){
					break;
				}
				j++;
			}
			if(m_clients[j]->getId() == idClient){
				//on verifie si la quantité est correct
				if(m_products[i]->getQuantity()>=quantity){
					m_clients[j]->addProduct(m_products[i], quantity);
				}else{
					cout<<"Quantité insufisante dans le magasin"<<endl;
				}
			}else{
				cout<<"Le client n'existe pas"<<endl;
			}
		}else{
			cout<<"Le produit n'est pas dans le magasin"<<endl;
		}
	}
}
//retire un produit du panier
void Magasin::delProductOfPanier(string nameProduct, int idClient){
        vector<Client*>::iterator it2;
        vector<Product*>::iterator it1;
        int i=0;
        int j=0;
        //on cherche le produit
        for(it1=m_products.begin();it1!=m_products.end();it1++){
                if(m_products[i]->getTitle()==nameProduct){
                        break;
                }
                i++;
        }
        //on cherche le client
        if(m_products[i]->getTitle() == nameProduct){
	        for(it2=m_clients.begin();it2!=m_clients.end();it2++){
	                if(m_clients[j]->getId()==idClient){
	                        break;
	                }
	                j++;
	        }
	        //on supprime le produit du panier
	        if(m_clients[j]->getId() == idClient){
	        	m_clients[j]->deleteProduct(m_products[i]->getTitle());
	    	}else{
	    		cout<<"Le client n'existe pas"<<endl;
	    	}
    	}else{
    		cout<<"le produit n'est pas dans le magasin"<<endl;
    	}
}
//modifie la quantité d'un produit du panier
void Magasin::setQuantityOfProductOfPanier(string nameProduct, int idClient, int quantity){
        vector<Client*>::iterator it2;
        vector<Product*>::iterator it1;
        int i=0;
        int j=0;
        //on cherche le produit
        for(it1=m_products.begin();it1!=m_products.end();it1++){
                if(m_products[i]->getTitle()==nameProduct){
                        break;
                }
                i++;
        }
        //on cherche le client
        if(m_products[i]->getTitle()==nameProduct){
	        for(it2=m_clients.begin();it2!=m_clients.end();it2++){
	                if(m_clients[j]->getId()==idClient){
	                        break;
	                }
	                j++;
	        }
	        //on verifie si la quantité est correct
	        if(m_clients[j]->getId()==idClient){
	        	if(m_clients[j]->getQuantity(m_products[i]->getTitle())>=quantity){
	        		//on modifie la quantité
	        		m_clients[j]->changeQuantity(quantity, m_products[i]->getTitle());
	        	}else{
	        		cout<<"Quantité insufisante dans le magasin ..."<<endl;
	        	}
	    	}else{
	    		cout<<"Le client n'existe pas"<<endl;
	    	}
    	}
}
//valide une commande
void Magasin::validOrder(int idClient){
	vector<Client*>::iterator it;
	int i = 0;
	int j = 0;
	int k = 0;
	int resultSomme = 0;
	//on cherche le client
	for(it=m_clients.begin();it!=m_clients.end();it++){
		if(m_clients[i]->getId() == idClient){
			break;
		}
		i++;
	}
	//on ajoute l'id de la commande dans le client
	m_clients[i]->addOrder(m_orders.size());
	vector<Product*>::iterator it1;
	vector<Product*>::iterator it2;
	//on actualise la quantité des produits dans le magasin
	for(it1=m_clients[i]->getPanier().begin(); it1!=m_clients[i]->getPanier().end(); it1++){
		for(it2=m_products.begin();it2!=m_products.end();it2++){
			if(m_clients[i]->getPanier()[j]->getTitle() == m_products[k]->getTitle()){
				resultSomme = m_products[k]->getQuantity() - m_clients[i]->getPanier()[j]->getQuantity();
				m_products[k]->setQuantity(resultSomme);
				break;
			}
			k++;
		}
		j++;
	}
	Order *newOrder= new Order(m_clients[i]->getPanier(), false, m_clients[i]->getNom()) ;
	m_orders.push_back(newOrder);
	m_clients[i]->clearPanier();
}
void Magasin::setStatus(int idOrder, bool statut){
	m_orders[idOrder]->setStatut(statut);
}
void Magasin::printOrders(){
	vector<Order*>::iterator it;
	int i =0;

	for(it = m_orders.begin(); it!=m_orders.end();it++){
		/*cout<<"Commande n°"<<i<<endl;
		m_orders[i]->printProducts();*/
		cout<<"id: "<<i<<" "<<m_orders[i];
		i++;
		cout<<endl;
	}
	if(i==0){
		cout<<"il n'y a aucune commande ..."<<endl;
	}
}
void Magasin::printOrdersClient(int idClient){
	vector<int>::iterator it;
	vector<Client*>::iterator it1;
	int i = 0;
	int j = 0;
	for(it1=m_clients.begin(); it1!=m_clients.end(); it1++){
		if(m_clients[i]->getId()==idClient){
			break;
		}
		i++;
	}
	if(m_clients[i]->getId()==idClient){
		for(it=m_clients[i]->getIdOrder().begin(); it!=m_clients[i]->getIdOrder().end(); it++){
			cout<<m_orders[m_clients[i]->getIdOrder()[j]];
			j++;
		}
	}
}
void Magasin::printOrdersClient(string name){
	vector<int>::iterator it;
	vector<Client*>::iterator it1;
	int i = 0;
	int j = 0;
	for(it1=m_clients.begin(); it1!=m_clients.end(); it1++){
		if(m_clients[i]->getNom()==name){
			break;
		}
		i++;
	}
	if(i!=0){
		if(m_clients[i]->getNom()==name){
			for(it=m_clients[i]->getIdOrder().begin(); it!=m_clients[i]->getIdOrder().end(); it++){
				cout<<m_orders[m_clients[i]->getIdOrder()[j]];
				j++;
			}
		}
	}
}
//libère la mémoire dprise pars les allocations dynamique
void Magasin::clearAll(){
	vector<Product*>::iterator it1;
	vector<Client*>::iterator it2;
	vector<Order*>::iterator it3;
	int i = 0;
	if(m_products.size()!=0){
		for(it1=m_products.begin();it1!=m_products.end();it1++){
			delete m_products[i];
			i++;
		}
	}
	i=0;
	if(m_clients.size()!=0){
		for(it2=m_clients.begin();it2!=m_clients.end();it2++){
			delete m_clients[i];
			i++;
		}
	}
	i=0;
	if(m_orders.size()!=0){
		for(it3=m_orders.begin();it3!=m_orders.end();it3++){
			delete m_orders[i];
			i++;
		}
	}
}
