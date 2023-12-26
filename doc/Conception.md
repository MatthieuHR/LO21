# Choix de conception

---
Dans cette section, nous allons détailler les choix de conceptions et d'implémentation des structures de données utilisées et la démarche adoptée pour les choisir.


## Analise du sujet

---
Après une analise rapide du sujet, nous avons remarqué qu'un parcours récursif de liste était nécessaire donc qu'une structure de liste simple serait favorables.

De plus nous avons aussi remarqué que les algorithms ne tirait pas d'avantages en termes de performances entre des listes simplement chainées et doublement chainées. Seul l'algorithme de suppression dans une liste est plus simple avec une liste doublement chainée.


## Choix final

---
### Représentation des listes
Pour notre choix final nous avons décidé de réaliser uniquement des listes simplement chainées avec un unique champs de valeur et un type liste qui est uniquement un pointeur sur la structure étant définie comme un éléments de la liste. Cela nous donne une structure générique de type : 
```c
typedef struct elm{
    type value;
    struct elm* next;
}ElementOfList;

typedef ElementOfList* List;
```
Dans notre cas les structures comme `Regles` et `ElmOfFact` ont des pointeurs sur une structure `Properties` pour pouvoir au besoin comparer les emplacements mémoire si c'est le mode de comparaison choisi pour l'implementation

---
### Implementation de la donnée "fait"
En parlant de la structure `Properties`, cette dernière représente le type de donner que l'on souhaite utiliser en tant que fait pour notre moteur expert donc tous peut être mis dedans et alors il faut modifier les fonctions suivantes:
* `isEmptyProperty` qui définie ce qu'est une `Properties` vide
* `cmpProperty` qui définie comment est comparer deux `Properties`
* `printProperties` qui défini un affichage pour une `Properties`

## Les structures implémenters et explication

---
### Fichier `FactList.h`
La structure `Properties` qui représente un fait et donc peut contenir ce que l'on souhaite. Pour un exemple, merci de regarder la [section test](Test.md).
````c
typedef struct {
    type name;
    ...
    type name;
}Properties;
````
La structure `ElmOfFact` définie un élément de la liste des faits. En complement la structure `FactList` sert à définir en la liste de fait en elle même.
````c
typedef struct elm{
    Properties* fact;
    struct elm* next;
}ElmOfFact;

typedef ElmOfFact* FactList;
````

---
### Fichier `Rules.h`
La structure `ElmOfPremise` sert à définir un élément de la liste qui a pour type `Premise` et qui est seulement un pointeur. Dans ce cas l'élément passer au champs `value` doit provenir d'une `FactList`.
````c
typedef struct elm{
    Properties* value;
    struct elm* next;
}ElmOfPremise;

typedef ElmOfPremise * Premise;
````
La structure `Rules` sert à définir une règle avec ça `premise` de type `Premise` et sa `conclusion` qui vien aussi d'une `FactList`.
````c
typedef struct{
    Premise premise;
    Properties* conclusion;
}Rules;
````

---
### Fichier `BC.h`
La structure `ElmBC` représente un élément d'une **Base de Connaissance**. Une **Base de Connaissance** est une liste de règle représenté par le type `BC`.
````c
typedef struct elm{
    Rules* rule;
    struct elm* next;
}ElmBC;

typedef ElmBC * BC;
````

---
C'est tout pour cette section, vous pouvez passer a la section suivante : [Fonctionnement du système expert](Functioning.md)


