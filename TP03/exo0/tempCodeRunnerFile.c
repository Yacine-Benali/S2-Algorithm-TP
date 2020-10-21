  Node *node = (Node *)malloc(sizeof(Node));
    Node *courant;
    node->val = x;
    node->suiv = NULL;
    if (*tete == NULL)
    {
        *tete = node;
    }
    else
    {
        courant = *tete;
        while (courant->suiv != NULL)
        {
            courant = courant->suiv;
        }
        courant->suiv = node;
    }