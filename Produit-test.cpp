#include "Produit.h"

#include <iostream>
#include <string>

using namespace std;

int main(){

	Produit *produitTest= new Produit("Figurine de l'homme invisible", "Reproduction fidèle de l'homme invisible voyageant dans la dimension invisible !", 453, 89.99);

	cout<<"Liste des produits disponible:"<<endl;
	cout<<"Nom: "<<produitTest->getName()<<"   descritption: "<<produitTest->getDescription()<<"    Prix: "<<produitTest->getPrice()<<"€   Quantité disponible: "<<produitTest->getQuantity()<<endl;
	cout<<endl<<"Modification du produit '"<<produitTest->getName()<<endl;

	produitTest->setName("Papier toilette Donald Trump");
	produitTest->setDescription("ça reste du papier toilette quoi qu'il arrive");
	produitTest->setQuantity(89);
	produitTest->setPrice(5.23);

	cout<<"Nom: "<<produitTest->getName()<<"   descritption: "<<produitTest->getDescription()<<"    Prix: "<<produitTest->getPrice()<<"€   quantité disponible: "<<produitTest->getQuantity()<<endl<<endl;

	cout<<"Affichage avec l'operateur <<" <<endl;
	cout<<produitTest<<endl;
	return 0;
}
