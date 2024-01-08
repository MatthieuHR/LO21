# Choix de conception

---
Dans cette section, nous allons détailler les choix de conceptions et d'implémentation des structures de données utilisées et la démarche adoptée pour les choisir.


## Analise du sujet

---
Après une analise rapide du sujet, nous avons remarqué qu'un parcours récursif de liste était nécessaire donc qu'une structure de liste simple serait favorables.

De plus nous avons aussi remarqué que les algorithms ne tirait pas d'avantages en termes de performances entre des listes simplement chainées et doublement chainées. Seul l'algorithme de suppression dans une liste est plus simple avec une liste doublement chainée.

Nous avons aussi remarqué qu'un accès en queue pour les listes serait intéressant, car il est imposé pour certaines fonctions de faire un ajout en queue.


## Choix final

---
### Représentation des listes et autres implémentations.
Pour représenter les listes le plus logique nous à semblés de garder des listes **simplement chainées**, car des listes doublements chainées n'apportent que peu d'avantages. Nous précisons plus loins la structure de chaque liste et ce qui nous à motiver à faire ce choix.

Cependant, malgré le fait que garder des structures des listes les plus simples possibles apporte des avantages, nous avons décidés que chaque liste devra contenir une **liste de fait** pour s'assurer que chaque élément interagisse bien avec ça liste de fait.

>[!NOTE]
> 
> Nous ne voulions pas imposer la création d'une base connaissance avant de créer les règles et la liste de fait, car nous estimions que l'un peut exister sans l'autre.

En parlant de liste de fait, nous avons décidé de rajouter un type `FactList` qui n'était pas demandé, mais qui sert à contenir tous les faits pour les prémisses et conclusions. Ce type est aussi utile pour vérifier que les base de connaissances et règles se base sur les meme faits et éviter de perdre tous les faits en mémoire.

Nous avons aussi rajouté le type `Boolean` pour booléan qui fonctionne comme un `1` et `0` en C ou `True` vaux `1` et `False` il vaut `0`.

---
### Implementation de la donnée "fait"
Nous avons longuement réfléchi à implémenter un fait sans que celui-ci soit handicapent si on voulait y ajouter des informations. 

C'est pour quoi nous n'avons attribué aucun type défini à cette donnée. À la place, nous laissons l'utilisateur choisir quelle donnée il souhaite utiliser et comment il définit l'égalité entre cette donnée avec un pointeur de fonction.

>[!NOTE]
>
>La donnée est alors représentée en C par un pointeur sur void : `void*`

Nous avons tous de meme une fonction qui interagissent avec ce type non défini :
* `isUndefinedProperty(fact)` qui dit si le fait en paramètre (`fact`) est indéfinie.


## Types implémentés

Voici un récapitulatif des types implémenté et leurs utilités (sans distinctions entre pointeur et type). Nous avons aussi décrété que toutes ces structures portrait être indéfinie (`NULL` en C).

>[!NOTE]
>
>`Type` désigne le type de notre fait.

---
### `FactList`

Ce type est une **pile** de `ElmOfFact` de taille non définit.

Il y a cinq champs :
* `head:ElmOfFact` le première élement de la liste.
* `last_id:LongInteger` qui est le dernier `id` donnée à un `ElmOfFact`. Par défaut sa valeur est à -1 quand aucun `id` n'a été distribuer.
* `cmpValue:function` qui est une fonction de comparaison entre deux faits
* `isEmpy:function` qui est une fonction qui dit si la liste est vide.
* `freeValue:function` qui est une fonction qui libère la mémoire d'un fait

Une `FactList` est une liste de faits qui servent de base pour les autres types.

Nous avons choisi cette implementation car la structure d'une **pile** est suffisante dans ce cas, comme aucune obligation d'implémentation était spécifiée et cela rend les algorithmes plus simples. De plus seuls les champs essentiels sont présents. Le champ `last_id` pourrait être remplacé par une accession à l'`id` du premier élément de la liste, mais cela complique le code et le champ `last_id` aura toujours une valeur ce qui évite des vérifications avec un access à la tete de liste.

