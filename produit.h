
#ifndef DEF_PRODUIT
#define DEF_PRODUIT

#include <string>
#include <iostream>

using namespace std;

class Product{
	public:
		Product(string title, string desc, int quantity, double price);
		string getTitle();
		string getDesc();
		int getQuantity();
		double getPrice();

		void setQuantity(int newQuantity);

		friend ostream& operator<<(ostream &flux, Product *produit);

	private:
		string m_title;
		string m_desc;
		int m_quantity;
		double m_price;
};

#endif
