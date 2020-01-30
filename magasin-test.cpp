
#include "magasin.h"

int main(){
	//creation de la classe magasin
	vector<Product*> produits;
	vector<Client*> clients;
	vector<Order*> orders;
	Magasin magasin(produits, clients, orders);

	vector<Product*> panier;

	cout<<"Programme entièrment fonctionnel mis à part quelque détail, comme la lecture de tout information où l'on renseigne un ID quand cette ID n'existe pas, de plus la partie base de donnée enregistré dans un fichier n'a pas été réalisé "<<endl<<endl;

	int choix1 = -1;
	int choix2 = -1;
	int choix3 = -1;
	int stop1 = 0;
	int stop2 = 0;
	bool statut = false;
	string nom;
	string prenom;
	int quantity;
	int id;
	double price;

	while(stop1==0){
		cout<<"=====EASY STORE====="<<endl<<endl;
		cout<<"Que voulez vous faire ?"<<endl;
		cout<<"1) Gestion clients"<<endl;
		cout<<"2) Gestion Produits"<<endl;
		cout<<"3) Gestion commande"<<endl;
		cout<<"4) quitter"<<endl<<">";
		cin>>choix1;
		stop2=0;
		if(choix1==1){
			while(stop2==0){
				cout<<"Gestion des Clients"<<endl;
				cout<<"Que voulez vous faire ?"<<endl;
				cout<<"1) voir tout les clients"<<endl;
				cout<<"2) voir les infos d'un client"<<endl;
				cout<<"3) ajouter un client"<<endl;
				cout<<"4) ajouter un produit au panier d'un client"<<endl;
				cout<<"5) supprimer un produit du panier d'un client"<<endl;
				cout<<"6) modifier la quantité d'un produit du panier d'un client"<<endl;
				cout<<"7) voir le panier d'un client"<<endl;
				cout<<"8) retourner au menu"<<endl<<">";
				cin>>choix2;
				if(choix2==1){
					magasin.printClients();
				}else if(choix2==2){
					cout<<"Voulez vous rentrer le nom ou l'ID du client ? (0 ID/ 1 nom)"<<endl<<">";
					cin>>choix3;
					if(choix3==0){
						cout<<"Quelle est l'ID du client ?"<<endl<<">";
						cin>>id;
						magasin.printClient(id);
					}else{
						cout<<"Quelle est le nom du client ?"<<endl<<">";
						cin>>nom;
						magasin.printClient(nom);
					}
				}else if(choix2==3){
					cout<<"Quelle prénom ?"<<endl<<">";
					cin>>prenom;
					cout<<"Quelle nom ?"<<endl<<">";
					cin>>nom;
					//on créer le nouveau client
					Client *client = new Client(magasin.getClients().size(), prenom, nom, panier);
					magasin.addClient(client);
				}else if(choix2==4){
					cout<<"Quelle est l'ID du client ?"<<endl<<">";
					cin>>id;
					cout<<"Quelle est le nom du produit ?"<<endl<<">";
					cin.ignore();
					getline(cin, nom);
					cout<<"Combien voulez vous en acheter ?"<<endl<<">";
					cin>>quantity;
					magasin.addProductToPanier(nom, id, quantity);
				}else if(choix2==5){
					cout<<"Quelle est l'ID du client ?"<<endl<<">";
					cin>>id;
					cout<<"Quelle est le nom du produit ?"<<endl<<">";
					cin>>nom;
					magasin.delProductOfPanier(nom, id);
				}else if(choix2==6){
					cout<<"Quelle est l'ID du client ?"<<endl<<">";
					cin>>id;
					cout<<"Quelle est le nom du produit ?"<<endl<<">";
					cin>>nom;
					cout<<"Quelle est la quantité du produit ?"<<endl<<">";
					cin>>quantity;
					magasin.setQuantityOfProductOfPanier(nom, id, quantity);
				}else if(choix2==7){
					cout<<"Quelle est l'ID du client ?"<<endl<<">";
					cin>>id;
					magasin.getClients()[id]->printPanier();
				}else if(choix2==8){
					cout<<endl<<endl;
					stop2=1;
				}
			}
		}else if(choix1 == 2){
			while(stop2 == 0){
				cout<<"Gestion des Produits"<<endl;
				cout<<"Que voulez vous faire ?"<<endl;
				cout<<"1) ajouter un produit au magasin"<<endl;
				cout<<"2) afficher tout les produits en magasin"<<endl;
				cout<<"3) afficher les infos d'un produit"<<endl;
				cout<<"4) modifier la quantité d'un produit"<<endl;
				cout<<"5) retourner au menu"<<endl<<">";
				cin>>choix2;
				if(choix2==1){
					cout<<"Quelle est le nom du produit ?"<<endl<<">";
					cin.ignore();
					getline(cin, nom);
					cout<<"Quelle est la description du produit ?"<<endl<<">";
					cin.ignore();
					getline(cin, prenom);
					cout<<"Quelle est la quantité du produit dans le magasin ?"<<endl<<">";
					cin>>quantity;
					cout<<"Quelle est le prix du produit ?"<<endl<<">";
					cin>>price;
					//on créer le produit
					Product *produit = new Product(nom, prenom, quantity, price);
					magasin.addProduct(produit);
				}else if(choix2==2){
					magasin.printProducts();
				}else if(choix2==3){
					cout<<"Quelle est le nom du produit ?"<<endl<<">";
					cin>>nom;
					magasin.printProduct(nom);
				}else if(choix2==4){
					cout<<"Quelle est le nom du produit ?"<<endl<<">";
					cin>>nom;
					cout<<"Quelle est la quantité du produit ?"<<endl<<">";
					cin>>quantity;
					magasin.updateQuantityProduct(nom, quantity);
				}else if(choix2==5){
					cout<<endl<<endl;
					stop2=1;
				}
			}
		}else if(choix1 == 3){
			while(stop2 == 0){
				cout<<"Gestions des commandes"<<endl;
				cout<<"Que voulez vous faire ?"<<endl;
				cout<<"1) voir toute les commandes"<<endl;
				cout<<"2) voir les commandes d'un client"<<endl;
				cout<<"3) voir le statut d'une commande"<<endl;
				cout<<"4) valider la commande d'un client"<<endl;
				cout<<"5) changer le statut d'une commande"<<endl;
				cout<<"6) retour au menu"<<endl<<">";
				cin>>choix2;
				if(choix2==1){
					magasin.printOrders();
				}else if(choix2==2){
						cout<<endl<<"Quelle est l'ID du client ?"<<endl<<">";
						cin>>id;
						magasin.printOrdersClient(id);
				}else if(choix2==3){
					cout<<"quelle est l'ID de la commande ?"<<endl<<">";
					cin>>id;
					if(magasin.getOrders()[id]->getStatut()==0){
						cout<<"Pas encore livré"<<endl;
					}else{
						cout<<"La commande a été livré !"<<endl;
					}
					
				}else if(choix2==4){
					cout<<"Quelle est l'ID du client ?"<<endl<<">";
					cin>>id;
					magasin.validOrder(id);
				}else if(choix2 == 5){
					cout<<"Quelle est l'état de la livraison ? (0 pas livré/ 1 livré)"<<endl<<">";
					cin>>statut;
					cout<<"Quelle est l'ID de la commande ?"<<endl<<">";
					cin>>id;
					magasin.getOrders()[id]->setStatut(statut);
				}else if(choix2==6){
					cout<<endl<<endl;
					stop2=1;
				}
			}
		}else if(choix1 == 4){
			stop1=1;
			choix2 = -1;
			choix1 = -1;
			magasin.clearAll();
		}
	}
}
