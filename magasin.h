
#ifndef DEF_MAGASIN
#define DEF_MAGASIN

#include <string>
#include <vector>
#include <iostream>

#include "produit.h"
#include "client.h"
#include "commande.h"
using namespace std;

class Magasin{
	public:
		//question 1
		Magasin(vector<Product*> products, vector<Client*> clients, vector<Order*> orders);
		vector<Product*> getProducts();
		vector<Client*> getClients();
		vector<Order*> getOrders();
		void setProducts(vector<Product*> products);
		void setClients(vector<Client*> clients);
		void setOrders(vector<Order*> orders);
		
		//question 3
		void addProduct(Product *products);
		void printProducts();
		void printProduct(string nameProduct);
		void updateQuantityProduct(string nameProduct, int quantity);
		
		//question 5
		void addClient(Client *client);
		void printClients();
		void printClient(string nameClient);
		void printClient(int idClient);
		void addProductToPanier(string nameProduct, int idClient, int quantity);
		void delProductOfPanier(string nameProduct, int idClient);
		void setQuantityOfProductOfPanier(string nameProduct, int idClient, int quantity);
		//question 7
		void validOrder(int idClient);
		void setStatus(int idOrder, bool statut);
		void printOrders();
		void printOrdersClient(int idClient);
		void printOrdersClient(string nameClient);

		void clearAll();
		
	private:
		//question 1
		vector<Product*> m_products;
		vector<Client*> m_clients;
		vector<Order*> m_orders;

};
#endif
