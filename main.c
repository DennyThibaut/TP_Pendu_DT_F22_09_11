/* ALGO: Pendu en C
   BUT: Creer un jeu du Pendu fonctionnel
   ENTREE: Le mot a cherche ainsi que chaque lettre
   SORTIE: Nb de vie, le mot actuellement recherche

   CONST
    TAILLE=100
var
    Lettre: charactere
    vie,cpt,i,estPareil,aTrouverUneLettre: Entier
    MotCherche,MotTrouve: Chaine

    replay<- 1
    TANT QUE (replay=1)
        REPETER
            ECRIRE "Entrer votre mot"
            LIRE MotCherche
        JUSQUA (longueur(MotCherche) > TAILLE OU longueur(MotCherche) < 3)
        POUR i DE 0 A longueur(MotCherche)
            FAIRE
                MotTrouve[i]<- '-'
                MotTrouve[i]='\0'
                i<- i+1
        FinPOUR
        TANT QUE (estPareil <> 1 ET vie <> 0)
            ECRIRE "Vous avez"& vie &"vie"
            ECRIRE "Mot a trouver :"& MotTrouve
            ECRIRE "Entrer une lettre: "
            LIRE (Lettre)
            POUR i DE 0 A longueur(MotCherche)
                FAIRE
                    SI Lettre = MotCherche[i] ALORS
                        MotTrouve[i]=Lettre
                        ECRIRE "La lettre"& Lettre &"est bien presente!"
                        aTrouverUneLettre = 1
                    FinSI
                    i<-i+1
                FinPOUR
            SI aTrouverUneLettre <> 1 ALORS
                vie<- vie-1
            SINON
                aTrouverUneLettre<- 0
            FinSI
            TANT QUE (i< longueur(MotCherche) ET MotTrouve[i] = MotCherche[i])
                i<- i+1
            FinTANT QUE
            SI (i=longueur(MotCherche)) ALORS
                estPareil<- 1
            SINON
                estPareil<- 0
            FinSI
        FinTANT QUE
        SI (vie <> 0)) ALORS
            ECRIRE "Il est facile ce jeu hein ? Bien joue!"
        SINON
            ECRIRE "Reflechis mieux la prochaine fois!"
        FinSI
        ECRIRE "T'as envie de rejouer ? (1 Oui, 0 Non)
        LIRE replay
    FinTANT QUE
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE 10

int main ()
{

    int replay = 1;
    while(replay == 1)
    {
        char MotCherche[TAILLE];
        char Lettre;
        int vie = 5, cpt = 0 , i = 0;
        int estPareil = 0, aTrouverUneLettre = 0;

        do{
            printf("Entrer votre mot: ");
            scanf("%s",&MotCherche);
        }while (strlen(MotCherche) > TAILLE || strlen(MotCherche) < 3);

        char MotTrouve[TAILLE];
        for(i=0;i<strlen(MotCherche);i++)
            MotTrouve[i] = '-';
            MotTrouve[i]='\0';

        while(estPareil != 1 && vie != 0)
        {
             fflush(stdin);
             printf("Vous avez %i vie\n",vie);
             printf("Mot a trouver :\n%s\n", MotTrouve);

             printf("Entrer une lettre: ");
             scanf("%c",&Lettre);

             for(i = 0; i < strlen(MotCherche); i++)
             {
                 if(Lettre == MotCherche[i])
                 {
                     MotTrouve[i] = Lettre;
                     printf("La lettre %c est bien presente!\n", Lettre);
                     aTrouverUneLettre = 1;
                 }
             }

             if(aTrouverUneLettre != 1)
                vie -= 1;
            else
                aTrouverUneLettre = 0;

             i = 0;
             while(i < strlen(MotCherche) && MotTrouve[i] == MotCherche[i]){
                i++;
             }
             if(i == strlen(MotCherche))
                estPareil = 1;
             else
                estPareil = 0;

        }

        if(vie != 0)
        {
            printf("Il est facile ce jeu hein ? Bien joue!\n");
        }
        else
        {
            printf("Reflechis mieux la prochaine fois \n");
        }

        printf("T'as envie de rejouer ? (1 Oui, 0 Non)");
        scanf("%i", &replay);
    }


    system("pause");
    return 0;
}
