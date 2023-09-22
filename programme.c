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
    int id;
    char  titre[100];
    char  description[100];
     char  statut[100];
    deadline deadline;     
}Tache;
int nombretache=0;
int last_id=0;
int index;
//fonction d'ajouter une nouvelle tâche:
void ajoutertache(Tache *tache){{
	   tache[nombretache].id =last_id+1;
   printf("Entrer le titre de tache %d:",nombretache+1);   
    scanf(" %[^\n]",&tache[nombretache].titre);
   
     printf("Entrez la description de la tache %d : ",nombretache+1);
    scanf(" %[^\n]", &tache[nombretache].description);
        printf("\nChoisissez le statut :\n",nombretache+1);
        printf("1 - A realiser\n");
        printf("2 - En cours de realisation\n");
        printf("3 - Finalisee\n");
        int choixStatut;     
        scanf("%d", &choixStatut);
        switch (choixStatut) {
            case 1:
                strcpy(tache[nombretache].statut, "a realiser");
                break;
            case 2:
                strcpy(tache[nombretache].statut, "en cours de raalisation");
                break;
            case 3:
                strcpy(tache[nombretache].statut, "finalisee");
                break;
            default:
                printf("Choix de statut invalide. Statut par defaut : a realiser\n");
                strcpy(tache[nombretache].statut, "a realiser");
                break;
        }
     printf("Entrer le delai jj/mm/aaaa %d:\n",nombretache+1);
    scanf("%d/ %d /%d", &tache[nombretache].deadline.jour, &tache[nombretache].deadline.mois, &tache[nombretache].deadline.annee); 
  last_id++;
    nombretache++;   
}}
// fonction d'ajouter plusieurs nouvelles tâches:
void ajouterplusieurtache(Tache *tache){
    int n_tacheajouter;
    printf("entrer le nombre des taches a ajouter:\n");
    scanf("%d",&n_tacheajouter);
    for(int i=0;i<n_tacheajouter;i++){
        ajoutertache(tache);
    }
}
//fonction afficher une seule tache:
/*void (Tache *tache){
int i;
		 printf("identifiant  de tache :%d\n",tache[i].id);
                printf("Titre de tache :%s\n",tache[i].titre);
                printf("Description de tache :%s\n",tache[i].description);
                printf("Statut de tache :%s\n",tache[i].statut);
                printf("delai de tache :%d/%d/%d\n",tache[i].deadline.jour,tache[i].deadline.mois,tache[i].deadline.annee);
}*/
//fonction afficher plusieurs tache:
void afficherplusieurtache(Tache *tache){
	for(int i=0;i<nombretache;i++){
		 		printf("identifiant  de tache :%d\n",tache[i].id);
                printf("Titre de tache :%s\n",tache[i].titre);
                printf("Description de tache :%s\n",tache[i].description);
                printf("Statut de tache :%s\n",tache[i].statut);
                printf("delai de tache :%d/%d/%d\n",tache[i].deadline.jour,tache[i].deadline.mois,tache[i].deadline.annee);
}}
//fonction trier par ordre alphabètique:
void Trieralphabetique(Tache *tache){
       Tache temp;
 for(int i=0;i<nombretache;i++){
 	for(int j=i+1;j<nombretache;j++){
 	 if(strcmp(tache[i].titre,tache[j].titre)>0){
                    temp = tache[i];
                tache[i]=tache[j];
                tache[j]=temp;  
            }	
	 }
}
}
//fonction trier par deadline:
void Trierpardeadline(Tache *tache){
    Tache temp;
    for(int i=0;i<nombretache;i++){
        for(int j=i+1;j<nombretache;j++){
            if(tache[i].deadline.annee>tache[j].deadline.annee){
			
			if(tache[i].deadline.mois>tache[j].deadline.mois) {
			
			   
                temp = tache[i];
                tache[i]=tache[j];
                tache[j]=temp;
            }
            
        }
    }
}
}
//Afficher les tâches dont le délai est dans 3 jours ou moins.
void afficherdeadline(Tache *tache){
int i,delai_jour, jours;
    time_t seconds=time(NULL);
    struct tm *current_time=localtime(&seconds);
    int currentYear = (current_time->tm_year + 1900);
    int currentMonth =(current_time->tm_mon + 1);
    int currentDay =current_time->tm_mday;

    for (i = 0; i < nombretache; i++){
        jours = tache[i].deadline.annee*365+tache[i].deadline.mois*30+tache[i].deadline.jour;
        delai_jour = jours-(currentYear*365+currentMonth*30+currentDay);
    
    if(delai_jour >0 && delai_jour <4){
    	printf("identifiant  de tache :%d\n",tache[i].id);
        printf("Titre de tache :%s\n",tache[i].titre);
        printf("Description de tache :%s\n",tache[i].description);
        printf("Statut de tache :%s\n",tache[i].statut);
        printf("delai de tache : dans %d jour(s)",delai_jour);
	}
}
}
//fonction afficher par choix:
void afficherTaches_parchoix(Tache *tache){
    	printf("\nChoisissez un tri :\n");
    	 printf("1 - Trier les taches par ordre alphabetique: \n");
        printf("2 - Trier les taches par date limite:\n");
        printf("3 - Afficher les tâches dont le délai est dans 3 jours ou moins: \n");
        
        int choixTri;
        scanf("%d", &choixTri);

        switch (choixTri) {
            case 1:
                Trieralphabetique( tache);
                 afficherplusieurtache(tache);

                break;
            case 2:
                  Trierpardeadline(tache);
                  afficherplusieurtache(tache);
                break;
            case 3:
            	afficherdeadline(tache);
            	break;
            	default:
                printf("Choix de tri invalide. \n");
 
}
}
//fonction Modifier la description d'une tache 
void Modifierdescription(Tache *tache){
    int ident;
	char newdescription[100];
    printf("entrer l identifiand de tache:\n");
	scanf("%d",&ident);
	printf("entrer nauvelle description de tache:\n");
	 scanf(" %[^\n]", &newdescription);
	
    for(int i=0;i<nombretache;i++){
        if(ident==tache[i].id){
        	index=i;
            strcpy(tache[index].description,newdescription);
        }else printf("cette tache est introuvable.");
    }    
    printf("Tache modifiee avec succes.\n");
      
}
//fonction Modifier statut d'une tache :
void Modifierstatut(Tache *tache){
    int ident;
    char newstatus[100];
    printf("entrer l identifiand de tache:\n");
    scanf("%d",&ident);
    printf("\n entrer la nouvelle statut :\n");
        printf("1 - A realiser\n");
        printf("2 - En cours de realisation\n");
        printf("3 - Finalisee\n");
        int choixStatut;
        
        scanf("%d", &choixStatut);

        switch (choixStatut) {
            case 1:
                strcpy(newstatus ,"a realiser");
                break;
            case 2:
                strcpy(newstatus, "en cours de raalisation");
                break;
            case 3:
                strcpy(newstatus, "finalisee");
                break;
            default:
                printf("Choix de statut invalide. Statut par defaut : a realiser\n");
                strcpy(tache[nombretache].statut, "a realiser");
                break;
        }
        
    for(int i=0;i<nombretache;i++){
        if(tache[i].id==ident){
            strcpy(tache[index].statut,newstatus);
        }else printf("cette tache est introuvable.");
    }printf("Tache modifiee avec succes.\n");
    
}
//fonction modifier deadline d'une tache:
void Modifierdeadline(Tache *tache){
	 int ident;
	 int j,m,a;
    printf("entrer l identifiand de tache:\n");
	scanf("%d",&ident);
	printf("Entrer le nouveau delai de tache jj/mm/aaaa:\n");
	  scanf("%d/ %d /%d",&j,&m,&a);
	   
	for(int i=0;i<nombretache;i++){
		if(tache[i].id==ident){
		index=i;
	
	  tache[index].deadline.jour=j;
	  tache[index].deadline.mois=m;
	  tache[index].deadline.annee=a;
}else printf("cette tache est introuvable.") ; 
}printf("Tache modifiee avec succes.\n");
    
}
//fonction modifier par choix:
void modifiertache_parchoix(Tache *tache){
    	printf("\nChoisissez un tri :\n");
    	printf("1 - Modifier la description d'une tache: \n");
        printf("2 - Modifier le statut d'une tache: \n");
        printf("3 - Modifier le delai d'une tache: \n");
        
        int choixmodif;
        scanf("%d", &choixmodif);

        switch (choixmodif) {
            case 1:
                Modifierdescription(tache);       
                break;
            case 2:
                  Modifierstatut(tache);
                break;
            case 3:
            	Modifierdeadline(tache);
            	default:
                printf("Choix de modification invalide. \n");
 
}
}
//fonction Supprimer une tache:
void  Supprimertache(Tache *tache){
     int ident;
	 printf("Entrer l identifiand de tache a supprimer:\n");
    scanf("%d",&ident);
    for(int i=0;i<nombretache;i++){
        if(ident==tache[i].id){
        	for (int j = i; j < nombretache-1; j++) {
        	index=j;
        	tache[index].id=tache[index+1].id;
        	strcpy(tache[index].titre,tache[index+1].titre);
        	strcpy(tache[index].description,tache[index+1].description);
        	strcpy(tache[index].statut,tache[index+1].statut);
        	tache[index].deadline.jour=tache[index+1].deadline.jour;
        	tache[index].deadline.mois=tache[index+1].deadline.mois;
        	tache[index].deadline.annee=tache[index+1].deadline.annee;    
        }
        nombretache--;
        
    
}else printf("cette tache est introuvable.");
}printf("Tache supprimee avec succes.\n");
}

