# Fonctionnement du système expert

---
Dans cette section, nous allons vous expliciter le fonctionnement de notre **système expert** en détaillant chaque étape de son fonctionnement.


## Préliminaire

---
Avant tout, il faut définir de quel type sera notre donnée. Pour cela il vous suffit de suivre l'éxemple suivant :
`````c
#include <stdlib.h>
#include <DB.h>

typedef struc{
    int value_1;
    ...
    int value_n;
}myType;

int main(){
    myType* elm = malloc(sizeof(myType));
    elm->value_1 = 3;
    ...
    elm->value_n = 12;
}
`````
Ici `elm` est utilisable par notre système expert.

Il vous faut aussi définir un pointeur de fonction pour comparer les éléments que l'on insère. Pour cela, il vous suffit de suivre cet exemple :
`````c
#include <stdlib.h>
#include <DB.h>

int getSUMValue(myType* var){
    return var->value_1 + ... + var->value_n;
}

Bool cmp(void* p1, void* p2){
    if(getSUMValue(p1) == getValue(p2)){
        return True;
    }else{
        return False;
    }
}

int main(){
    Bool (*fnPointer)(void*,void*);
    fnPointer = cmp;
}
`````
Maintenant `fnPointer` est utilisable par les fonctions nécessitant un pointeur de fonction.

Mais avant de faire fonctionner notre système expert, il faut créer deux choses éssentiels :
* une **liste de fait**
* une **base de connaissances**


Regardons alors quels sont leurs roles et comment les créer.

---
### La **liste de fait**

Une liste de fait est la base de tout système expert, elle permet de définir les données utilisées par les conclusions et prémises des règles. 

Dans notre système expert toutes les conclusions et prémises sont tirée de cette liste de fait et doivent donc **être créée en premier**. Le type de la liste de fait est `FactList`.

Pour vous aider à sa création, vous avez à votre disposition plusieurs fonctions :
* `createFactList(Bool (*cmpValue)(void*, void*))` pour créer une liste de fait vide avec `cmpValue` qui est un pointeur sur la fonction de comparaison que vous avez définie.
* `addFact(FactList list,*void fact)` pour ajouter une propriété(`fact`) a une liste de fait(`list`). Vous pouvez utiliser la meme variable `fact` en changent ça valeur sans problems.
* `removeAllFacts(FactList list)` pour supprimer tous les fait d'une liste de fait.

Il y a aussi des fonctions qui intéragissent avec le type `FactList` :
* `isAlreadyInFactList(FactList list, void* fact)` qui vérifie si l'élément est dans la liste de fait avec le pointeur de fonction et revoie un `*void`. 
* `isPresentInFactList(FactList list, void* fact);` qui vérifie si l'élément est dans la liste de fait avec l'emplacement mémoire et revoie un `*void`
* `getById(FactList list, long id)` qui renvoie l'élément associé à l'`id`;.

>Pour plus de détail sur les fonctions merci de regarder les algorithms commenter [ici](Alogrithm.md)

---
### La **base de connaissance**

Une fois notre liste de fait créer il nous faut établir des relations entre les différents faits. Nous allons alors réaliser des règles que nous allons ensuite stocker dans une base de connaissance.

Commençons par créer une règle. Le type d'une **règle** est `Rule` et ces fonctions sont disponibles pour aider à les créer :
* `createEmptyRule(FactList facts)` qui créer une règle vide avec une liste de fait associée (`facts`).
* `addPremise(Rule* rules,void* premise)` qui ajoute une prémise tiré d'une liste de fait à la liste de prémises.
* `setConclusion(Rule* rule, void* conclusion)` qui permet de définir une conclusion tirée d'une liste de fait.
* `removeFromPremise(Rule* rule,void* premise)` qui retire une prémise si elle est présente.


Il y a aussi des fonctions qui intéragissent avec le type `Rule` :
* `isPremiseEmpty(Rule* rule)` qui renvoie un `Bool` et dit si la prémise est vide.
* `getConclusion(Rule* rule)` qui renvoie la conclusion de type `void*`.
* `getFactListOfRule(Rule* rule)` qui renvoie la liste de fait associée à la règle de type `FactList`.

>Pour plus de détail sur les fonctions merci de regarder les algorithms commenter [ici](Alogrithm.md)

