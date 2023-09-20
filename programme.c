#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <time.h>
typedef struct {
    int jour;
    int mois;
    int annee;
}deadline;


typedef struct {
    int id[20];
    char  titre[100];
    char  description[100];
    deadline deadline;
    char  statut[100];   
}Tache;

void ajoutertache(Tache taches[],int nbt){
    Tache t;
    printf("entrer l identifiant de tache:\n");
    scanf("%d",&taches[nbt].id);
    printf("entrer le titre de titre:\n");   
    scanf("%s",&taches[nbt].titre);
    printf("entrer la description de tache:\n");
    scanf("%s",&taches[nbt].description);
    printf("entrer la date de deadline:\n");
    scanf("%d %d %d", &taches[nbt].deadline.jour, &taches[nbt].deadline.mois, &taches[nbt].deadline.annee);
    taches[nbt]=t;
    ++nbt;
}
void ajouterplusieurtache(Tache taches[],int nbt){
    int tacheajouter;
    for(int i=0;i<tacheajouter;++i){
        ajoutertache(taches,nbt);
        nbt++;
    }
}
void Trieralphabetique(Tache taches[],int nbt){
    Tache temp;
    for(int i=0;i<nbt;i++){
        for(int j=0;j<nbt-1;j++){
            if(taches[j].titre>taches[j+1].titre){
                 temp=taches[j];
                taches[j]=taches[j+1];
                taches[j+1]=temp;
            }
        }
    }
}void Trierpardeadline(Tache taches[],int nbt){
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
     for ( int i = 0; i < nbt; i++){
       Trieralphabetique(taches,nbt);
}
     for ( int i = 0; i < nbt; i++){
       Trierpardeadline(taches,nbt);
}
    for ( int i = 0; i < nbt; i++){
      dead=

    }


}
int main(){
    return 0;
}
    


   


