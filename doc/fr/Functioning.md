# Fonctionnement du système expert

---
Dans cette section nous allons vous explicitée le fonctionnement de notre **système expert** en détaillant chaque étape de son fonctionnement.


## Préliminaire

---
Avant de faire fonctionner notre système expert, il faut créer deux choses éssentiels :
* une **liste de fait**
* une **base de connaissances**


Regardons alors quels sont leurs roles et comment les créer.

---
### La **liste de fait**

Une liste de fait est la base de tout système expert, elle permet de définir les données utilisées par les conclusions et prémises des règles. 

Dans notre système expert toutes les conclusions et prémises sont tirée de cette liste de fait et doit donc **être créer en premier**. Le type de la liste de fait est `FactList`.

Pour vous aider à sa création vous avez à votre dispositions plusieurs fonctions :
* `createFactList()` pour créer une liste de fait vide (sans éléments).
*  `addFact(FactList list,Property fact)` pour ajouter une propriétée(`fact`) a une lsite de fait(`list`). Vous pouver utiliser la meme variable `fact` en changent ça valeur sans soucis.
*  `remouveAllFacts(FactList list)` pour supprimer tous les fait d'une liste de fait.
*  `transferFact(FactList list, Property* fact)` pour transférer un fait déjà existant d'une liste de fait vers une une autre avec son pointeur.

Il y a aussi des fonctions qui intéragissent avec le type `FactList` :
* `isInFactList(FactList list, Property* fact)` qui vérifie si l'élément est dans la liste de fait et revoie un `Bool`. 

>Pour plus de détail sur les fonctions merci de regarder les algorithms commenter [ici](Alogrithm.md)

---
### La **base de connaissance**

Une fois notre liste de fait créer il nous faut établir des relations entre les différents faits. Nous alons alors réaliser des règles que nous allons ensuite stocker dans une base de connaissance.

Commençons par créer une règle. Le type d'une **règle** est `Rule` et ces fonctions sont disponibles pour aider à les créer :
* `createEmptyRule()` qui créer une règle vide.
* `addPremise(Rule* rules,Property* premise)` qui ajoute une prémise tiré d'une liste de fait à la liste de prémises.
* `createConclusion(Rule* rule, Property* conclusion)` qui permet de définir une conclusion tirée d'une liste de fait.
* `remouvePremise(Rule* rule,Property* premise)` qui retire une prémise si elle est présente.
* `BC copyOfBC(BC bc)` pour renvoyer une copie une base de connaissance.

Il y a aussi des fonctions qui intéragissent avec le type `Rule` :
* `PropertiesInPremise(Premise premise, Property* prop)` qui vérifie si un fait(`prop`) est dans la prémise et renvoie un `Bool`.
* `isPremiseEmpty(Rule* rule)` qui renvoie un `Bool` et dit si la prémise est vide.
* `getHeadOfPremise(Rule* rule)` qui renvoie le première élément de la prémise de type `ElmOfPremise*`.
* `getConclusion(Rule* rule)` qui renvoie la conclusion de type `Property*`.

>Pour plus de détail sur les fonctions merci de regarder les algorithms commenter [ici](Alogrithm.md)

Une fois notre règle créer il ne reste plus qu'a ajouter cette règle a une base de connaissance. Regardons comment créer une base de connaissance de type `BC`.

Voici les fonctions qui permets sa conception :
* `createEmptyBC()` pour créer une base de connaissance vide.
* `addRuleToBC(BC bc,Rule* rule)` pour ajouter une règle à la base de connaissance.

Il y a aussi des fonctions qui intéragissent avec le type `BC` :
* `getHeadRule(BC bc)` qui donne la première règle d'une base de connaissance.

>Pour plus de détail sur les fonctions merci de regarder les algorithms commenter [ici](Alogrithm.md)

## Fonctionnement du système expert

---
### Avant d'appeler le système expert

Avant de faire fonctionner notre système expert merci de créer 3 liste de fait :
* une qui contient tous les faits
* une qui contient les fait que l'on veut tester
* une pour le résultat du système expert 

Il faudra aussi créer une base de connaissance.

>A chaque utilisation la base de connaissance est alterrée il faut donc la recréer à chaque fois ou la copier avec la fonction `copyOfBC`.

---
### Pendant l'exécution

Lors de l'exécution une **pile** va être créé qui va contenir tous les fait que l'on souhaite tester. 

Le programme va alors **dépiler** un élément et regarder si, pour chaque élement de la base de connaissance, la prémise contient ce fait :
* si oui l'élément est retirer de la prémise et le programme vérifie si la prémise de la règle est vide :
    * si oui alors cela veut dire que la règle est vérifier et alors elle est ajoutée aux conclusion et sur la **pile** pour d'éventuels occurence dans d'autres regles et le programme passe a l'élément suivant.
    * si non le programme continue sur l'élément suivant.
* si non le programme passe à la règle suivante.

Une fois que la pile est vide le programme nous retourne sa liste de conclusion et un code de réussite (`0`).

---
### Les codes d'erreur


## Les fonctions utiles

---





