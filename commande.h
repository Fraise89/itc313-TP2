
#ifndef DEF_COMMANDE
#define DEF_COMMANDE

#include <string>
#include "client.h"
#include "produit.h"

using namespace std;

class Order{
	public:
		Order(vector<Product*> ProduitAchete, bool statut, string nomClient);
		friend ostream& operator<<(ostream &flux, Order* order);
		void setStatut(bool statut);
		bool getStatut();
		void printProducts();
		void setNomClient();
	private:
		vector<Product*> m_produitAchete;
		string m_nomClient;
		bool m_statut;
};

#endif
