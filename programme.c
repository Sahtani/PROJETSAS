#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <time.h>
typedef struct {
    int jour;
    int mois;
    int annee;
}deadline;
typedef struct Tache{
    int id[20];
    char  titre[100];
    char  description[100];
    deadline deadline;
    char  statut[100];   
}Tache;
void ajoutertache(Tache taches[],int nbt){
    Tache t;
    for(int i=0;i<nbt;i)
       if(nbt==0){
          t.id[i]=1;
        }else {
            t.id[i]++;
        }
    
    printf("entrer le titre de tache:\n");   
    scanf("%s",&taches[nbt].titre);
    printf("entrer la description de tache:\n");
    scanf("%s",&taches[nbt].description);
    printf("entrer la date de deadline:\n");
    scanf("%d %d %d", &taches[nbt].deadline.jour, &taches[nbt].deadline.mois, &taches[nbt].deadline.annee);
    taches[nbt]=t;
    
    
}
void afficherTaches1(Tache taches[],int nbt){
    for(int i=0;i<nbt;i++){
     printf("%d %s %s %d/%d/%d %s\n",taches[i].id,taches[i].titre,taches[i].description,taches[i].deadline.jour,taches[i].deadline.mois,taches[i].deadline.annee);
    }
}

/*void ajouterplusieurtache(Tache taches[],int nbt){
    int tacheajouter;
    printf("entrer le nombre des taches a ajouter:\n");
    scanf("%d",&tacheajouter);
    for(int i=0;i<tacheajouter;++i){
        ajoutertache(taches,nbt);
        nbt++;
    }
}
void Trieralphabetique(Tache taches[],int nbt){
    void swaptache(Tache *a, Tache *b){
       Tache temp;
    strcpy(temp.titre, a->titre);
    strcpy(a->titre, b->titre);
    strcpy(b->titre, temp.titre);
    }
    void tri(Tache taches[],int nbt){
    for (int i = 0; i < nbt-1; i++) {
        for (int j = ; j < nbt-i-1; j++) {
            if (strcmp(Tache[j].titre, Tache[j+1].titre) > 0) {
               
            }
        }
    }
    
 }
}

void Trierpardeadline(Tache taches[],int nbt){
    Tache temp;
    for(int i=0;i<nbt;i++){
        for(int j=0;j<nbt-1;j++){
            if(taches[j].deadline.jour>taches[j+1].deadline.jour){
                 temp=taches[j];
                taches[j]=taches[j+1];
                taches[j+1]=temp;
            }
        }
    }
}


void afficherTaches(Tache taches[],int nbt){
    int dead = 0;
    for(int i=0;i<nbt;i++){
        Trieralphabetique( taches,nbt);
        printf("%d %s %s %d/%d/%d %s\n",i,taches[i].titre,taches[i].description,taches[i].deadline.jour,taches[i].deadline.mois,taches[i].deadline.annee);
    }
    for ( int i = 0; i < nbt; i++){
       Trieralphabetique(taches,nbt);
       printf("%d %s %s %d/%d/%d %s\n",i,taches[i].titre,taches[i].description,taches[i].deadline.jour,taches[i].deadline.mois,taches[i].deadline.annee);
    }
    
     for ( int i = 0; i < nbt; i++){
       
      
}


  

}
void modifierdescription(Tache taches[],char newdescription){
    int nbt,ident;
    printf("entrer l identifiand de tache:\n");
	scanf("%d",&ident);
    for(int i=0;i<nbt;i++){
        if(ident==taches[i].id[i]){
            strcpy(taches[i].description,newdescription);
        }
    }
        
}
void modifierstatut(Tache taches[],char newstatus){
    int ident,nbt;
    printf("entrer l identifiand de tache:\n");
    scanf("%d",&ident);
    for(int i=0;i<nbt;i++){
        if(taches[i].id==ident){
            printf("entrer le nouveau statut de tache:\n");
           scanf("%d",taches[nbt].id);
            strcpy(taches[i].statut,newstatus);
        }
    }

    }
void modifierdeadline(Tache taches[],char newdeadline){
    int ident,nbt;
    printf("entrer l identifiand de tache:\n");
    scanf("%d",&ident);
    for(int i=0;i<nbt;i++){
        if(taches[i].id==ident){
            printf("entrer la nouvelle date de deadline de tache:\n");
            scanf("%d %d %d",&taches[nbt].deadline.jour, &taches[nbt].deadline.mois, &taches[nbt].deadline.annee);
           
        }else printf("Aucune tâche avec cet identifiant n'a été trouvée.\n");
    }
}
void  Supprimertache(Tache taches[]){
     int ident,nbt;
	 printf("entrer l identifiand de tache a supprimer:\n");
    scanf("%d",&ident);
    for(int i=0;i<nbt;i++){
        if(ident==taches[i].id[i]){
            
        }
    
}
}

void modifierstatut(Tache taches[],int nbt){
    Tache temp;
    for(int i=0;i<nbt;i++){
        
            }
}
    





/*void menutache(){

            printf("\t\t+----------------------------------------+\n");
            printf("\t\t|             Menu Taches                |\n");
            printf("\t\t+----------------------------------------+\n");
            printf("\t\t|                                        |\n");
            printf("\t\t|     1- Afficher L\'etudiants           |\n");
            printf("\t\t|     2- Afficher                        |\n");
            printf("\t\t|     3-Ajouter apprenat (s)                          |\n");
            printf("\t\t|     4-                         |\n");
            printf("\t\t+----------------------------------------+\n");

}*/
int main(){
    int c;
    char c2;
    int nbt=0;
    Tache taches[100];
 while(1){
                       
    
            printf("\t\t                                                                 \n");
            printf("\t\t    1- Ajouter une nouvelle tache :                               \n");
            printf("\t\t    2- Ajouter plusieurs nouvelles taches:                        \n");
            printf("\t\t    3- Afficher la liste de toutes les taches :                    \n");
            printf("\t\t    4- Modifier une tache:                                         \n");
            printf("\t\t    5- Supprimer une tache par identifiand :                        \n");
            printf("\t\t    6- Rechercher les Taches :                                       \n");
            printf("\t\t    7- Statistiques:                                                  \n");
            printf("\t\t    8- Quittez:                                                        \n");
              
                       
                       
                     

            printf("Entrer un Choix :\n");
                        scanf("%d", &c);
            
            switch (c)
            { 
                 
            case 1:
               ajoutertache(taches,nbt);
                
                
                break;
                case 2:
                afficherTaches1(taches,nbt);
                    system("pause");
                break;
         /*case 2:
               ajouterplusieurtache(taches,nbt);
                system("pause");
                break;    
           
            case 3:
               afficherTaches(taches,nbt);
                break;
                /*
            case 4:
               Modifiertache(taches,nbt);
                break; 
            case 5:
               Supprimertache(taches,nbt);
                break;
            case 6:
               Recherchertache(taches,nbt);
                break; 
            case 7:
               Statistiques(taches,nbt);
                break; */
             case 8:
               exit(0);
                 break;
                 default :
                 printf("Choix invalide. Veuillez entrer un choix valide.\n");
                 break;
                        
              
            }
           
} 
    return 0;
}
    


   


