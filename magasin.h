#include <string>
#include <vector>
using namespace std;
class Magasin
{
public:
	Magasin(string products, string clients, string object);
	string getProducts();
	string getObject();
	vector<Product*> getProducts();
	vector<Client*> getClients();
	vector<Order*> getOrders();
	Void setProducts(vector <Product*> product);
	Void setClients(vector <Client*> client);
	Void setOrders(vector <Order*> order);
	Void setObject(string object);

private: 
	string m_products;
	string m_object;
	vector<Product*> m_products;
	vector<Client*> m_clients;
	vector<Order*> m_orders;
	
};
