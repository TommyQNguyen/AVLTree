#include "Vue.h"

using namespace std;

int showMenu() {
	int choice;
	cout << endl << endl <<
		"Le facteur d'equilibre est de : " << endl << endl <<
		"Que voulez-vous faire?" << endl << endl << endl <<
		"1 Ajouter un element a l'arbre?" << endl <<
		"2 Imprimer l'arbre?" << endl <<
		"3 Supprimer une valeur" << endl <<
		"4 Parcourir l'arbre" << endl <<
		"5 Quitter?" << endl << endl << endl << endl << endl << endl
		<< "Votre choix : ";
	cin >> choice;
	clrscr();
	return choice;
}

void menu_ADD()
{
	int dataInput = 0;

	clrscr();
	cvmSetColor(ROSE);
	cout << "\n\n\n\n\n\n\nQuelle est la valeur ? : ";
	cvmResetColor();
	cin >> dataInput;

	insert(dataInput);
	clrscr();
	showTree();
	clrscr();
}

void menu_DELETE()
{
	int dataInput = 0;

	clrscr();
	cvmSetColor(JAUNE);
	cout << "\n\n\n\n\n\n\nQuelle est la valeur ? : ";
	cvmResetColor();
	cin >> dataInput;

	deletion(dataInput);
	clrscr();
	showTree();
	clrscr();
}

void menu_TRAVERSAL(Node* root)
{
	clrscr();
	cvmSetColor(BLEU);
	cout << "Voici le parcours prefix :\n\n";
	preorder(root);

	cout << "\n\nVoici le parcours infixe :\n\n";
	inorder(root);

	cout << "\n\nVoici le parcours postfixe :\n\n";
	postorder(root);
	_getch();
	clrscr();
	cvmResetColor();
}

