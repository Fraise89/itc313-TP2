#include <string>
#include <vector>
using namespace std;
class Magasin
{
public:
	Magasin(string products, string clients, int orders, string object);
	Object getObject(string Object="Vide");

private: 
	string m_products;
	int m_orders;
	string m_object;
	vector<Product*> m_products;
	vector<Client*> m_clients;
	vector<Order*> m_orders;
	
};