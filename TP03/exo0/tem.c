void ajout2(Node **tete, int x)
{
    // Declaration d 'un deuxième pointeur sur l'élément courant
    Node *courant;
    //Création d'un nouveau noeud
    Node *nouv = (Node *)malloc(sizeof(Node));
    //Saisir les informations
    nouv->val = x;
    nouv->suiv = NULL;
    if (*tete == NULL)
        *tete = nouv;
    else
    {
       // Se positionner sur le dernier élément
        courant = *tete;
        while (courant->suiv != NULL)
            courant = courant->suiv;
        //Chaînage du nouvel élément à la liste
        courant->suiv = nouv;
    }
}