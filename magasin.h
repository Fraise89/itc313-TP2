#ifndef DEF_MAGASIN
#define DEF_MAGASIN

#include <string>
#include <vector>
#include "Produit.h"
#include "Client.h"
#include "Order.h"

using namespace std;

class Magasin{
public:
	Magasin(vector<Product*> products, vector<Client*> clients, vector<Order*> orders);
	vector<Product*> getProducts();
	vector<Client*> getClients();
	vector<Order*> getOrders();
	void setProducts(vector<Product*> products);
	void setClients(vector<Client*> clients);
	void setOrders(vector<Order*> orders);
	//question 3
	void addProduct(Product* products);
	void printAllProduct();
	void pintInfo(string nameProduct);
	void updateQuantityProduct(string nameProduct, int quantity);
	private:
		vector<Product*> m_products;
		vector<Client*> m_clients;
		vector<Order*> m_orders;

};
#endif
