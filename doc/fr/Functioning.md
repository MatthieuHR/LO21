# Fonctionnement du système expert

---
Dans cette section, nous allons vous expliciter le fonctionnement de notre **système expert** en détaillant chaque étape de son fonctionnement.

>[!NOTE]
>
>Dans cette section le type de notre **fait** est représenter par `void*` pour faire l'analogie avec le C même si cela n'est pas correct algorithmiquement parlant.
>
>De plus toutes les fonctions sont nommée en fonction de leur implémentation C.


## Préliminaire

---
### Petit passage par le C

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

Une liste de fait est la base de tout système expert, elle permet de définir les données utilisées par les conclusions et prémisses des règles. 

Dans notre système expert toutes les conclusions et prémisses sont tirée de cette liste de fait et doivent donc **être créée en premier**. Le type de la liste de fait est `FactList`.

Pour vous aider à sa création, vous avez à votre disposition plusieurs fonctions :
* `createFactList((*cmpValue)(void*, void*):Bool):FactList` pour créer une liste de fait vide avec `cmpValue` qui est un pointeur sur la fonction de comparaison que vous avez définie.
* `addFact(list:FactList, fact:void*):FactList` pour ajouter une propriété (`fact`) a une liste de fait (`list`). Attention chaque fait doit avoir une adresse mémoire unique.
* `removeAFact(list:FactList, fact:void*):FactList` pour supprimer une propriété (`fact`) d'une liste de fait (`list`).
* `removeAFactById(list:FactList, id:LongInteger):FactList` pour supprimer une propriété (`fact`) d'une liste de fait (`list`) par rapport à son `id`.
* `removeAllFacts(list:FactList):FactList` pour supprimer tous les fait d'une liste de fait.
* `removeAllFactsAndFree(list:FactList):FactList` pour supprimer tous les fait d'une liste de fait et le fait. **Attention à ne pas si le fait est utilisé ailleurs**.

Il y a aussi des fonctions qui intéragissent avec le type `FactList` :
* `isAlreadyInFactList(list:FactList, fact:void*):Bool` qui vérifie si l'élément est dans la liste de fait avec le pointeur de fonction et revoie un `Bool`. 
 `isPresentInFactList(list:FactList, fact:void*):Bool` qui vérifie si l'élément est dans la liste de fait avec l'emplacement mémoire et revoie un `Bool`
* `getFactById(list:FactList, id:LongInteger):void*` qui renvoie l'élément associé à l'`id`;.

>Pour plus de détail sur les fonctions merci de regarder les algorithms commenter [ici](Alogrithm.md)

---
### La **base de connaissance**

Une fois notre liste de fait créer il nous faut établir des relations entre les différents faits. Nous allons alors réaliser des règles que nous allons ensuite stocker dans une base de connaissance.

Commençons par créer une règle. Le type d'une **règle** est `Rule` et ces fonctions sont disponibles pour aider à les créer :
* `createEmptyRule(facts:FactList):Rule` qui créer une règle vide avec une liste de fait associée (`facts`).
* `addPremise(rules:Rule, premise:void*):Rule` qui ajoute une prémise tiré d'une liste de fait à la liste de prémises.
* `setConclusion(rule:Rule, conclusion:void*):Rule` qui permet de définir une conclusion tirée d'une liste de fait.
* `removeFromPremise(rule:Rule, premise:void*):Rule` qui retire une prémise si elle est présente.


Il y a aussi des fonctions qui intéragissent avec le type `Rule` :
* `isEqualsRule(rule1:Rule, rule2:Rule)Bool` qui renvoie un `Bool` et dit si les deux règles sont identiques.
* `isPremiseEmpty(rule:Rule):Bool` qui renvoie un `Bool` et dit si la prémise est vide.
* `getConclusion(rule:Rule):void*` qui renvoie la conclusion, un fait.

>Pour plus de détail sur les fonctions merci de regarder les algorithms commenter [ici](Alogrithm.md)

Une fois notre règle créée, il ne reste plus qu'à ajouter cette règle à une base de connaissance. Regardons comment créer une base de connaissance de type `DB`.

Voici les fonctions qui permettent sa conception :
* `createEmptyDB(facts:FactList):DB` pour créer une base de connaissance vide avec une liste de faits associée.
* `addRuleToDB(db:DB, rule:Rule):DB` pour ajouter une règle à la base de connaissance.
* `removeARule(db:DB, rule:Rule):DB` qui permet d'enlever une règle de la base de connaissance. Attention, la règle n'est pas libérée de la mémoire, il faut donc la récupérer avant de l'enlever pour éviter de la perdre en mémoire.
* `removeARuleById(db:DB, id:LongInteger):DB` qui permet d'enlever une règle de la base de connaissance par rapport à son `id`. Attention, la règle est libérée en mémoire.
* `removeAllRules(db:DB):DB` qui permet d'enlever toutes les règles de la base de connaissance. Attention, les règles sont libérées en mémoire.
* `DB copyOfDB(db:DB):DB` pour renvoyer une copie une base de connaissance.

Il y a aussi des fonctions qui intéragissent avec le type `DB` :  
* `isPresentInDB(db:DB, fact;void*):Bool` qui renvoie un `Bool` et dit si le fait est présent dans la base de connaissance par rapport à l'objet lui-même.
* `isAlreadyInDB(db:DB, fact:void*):Bool` qui renvoie un `Bool` et dit si le fait est présent dans la base de connaissance par rapport à ses champs.
* `getRuleById(db:DB, id:LongInteger):Rule` qui renvoie la règle associée à l'id.