Une fois notre règle créée, il ne reste plus qu'à ajouter cette règle à une base de connaissance. Regardons comment créer une base de connaissance de type `DB`.

Voici les fonctions qui permettent sa conception :
* `createEmptyBC(FactList facts)` pour créer une base de connaissance vide avec une liste de faits associée.
* `addRuleToBC(DB bc,Rule* rule)` pour ajouter une règle à la base de connaissance.
* `DB copyOfBC(DB bc)` pour renvoyer une copie une base de connaissance.

Il y a aussi des fonctions qui intéragissent avec le type `DB` :
* `getFactListOfDB(DB bc)` qui renvoie la liste de fait associée à la base de connaissance de type `FactList`.

>Pour plus de détail sur les fonctions merci de regarder les algorithms commenter [ici](Alogrithm.md)

>[!WARNING]
> 
> Les listes de faits (`FactList`) sont comparées quand on applique des ajouts d'éléments pour s'assurer qu'ils sont issue de la même liste. Veillez donc à toujours utiliser la même liste de faits.


>[!TIP]
> 
> Vous pouvez retrouver [ici](Function.md) toutes les fonctions et leurs utilities et éventuellement plus de détail.


## Fonctions utiles

---
### Les fonctions de libération de mémoire 

Pour libérer la mémoire utilisée par notre système expert, il faut utiliser les fonctions suivantes :
* `freeFactList(FactList list)` pour libérer la mémoire utilisée par une liste de fait.
* `freeRule(Rule rule)` pour libérer la mémoire utilisée par une règle.
* `freeDB(DB bc)` pour libérer la mémoire utilisée par une base de connaissance.
>Pour plus de détail sur les fonctions merci de regarder les algorithms commenter [ici](Function.md)

---
### Les fonctions pour parcourir les listes 

Pour parcourir une **règle**, il faut utiliser les fonctions suivantes :
* `getHeadOfPremise(Rule rule)` pour récupérer la tête de la liste de prémises.
* `getNextOfPremise(ElmOfPremise* rule)` pour récupérer l'élément suivant de la liste de prémises.
* `getPremise(ElmOfPremise* elm)` pour récupérer le fait de l'élément de la prémisse.

Pour parcourir une **base de connaissance**, il faut utiliser les fonctions suivantes :
* `getHeadRule(DB bc)` pour récupérer la tête de la liste de règles.
* `getNextRule(ElmOfDB* elm)` pour récupérer l'élément suivant de la liste de règles.
* `getRule(ElmOfDB* elm)` pour récupérer la règle de l'élément de la base de connaissance.

>Pour plus de détail sur les fonctions merci de regarder les algorithms commenter [ici](Function.md)

---
### Les fonctions pour récupérer une liste de fait

Pour récupérer une **liste de fait**, il faut utiliser les fonctions suivantes :
* `getFactListOfRule(Rule* rule)` pour récupérer la liste de fait associée à la règle.
* `getFactListOfDB(DB bc)` pour récupérer la liste de fait associée à la base de connaissance.

>Pour plus de détail sur les fonctions merci de regarder les algorithms commenter [ici](Function.md)


## Fonctionnement du système expert

---
### Avant d'appeler le système expert

Avant de faire fonctionner notre système expert merci de créer 3 liste de fait :
* une qui contient tous les faits
* une qui contient les fait que l'on veut tester
* une pour le résultat du système expert 

Il faudra aussi créer une base de connaissance.

>À chaque utilisation la base de connaissance est alter, il faut donc la recréer à chaque fois où la copier avec la fonction `copyOfBC`.

---
### Pendant l'exécution

Lors de l'exécution une **pile** va être créé qui va contenir tous les fait que l'on souhaite tester. 

Le programme va alors **dépiler** un élément et regarder si, pour chaque élement de la base de connaissance, la prémise contient ce fait :
* si oui l'élément est retiré de la prémise et le programme vérifie si la prémise de la règle est vide :
    * si oui alors cela veut dire que la règle est vérifiée et ensuite, elle est ajoutée à la conclusion et sur la **pile** pour d'éventuelles occurrences dans d'autres règles et le programme passe à l'élément suivant.
    * sinon le programme continue sur l'élément suivant.
* sinon le programme passe à la règle suivante.

Une fois que la pile est vide le programme nous retourne sa liste de conclusion et un code de réussite (`0`).

---
### Les codes d'erreur