//fonction Rechercher par identifiant:
void RechercherId(Tache *tache){
	int ident;
	printf("Entrer l identifiand de tache a rechercher:\n");
    scanf("%d",&ident);
	for(int i=0;i<nombretache;i++){
		if(tache[i].id==ident){
		       	printf("voila la tache :\n");
		    	printf("identifiant  de tache :%d\n",tache[i].id);
                printf("Titre de tache :%s\n",tache[i].titre);
                printf("Description de tache :%s\n",tache[i].description);
                printf("Statut de tache :%s\n",tache[i].statut);
                printf("delai de tache :%d/%d/%d\n",tache[i].deadline.jour,tache[i].deadline.mois,tache[i].deadline.annee);		
		}else printf("cette tache est introuvable.");
	}
}
//fonction Rechercher par titre:
void RechercherTitre(Tache *tache) {
	char t[200];
	printf("Entrer le titre de tache a rechercher:\n");
    scanf("%s",&t);
    for(int i=0;i<nombretache;i++){
		if(strcmp(t,tache[i].titre)==0){
		    	printf("voila la tache :\n");
		    	printf("identifiant  de tache :%d\n",tache[i].id);
                printf("Titre de tache :%s\n",tache[i].titre);
                printf("Description de tache :%s\n",tache[i].description);
                printf("Statut de tache :%s\n",tache[i].statut);
                printf("delai de tache :%d/%d/%d\n",tache[i].deadline.jour,tache[i].deadline.mois,tache[i].deadline.annee);
			
		}else printf("cette tache est introuvable.");
	}    
}
//fonction rechercher par choix:
void Recherchertache_parchoix(Tache *tache){
	printf("\nChoisissez un recherche :\n");
    	 printf("1 -Rechercher une tâche par son Identifiant: \n");
         printf("2 - Rechercher une tâche par son Titre: \n");
        
        
        int choixrech;
        scanf("%d", &choixrech);

        switch (choixrech) {
            case 1:
                RechercherId(tache);       
                break;
            case 2:
                 RechercherTitre(tache);
                break;
            	default:
                printf("Choix de recherche invalide. \n");
 
}
}
//Statistiques :
//fonction Afficher le nombre total des tâches
void afficher_nombretache(Tache *tache){
	printf("le nombre total des taches est :%d",nombretache);	
}
//fonction Afficher le nombre de tâches complètes et incomplètes.
void afficher_tacheci(Tache *tache){
	int nbr_cmp,nbr_inc=0;
	for(int i=0;i<nombretache;i++){
		if((strcmp(tache[i].statut,"a realiser")==0)||(strcmp(tache[i].statut, "en cours de raalisation"))==0){
			nbr_inc++;
			
		}else if((strcmp(tache[i].statut,"finalisee")==0)){
			nbr_cmp++;
		}
	}
	printf("Le nombre de taches incompletes:%d\n",nbr_inc);
	printf("Le nombre de taches completes:%d\n",nbr_cmp);
}
//fonction Afficher le nombre de jours restants jusqu'au délai de chaque tâche:
void afficher_jourrestants(Tache *tache){
	int i,delai_jour, jours;
    time_t seconds=time(NULL);
    struct tm *current_time=localtime(&seconds);
    int currentYear = (current_time->tm_year + 1900);
    int currentMonth =(current_time->tm_mon + 1);
    int currentDay =current_time->tm_mday;

    for (i = 0; i < nombretache; i++){
        jours = tache[i].deadline.annee*365+tache[i].deadline.mois*30+tache[i].deadline.jour;
        delai_jour = jours-(currentYear*365+currentMonth*30+currentDay);
		printf("identifiant  de tache :%d\n",tache[i].id);
        printf("Titre de tache :%s\n",tache[i].titre);
        printf("Description de tache :%s\n",tache[i].description);
        printf("Statut de tache :%s\n",tache[i].statut);
        printf("delai de tache : dans %d jour(s)",delai_jour);
	}	}