Les trois derniers champs sont des fonctions que l'utilisateur doit renseigner afin de garantir le fonctionnement du système expert. Nous allons détailler leurs 3 roles :
* `cmpValue` permet de définir comment comparer deux éléments par valeur. Cette fonction est utilisée pour savoir si un fait ayant déja les mêmes valeurs n'est pas présent dans une liste avant de l'ajouter. Doit renvoyer `True` s'ils sont égaux et `False` sinon. Le prototype est le suivant : `theFunction(fact1:Type , fact2:Type):Boolean`
* `isEmpty` permet de définir si un élément est vide donc si ses champs sont vides ou quels champs doivent l'être. Doit renvoyer `True` s'il est vide et `False` sinon. Le prototype est le suivant : `theFunction(fact:Type):Boolean`
* `freeValue` doit permettre de libérer entièrement les champs et l'élément lui-même. Ne renvoie rien. Le prototype est le suivant : `theFunction(fact:Type):UNDEFINED`

---
### `ElmOfFact`

Ce type est composé de trois champs :
* `id:LongInteger` qui est l'identifiant unique de cet élément.
* `fact:Type` qui est de type `Property` et qui représente un **fait**, une donnée.
* `next:ElmOfFact` qui représente l'élément suivant de la liste.

Un `ElmOfFact` représenté un élément d'une liste de type `FactList`.

Nous avons choisi cette implémentation, car une liste simplement chainée suit. Le champ `id` est juste là pour rendre plus pratique l'utilisation de la structure `FactList` par un humain, comme aucune fonction de base ne se sert comme référence.

---
### `Premise`

Ce type est une liste de `ElmOfPremise` de taille non définit. 

Il possède deux champs :
* `head:ElmOfPremise` qui permet d'accéder au premier élément.
* `tail:ElmOfPremise` qui permet d'accéder au dernier élément.
* `last_id:LongInteger` qui est le dernier `id` donnée à un `ElmOfPremise` et il vaut `-1` quand aucun élément n'a été ajoutée.

Une `Premise` est une liste de fait (`Property`) lier par la condition `ET`.

Nous avons choisi cette implémentation, car un accès en queue est utile pour les obligations liées au projet ce qui permet de faire un ajout en queue en `o(1)`. De plus nous gardons un accès en tête, puisque la liste est simplement chainée. 

>[!FACT]
>
>Nous aurions préféré une pile, car garde l'avantage de l'ajout en `o(1)` et plus simple, mais le sujet nous imposer une liste.

---
### `ElmOfPremise`

Ce type est composé de deux champs :
* `premise:Type` qui est de type `Property` et qui représente un fait, une donnée.
* `id:LongInteger` qui est l'identifiant unique de cet élément.
* `next:ElmOfPremise` qui représente l'élément suivant de la liste.

Un `ElmOfPremise` représenté un élément d'une liste de type `Premise`.

Nous avons choisi cette implémentation, car rien de plus est nécessaire pour cette partie.

---
### `Rule`

Ce type est composé de trois champs :
* `premise:Premise` de type `Premise` qui représente un ensemble de conditions à satisfaire.
* `conclusion:Type` de type `Property` qui est le résultat si la prémisse est satisfaite.
* `facts:FactList` qui est la liste de fait (`FactList`) sur laquelle se base la règle

Et représente une règle à satisfaire.

Nous avons choisi cette représentation, car l'accès à la liste de fait est intéressant pour ne pas perdre en mémoire tous les faits existants.

---
### `DB`

Ce type est une liste de `ElmOfDB` de taille non définit. 

Il est composé de quatre champs :
* `head:ElmOfDB` qui permet d'accéder au premier élément.
* `tail:ElmOfDB` qui permet d'accéder au dernier élément.
* `last_id:LongInteger` qui est le dernier `id` donnée à un `ElmOfDB` et il vaut `-1` quand aucun élément n'a été ajoutée.
* `facts` qui est la liste de fait (`FactList`) sur laquelle se base la base de connaissance.

