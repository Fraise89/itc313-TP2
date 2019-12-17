#ifndef DEF_COMMANDE
#define DEF_COMMANDE

#include <string>

using namespace std;

class Commande{
	public:
		Commande(Client* client,vector<Produit*> ProduitAchete, bool statut);*
		friend ostream& operator<<(ostream &flux, Commande* commande);
	private:
		Client* m_client = client;
		vector<Produit*> m_produitAchete = produitAchete;
		m_statut = statut
};

#endif
