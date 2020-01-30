
#include "commande.h"

Order::Order(vector<Product*> produitAchete, bool statut, string nomClient){
	m_produitAchete = produitAchete;
	m_statut = statut;
	m_nomClient = nomClient;
}
void Order::setStatut(bool statut){
	m_statut = statut;
}
//affiche les produits de la commande
void Order::printProducts(){
	vector<Product*>::iterator it;
	int i = 0;
	for(it = m_produitAchete.begin(); it!=m_produitAchete.end(); it++){
		cout<<"x"<<m_produitAchete[i]->getQuantity()<<"  "<<m_produitAchete[i]->getTitle()<<endl;
		i++;
	}
}
bool Order::getStatut(){
	return m_statut;
}
//surcharge de l'operateur <<
ostream& operator<<(ostream &flux,Order* order){

    flux<<"Détail de la commande:"<<endl<<"nom du client: "<<order->m_nomClient<<endl;
	flux<<"livré: ";
	if(order->m_statut == false){
		flux<<"Non"<<endl<<endl;
	}else{
		flux<<"Oui"<<endl<<endl;
	}
	flux<<"Liste des produit acheté:"<<endl;
	vector<Product*>::iterator it;
	int i = 0;
	for(it=order->m_produitAchete.begin();it!=order->m_produitAchete.end();it++){
		flux<<order->m_produitAchete[i];//"     nom:"<<order->m_produitAchete[i]->getTitle()<<", quantité: "<<order->m_produitAchete[i]->getQuantity()<<", prix: "<<order->m_produitAchete[i]->getPrice() * order->m_produitAchete[i]->getQuantity()<<endl;
		i++;
	}
    return flux;

}