Une `DB` est liste de règle (`Rule`) afin de pouvoir faire résonner notre système expert.

Nous avons choisi cette implementation car un accès en queue est utile pour respecter les contraintes et que les `last_id` est pratique pour simplifier les algorithmes. La fact list sert à savoir si les règles et la base se base sur la même liste de fait ce qui permet de faire plusieurs systèmes experts sans conflits.

---
### `ElmOfDB`

Ce type est composé de trois champs :
* `rule:Rule` qui est de type `Rule` et qui représente une règle.
* `next:ElmOfDB` qui représente l'élément suivant de la liste.
* `id:LongIntegr` qui est l'identifiant unique de cet élément

Un `ElmOfDB` représenté un élément d'une liste de type `DB`.

Nous avons choisi cette représentation, car une structure simple suffit.
Le champ `id` est juste là pour rendre plus pratique l'utilisation de la structure `DB` par un humain, comme aucune fonction ne se sert comme référence.


## Les structures implémenters et explication
Nous avons décidé qu'en `C` tous les types implémentés seraient des pointeurs sur des structures. Cela permet de ne pas avoir à faire de copie de structure et donc de gagner en performance. Cela permet aussi de retourner `NULL` quand les conditions ne sont pas respectées, comme en créant une structure avec sa fonction associée.

Vous remarquerez aussi que des types du type de forme `Pre...` sont présentes pour faire le lien entre les types C et algorithmique, mais ne sont jamais utilisés dans les algorithmes ou programmes C.

---
### Fichier `FactList.h`
La structure `ElmOfFact` définie un élément de la liste des faits. En complement la structure `FactList` sert à définir en la liste de fait en elle-même.
````c
typedef struct elm{
    long id;
    void* fact;
    struct elm* next;
}ElmOfFact;

typedef struct {
    ElmOfFact* head;
    int last_id;
    Boolean (*cmpValue)(void *, void*);
}PreFactList;

typedef PreFactList* FactList;
````
`*cmpValue` est un pointeur de fonction renseigné par l'utilisateur qui permet de vérifier si deux éléments du type qu'il a choisi sont égaux. Cette fonction ne sert qu'à éviter de mettre deux fois le meme fait dans une liste de fait.

---
### Fichier `Rules.h`
La structure `ElmOfPremise` sert à définir un élément de la liste qui a pour type `Premise` et qui est seulement un pointeur sur un **fait**. Dans ce cas l'élément passer au champ `premise` doit provenir d'une `FactList`.
````c
typedef struct elm{
    void* premise;
    struct elm* next;
    long id;
}ElmOfPremise;

typedef struct {
    ElmOfPremise* head;
    ElmOfPremise* tail;
    long last_id;
}Premise;
````

La structure `Rule` sert à définir une règle. Le champ `facts` est à vérifier que les éléménts de la prémise proviennent de la meme liste de fait qui a servi à créer la règle. Le champ `facts` est important, car s'il n'était pas un pointeur, on perdrait à chaque modification la tête ou queue de liste, comme par défaut le compilateur créer une copie.
````c
typedef struct{
    Premise* premise;
    void* conclusion;
    FactList facts;
} PreRule;

typedef PreRule* Rule;
````

---
### Fichier `DB.h`
La structure `ElmOfDB` représente un élément d'une **Base de Connaissance**. Une **Base de Connaissance** est une liste de règle représentée par le type `DB`.
````c
typedef struct elm{
    Rule rule;
    struct elm* next;
    long id;
}ElmOfDB;

typedef struct {
    ElmOfDB* head;
    ElmOfDB* tail;
    long last_id;
    FactList facts;
}PreDB;

typedef PreDB* DB;
````
Ici encore le champ `facts` sert à vérifier que les règles ajoutées dans la base connaissance soient issue de la même liste de fait.

---
C'est tout pour cette section, vous pouvez passer à la section suivante : [Fonctionnement du système expert](Functioning.md).