>Pour plus de détail sur les fonctions merci de regarder les algorithms commenter [ici](Alogrithm.md)

>[!WARNING]
> 
> Les listes de faits (`FactList`) sont comparées quand on applique des ajouts d'éléments pour s'assurer qu'ils sont issue de la même liste. Veillez donc à toujours utiliser la même liste de faits.


>[!TIP]
> 
> Vous pouvez retrouver [ici](Function.md) toutes les fonctions implémenter en C et leurs utilities et éventuellement plus de détail.


## Fonctions utiles

---
### Les fonctions de libération de mémoire 

Pour libérer la mémoire utilisée par notre système expert, il faut utiliser les fonctions suivantes :
* `freeFactList(list:FactList)FactList` pour libérer la mémoire utilisée par une liste de fait.
* `freeRule(rule:Rule):FactList` pour libérer la mémoire utilisée par une règle.
* `freeDB(db:DB):FactList` pour libérer la mémoire utilisée par une base de connaissance.
>Pour plus de détail sur les fonctions merci de regarder les implémentations C commenter [ici](Function.md) ou algorithmes [ici](Alogrithm.md)

---
### Les fonctions pour parcourir les listes 

Pour parcourir une **liste de fait**, il faut utiliser les fonctions suivantes :
* `getHeadOfFactList(list:FactList):ElmOfFactList` pour récupérer la tête de la liste de fait.
* `nextFact(elm:ElmOfFactList):ElmOfFactList` pour récupérer l'élément suivant de la liste de fait.
* `getFact(elm:ElmOfFactList):void*` pour récupérer le fait de l'élément de la liste de fait.
* `getIdOfFact(elm:ElmOfFactList):LongInteger` pour récupérer l'id de l'élément de la liste de fait.
>Pour plus de détail sur les fonctions merci de regarder les implémentations C commenter [ici](Function.md)

Pour parcourir une **règle**, il faut utiliser les fonctions suivantes :
* `getHeadOfPremise(rule:Rule):ElmOfPremise` pour récupérer la tête de la liste de prémises.
* `getNextOfPremise(rule:ElmOfPremise):ElmOfPremise` pour récupérer l'élément suivant de la liste de prémises.
* `getPremise(elm:ElmOfPremise):void*` pour récupérer le fait de l'élément de la prémisse.
* `getCoclusion(rule:Rule):void*` pour récupérer la conclusion de la règle.
>Pour plus de détail sur les fonctions merci de regarder les implémentations C commenter [ici](Function.md)

Pour parcourir une **base de connaissance**, il faut utiliser les fonctions suivantes :
* `getHeadRule(db:DB):ElmOfDB` pour récupérer la tête de la liste de règles.
* `getNextRule(elm:ElmOfDB):ElmOfDB` pour récupérer l'élément suivant de la liste de règles.
* `getRule(elm:ElmOfDB):Rule` pour récupérer la règle de l'élément de la base de connaissance.
* `getIdOfRule(elm:ElmOfDB):LongInteger` pour récupérer l'id de l'élément de la base de connaissance.
>Pour plus de détail sur les fonctions merci de regarder les implémentations C commenter [ici](Function.md)

---
### Les fonctions pour récupérer une liste de fait

Pour récupérer une **liste de fait**, il faut utiliser les fonctions suivantes :
* `getFactListOfRule(rule:Rule):FactList` pour récupérer la liste de fait associée à la règle.
* `getFactListOfDB(db:DB):FactList` pour récupérer la liste de fait associée à la base de connaissance.
>Pour plus de détail sur les fonctions merci de regarder les implémentations C commenter [ici](Function.md)

>[!NOTE]
>
>Ces fonctions ne possède pas d'algorithms car sont des fonctions très basique.


## Fonctionnement du système expert

---
### Avant d'appeler le système expert

Avant de faire fonctionner notre système expert merci de créer deux liste de fait :
* une qui contient les fait que l'on veut tester
* une pour stocker le résultat du système expert 

Il faudra aussi créer une base de connaissance.

>À chaque utilisation la base de connaissance est alter, il faut donc la recréer à chaque fois où la copier avec la fonction `copyOfDB()`.

---
### Pendant l'exécution

Commencer par lancer le système expert avec cette fonction : `expertSystem(factsToTest:FactList, resultFacts:FactList, knowledgeBase:DB)`

Lors de l'exécution la liste de fait `factsToTest` va nous servir de **pile** pour tester chercher les faits.

Le programme va alors **dépiler** un élément et regarder si, pour chaque élement de la base de connaissance, la prémise contient ce fait :
* si oui l'élément est retiré de la prémise et le programme vérifie si la prémise de la règle est vide :
    * si oui alors cela veut dire que la règle est vérifiée et ensuite, elle est ajoutée à la conclusion et sur la **pile** pour d'éventuelles occurrences dans d'autres règles et le programme passe à l'élément suivant.
    * sinon le programme continue sur l'élément suivant.
* sinon le programme passe à la règle suivante.

Une fois que la pile est vide le programme nous retourne sa liste de conclusion et un code de réussite (`0`).

---
### Les codes d'erreur

---
C'est tout pour cette section, vous pouvez passer à la section suivante : [Algorithmes des sous programmes](Algorithm.md).