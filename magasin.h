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

	//question 5
	void addClient(Client* client);
	void printAllClient();
	void printClient(string nameClient);
	void printClient(int idClient);
	void addProductToPanier(string nameProduct, string nameClient);
	void delProductOfPanier(string nameProduct, string nameClilent);
	void setQuantityOfProductOfPanier(string nameProduct, string nameClient, int quantity);
	private:
		vector<Product*> m_products;
		vector<Client*> m_clients;
		vector<Order*> m_orders;

};
#endif