//Statistiques :
void Statistiques(Tache *tache){
	printf("\nChoisissez un tri :\n");
    	 printf("1 - Afficher le nombre total des taches: \n");
         printf("2 - Afficher le nombre de taches completes et incompletes: \n");
         printf("3 - Afficher le nombre de jours restants jusqu'au delai de chaque tache:\n");
        
        int choix_st;
        scanf("%d", &choix_st);

        switch (choix_st) {
            case 1:
                afficher_nombretache(tache);       
                break;
            case 2:
                 afficher_tacheci(tache);
                break;
            case 3:
            	afficher_jourrestants(tache);
            
            	break;
					
            default:
                printf("Choix invalide. \n");
 
}
}
int main(){
	Tache tache[100];
    int c1=0;
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
    
              
              printf("Entrer un Choix :");
                        scanf("%d", &c1);
              switch (c1){
              	case 1:ajoutertache(tache);
              	break;
              	
              	case 2:ajouterplusieurtache(tache);
              	break;
              
              		case 3:afficherTaches_parchoix(tache);
              	break;
              
              		case 4:modifiertache_parchoix(tache);
              	break;
              	
              		case 5:Supprimertache(tache);
              	break;
              	
              		case 6:Recherchertache_parchoix(tache);
              	break;
              
              		case 7:Statistiques(tache);
              	break;
                 default :
                 printf("Choix invalide. Veuillez entrer un choix valide.\n");
                
                 break;			  
	}
		}
		return 0;
		}