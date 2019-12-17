#include "Commande.h"

Commande::Commande(Client* client, vector<Porduit*> produitAchete, bool statut){
	m_client = client;
	m_produitAchete = produitAchete;
	m_statut = statut;
}
ostream& operator<<(ostream &flux,Commande* commande){

    	flux<<"Détail de la commande:"<<endl<<"nom du client: "<<m_client->getName()<<endl;
	flux<<"livré: ";
	if(statut == false){
		flux<<"Non"<<endl<<endl;
	}else{
		flux<<"Oui"<<endl<<endl;
	}
	flux<<"Liste des produit acheté:"<<endl;
	vector<Produit*>::iterator it;
	int i = 0;
	for(it=m_produitAchete.beginn();it!=m_produitAchete.end();it++){
		flux<<"     nom:"<<m_produitAchete[i].getName()<<", quantité: "<<produitAchete[i].getQuantity()<<", prix: "<<produitAchete[i].getPrice * produitAchete[i].getQuantity[i]<<endl;
	}
    return flux;

}

