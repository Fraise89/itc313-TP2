#ifndef DEF_PRODUIT
#define DEF_PRODUIT

#include <iostream>
#include <string>
using namespace std;

class Produit{
	public:
		string getName();
		string getDescription();
		int getQuantity();
		float getPrice();

		void setName(string name);
		void setDescription(string description);
		void setQuantity(int quantity);
		void setPrice(float price);

		friend ostream& operator<<(ostream &flux, Produit *produit);
		Produit(string name, string description, int quantity, int price);

	private:
		string m_name;
		string m_description;
		int m_quantity;
		float m_price;
};


#endif
