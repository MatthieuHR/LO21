# Guide des fonctions (en C)

----
Dans cette partie, vous pourrez retrouver toutes les fonctions implémenter en C et ainsi que leurs usages et déclarations.

Cette partie sera traitée en fonctions des fichiers `.h` et chaque fichier succédant inclus tous les fichiers précédent.
>[!NOTE]
>
>Il vous suffit donc d'inclure le fichier `ExpertSys.h` pour faire fonctionner le tout.


## Fichier `Properties.h`

---
`Boolean isUndefinedProperty(void* prop)` : dit si un fait (`prop`) est indéfinie, c'est-à-dire pointe sur `NULL`. Renvoie `True` si est vide, `False` sinon.


## Fichier `FactList.h`

---
### Les fonctions de test : 

---
`Boolean isEmptyProperty(FactList facts, void* prop)` : dit si un fait (`prop`) est vide. Renvoie `True` si est vide, `False` sinon. Une `Property` est vide si elle est indéfinie ou si le résultat de la fonction `isEmpty` du champ du meme nom est `True`.

`Boolean isAlreadyInFactList(FactList list, void* fact)` : permet de savoir si un fait (`fact`) est deja dans `list` en se basant sur le pointeur de fonction contenue dans le champ `cmpValue` de `list`. Renvoi `True` si `cmpValue()` renvoie `True` pour une comparaison et `False` sinon. La fonction est récursive. Un fait indéfini ou une liste de fait vide renvoi automatiquement `NULL`.

`Boolean isPresentInFactList(FactList list, void* fact)` : permet de savoir si un fait (`fact`) est deja dans `list` en se basant sur l'adresse mémoire des faits. Renvoi `True` si les adresses mémoire sont identiques et `False` sinon. La fonction est récursive. Un fait indéfini ou une liste de fait vide renvoi automatiquement `NULL`.

`Boolean isUndefinedFactList(FactList list)` : permet de savoir si une liste de fait (`list`) est définie. Une liste de fait est indefinite si elle pointe sur `NULL`. La fonction renvoie `True` si la liste est définie et `False` sinon.

`Boolean isEmptyFactList(FactList list)` : permet de savoir si une liste de fait (`list`) est vide. Une liste de fait est vide si elle est indéfinie ou sa tete est indéfinie. La fonction renvoie `True` si la liste est vide et `False` sinon.


### Les fonctions pour manipuler une `FactList` :

---
`FactList createFactList(Boolean (*cmpValue)(void*, void*), Boolean (*isEmpty)(void *), void(*freeValue)(void*)))` : revoie un objet de type `FactList` avec tous ses champs `NULL` sauf `cmpValue` qui est remplie avec le paramètre `cmpValue`,`isEmpty` qui est remplie avec le paramètre `isEmpty`,`freeValue` qui est remplie avec le paramètre `freeValue` et `last_id` qui vaut `-1`. Sert à créer un objet utilisable pour les autres fonctions. La fonction renvoie `NULL` si un des trois parameters est `NULL`.

`FactList addFact(FactList list, void* fact)` : ajoute un fait (`fact`) à une liste de fait à condition qu'un autre fait ne renvoie pas `True` quand il est comparé avec `fact` à l'aide de la fonction `cmpValue()` dans le champ du même nom dans `list`. La fonction renvoie quoi qu'il arrive la même `list` avec un élément en plus ou non. Un fait vide ou une liste de fait indéfinie ne rajoute pas le fait.

`FactList removeAFact(FactList list, void* fact)` : permet de supprimer un fait (`fact`) d'une liste de fait (`list`). La fonction renvoie quoi qu'il arrive la même `list` avec un élément en moins ou non. Un fait indéfini ou une liste vide renvoie `False` par défaut. Remet `last_id` à 0.

`FactList removeAFactAndFree(FactList list, void* fact)` : permet de supprimer un fait (`fact`) d'une liste de fait (`list`). La fonction `freeValue()` le fait supprimer. La fonction renvoie quoi qu'il arrive la même `list` avec un élément en moins ou non. Un fait indéfini ou une liste vide renvoie `False` par défaut. Remet `last_id` à 0.

`FactList removeAFactById(FactList list, long id)` : permet de supprimer un fait (`fact`) d'une liste de fait (`list`) en fonction de son champ `id`. La fonction renvoie quoi qu'il arrive la même `list` avec un élément en moins ou non. Un id supérieur à au `last_id` de la liste de fait ou inférieur à 0 ou une liste vide renvoie `False` par défaut. Remet `last_id` à 0.

`FactList removeAFactByIdAndFree(FactList list, long id)` : permet de supprimer un fait (`fact`) d'une liste de fait (`list`) en fonction de son champ `id`. La fonction `freeValue()` le fait supprimer. La fonction renvoie quoi qu'il arrive la même `list` avec un élément en moins ou non. Un id supérieur à au `last_id` de la liste de fait ou inférieur à 0 ou une liste vide renvoie `False` par défaut.

`FactList removeAllFacts(FactList list)` : permet de vider une liste de fait, mais ne vide pas le champ `cmpValue` intact. Cette fonction ne `freeValue()` pas les faits de `list`. Renvoie une `Factlist` semblable à celle créée par la fonction `createFactList()`. Une liste de fait vide ne remet que son champ `last_id` à 0.

`FactList removeAllFactsAndFree(FactList list)` : permet de vider une liste de fait, mais ne vide pas le champ `cmpValue` intact. Cette fonction `freeValue()` tous les fait de `list`. Renvoie une `Factlist` semblable à celle créée par la fonction `createFactList()`. Une liste de fait vide ne remet que son champ `last_id` à 0.

`FactList freeFactList(FactList list)` : permet de libérer la mémoire allouée à une liste de fait. Renvoie `NULL`. La fonction `free()` tous les fait de `list`.


### Les fonctions pour parcourir une `FactList` :

---
`void* getFactById(FactList list, long id)` : permet d'obtenir un pointeur sur le fait souhaité en fonction de son champ `id`. Le paramètre `id` est celui qui doit matcher le champ `id`. Renvoi un fait s'il est trouvé sinon `NULL`.

`ElmOfFact* getHeadOfFactList(FactList list)` : permet d'obtenir le premier élément d'une liste de fait (`list`). La fonction renvoie un pointeur sur le premier élément de la liste de fait de type `ElmOfFact*`. Renvoi `NULL` si n'existe pas.

`ElmOfFact* nextOfFact(ElmOfFact* elm)` : permet d'obtenir l'élément suivant d'un élément de fait (`elm`). La fonction renvoie un pointeur sur l'élément suivant de type `ElmOfFact*`. Renvoie `NULL` si `elm` est `NULL`. Renvoi `NULL` si n'existe pas

`void* getFact(ElmOfFact* elm)` : permet d'obtenir le fait d'un élément de fait (`elm`). La fonction renvoie un pointeur sur le fait de type `void*`. Renvoie `NULL` si `elm` est `NULL`.

`long getIdOfFact(ElmOfFact* elm)` : permet d'obtenir l'id d'un élément de fait (`elm`). La fonction renvoie un pointeur sur l'id de type `long`. Renvoie `-1` si `elm` est `NULL`.



## Fichier `Rules.h`

---

### Les fonctions de test :

---
`Boolean isEqualsRule(Rule rule1, Rule rule2)` : permet de savoir si deux règles (`rule1` et `rule2`) sont identiques par rapport à tous leurs champs (`conclusion`, `premise`, `facts`) et les prémisses sont égales si tous les faits d'une prémisse sont dans l'autre prémisse et inversement (les `id` peuvent différer). La fonction renvoie `True` si les règles sont identiques et `False` sinon.

`Boolean isUndefinedRule(Rule rule)` : permet de savoir si une règle (`rule`) est indéfinie. Une règle est indéfinie si elle pointe sur `NULL`. La fonction renvoie `True` si la règle est définie et `False` sinon.

`Boolean isEmptyRule(Rule rule)` : permet de savoir si une règle (`rule`) est vide. Une règle est vide si elle pointe sur `NULL` ou si sa prémise est vide dont que le champ `head` de la prémise est indéfinie. La fonction renvoie `True` si la règle est vide et `False` sinon.

`Boolean factInPremise(Premise premise, void* prop)` : permet de savoir si un fait (`prop`) est dans une prémise (`premise`). La fonction renvoie `True` si le fait est dans la prémise et `False` sinon. La fonction est récursive. Un fait indéfini ne peut être dans une prémisse.

`Boolean isPremiseEmpty(Rule rule)` : permet de savoir si une `prémise` d'une règle (`rule`) est vide donc si sa tête est infinite. La fonction renvoie `True` si la prémise est vide et `False` sinon. La fonction est récursive.

`Boolean isUndefinedConclusion(Rule rule)` : permet de savoir si une `conclusion` d'une règle (`rule`) est indéfinie (pointe sur `NULL`). La fonction renvoie `True` si la conclusion est définie et `False` sinon.


### Les fonctions de manipulation d'une `Rule` :

---
`Rule createEmptyRule(FactList facts)` : renvoie un objet de type `Rules` avec tous ces champs `NULL` sauf `facts` qui vaut le paramètre `facts`. Renvoi `NULL` si `facts` est indéfinie.

`Rule addFactInPremise(Rule rule, void* premise)` : permet d'ajouter un fait (`premise`) dans le champ `premise` d'une règle (`rule`). Le fait n'est pas ajouté s'il n'est pas dans la liste de fait ou `rule` est indéfinie ou le fait est indéfinie ou si la conclusion est le fait. La fonction renvoie quoi qu'il arrive `rule` modifier ou non.

`Rule removeFromPremise(Rule rule, void* premise)` : permet de supprimer un fait (`premise`) dans le champ `premise` d'une règle (`rule`). La fonction renvoie quoi qu'il arrive `rule` modifier ou non.

`Rule removeFromPremiseById(Rule rule, long id)` : permet de supprimer un fait (`premise`) dans le champ `premise` d'une règle (`rule`) en fonction de son champ `id`. La fonction renvoie quoi qu'il arrive `rule` modifier ou non.

`Rule setConclusion(Rule rule, void* conclusion)` : permet de définir une conclusion (`conclusion`) dans le champ `conclusion` d'une règle (`rule`). La fonction renvoie quoi qu'il arrive `rule` modifier ou non. Le fait n'est pas ajouté s'il n'est pas dans la liste de fait ou vide indéfinie ou si la règle est indéfinie ou si la conclusion est présent dans la prémisse.

`Rule removeConclusion(Rule rule)` : permet de rendre indéfinie la conclusion d'une règle. Renvoie la règle avec le champ `conclusion` indéfinie.

`FactList freeRule(Rule rule)` : permet de libérer la mémoire allouée à une règle. La fonction `free()` tous les éléments de la prémise et la conclusion. Renvoie la liste de fait associée à la règle. Revoie `NULL` si la mèmoire n'a pas pu être libérée. Ne libère pas les faits.


Les fonctions pour parcourir une `Rule` :

---
`ElmOfPremise* getHeadOfPremise(Rule rule)` : permet d'obtenir le premier élément de la prémise d'une règle (`rule`). La fonction renvoie un pointeur sur le premier élément de la prémise de type `ElmOfPremise*` et `NULL` s'il n'existe pas.

`ElmOfPremise* nextOfPremise(ElmOfPremise* elm)` : permet d'obtenir l'élément suivant d'un élément de prémise (`elm`). La fonction renvoie un pointeur sur l'élément suivant de type `ElmOfPremise*`. Renvoie `NULL` si `elm` est `NULL`.

`void* getPremise(ElmOfPremise* elm)` : permet d'obtenir le fait d'un élément de prémise (`elm`). La fonction renvoie un pointeur sur le fait de type `void*`. Renvoie `NULL` si `elm` est `NULL`.

`void* getConclusion(Rule rule)` : permet d'obtenir la conclusion d'une règle (`rule`). La fonction renvoie un pointeur sur la conclusion de type `void*`. Renvoie `NULL` si n'existe pas.

`void* getIdOfPremise(ElmOfPremise* elm)` : permet d'obtenir l'id d'un élément de prémise (`elm`). La fonction renvoie un pointeur sur l'id de type `long`. Renvoie `-1` si `elm` est `NULL`.

`FactList getFactListOfRule(Rule rule)` : permet d'obtenir la liste de fait associée à une règle (`rule`). La fonction renvoie un pointeur sur la liste de fait de type `FactList` et `NULL` si la règle est indéfinie. Normalement si la règle a été correctement créer avec la fonction `createEmptyRule()` le champ `facts` n'est jamais vide.

## Fichier `DB.h`

---

### Les fonctions de test :

----
`Bolean isRuleAddable(Rule rule)` : permet de savoir si une règle est prête à être ajoutée à une base de connaissance. Une règle est **addable** si elle n'est pas vide et si sa liste de fait est définie.

`Boolean isUndefinedDB(DB db)` : permet de savoir si une base de connaissance (`db`) est indéfinie. Une base de connaissance est indéfinie si elle pointe sur `NULL`. La fonction renvoie `True` si la base de connaissance est définie et `False` sinon.

`Boolean isEmptyDB(DB db)` : permet de savoir si une base de connaissance (`db`) est vide. Une base de connaissance est vide si elle pointe sur `NULL` ou si elle ne contient aucune règle (la tete de la base de connaissance est indéfinie). La fonction renvoie `True` si la base de connaissance est vide et `False` sinon.

`Boolean isPresentInDB(DB db, Rule rule)` : permet de savoir si une règle (`rule`) est déjà dans une base de connaissance (`db`) par rapport à son adresse mémoire. La fonction renvoie `True` si la règle est dans la base de connaissance et `False` sinon. Une règle indéfinie n'est pas présente dans une base de connaissance.

`Boolean isAlreadyInDB(DB db, Rule rule)` : permet de savoir si une règle (`rule`) est déjà dans une base de connaissance (`db`) par rapport à son contenu (comparaisons de ses champs). La fonction renvoie `True` si la règle est dans la base de connaissance et `False` sinon. **Fonction non commander, car très couteuse.**

### Les fonctions pour modifier une `DB` :

---


`DB createEmptyDB(FactList facts)` : permet de créer une base de connaissance vide avec une liste de fait associée (`facts`). La fonction renvoie un pointeur sur la base de connaissance de type `DB`. Renvoie `NULL` si la liste de fait est indéfinie.

`DB addRule(DB db, Rule rule)` : permet d'ajouter une règle (`rule`) à une base de connaissance (`db`). La fonction renvoie quoi qu'il arrive `db` modifier ou non. La fonction ne fait rien si la règle est vide ou la base de donnée. Une règle qui existe déja dans la base de connaissance n'est pas ajoutée. De plus la liste de faits de la règle et base de connaissance doit être la même.

`Rule removeARule(DB db, Rule rule)` : permet de supprimer une règle (`rule`) d'une base de connaissance (`db`). La fonction renvoie quoi qu'il arrive `db` modifier ou non. La fonction ne fait rien si la règle est vide ou la base de donnée.

`Rule removeARuleAndFree(DB db, Rule rule)` : permet de supprimer une règle (`rule`) d'une base de connaissance (`db`) et de la libérer en mémoire. La fonction renvoie quoi qu'il arrive `db` modifier ou non. La fonction ne fait rien si la règle est vide ou la base de donnée.

`Rule removeARuleById(DB db, long id)` : permet de supprimer une règle (`rule`) d'une base de connaissance (`db`) en fonction de son champ `id`. La fonction renvoie quoi qu'il arrive `db` modifier ou non. La fonction ne fait rien si la règle est vide ou la base de donnée.

`Rule removeARuleByIdAndFree(DB db, long id)` : permet de supprimer une règle (`rule`) d'une base de connaissance (`db`) en fonction de son champ `id` et de la libérer en mémoire. La fonction renvoie quoi qu'il arrive `db` modifier ou non. La fonction ne fait rien si la règle est vide ou la base de donnée.

`Rule removeAllRules(DB db)` : permet de supprimer toutes les règles d'une base de connaissance (`db`). La fonction renvoie quoi qu'il arrive `db` modifier ou non. La fonction ne fait rien si la base de donnée est vide.

`Rule removeAllRulesAndFree(DB db)` : permet de supprimer toutes les règles d'une base de connaissance (`db`) et de les libérer en mémoire. La fonction renvoie quoi qu'il arrive `db` modifier ou non. La fonction ne fait rien si la base de donnée est vide.

`DB copyDB(DB db)` : permet de copier une base de connaissance (`db`). La fonction renvoie un pointeur sur la base de connaissance de type `DB`. La fonction ne copie pas la liste de fait associée à la base de connaissance. De plus chaque élément de la copie a un emplacement différent en mémoire sauf pour les faits.

`FactList freeDB(DB db)` : permet de libérer la mémoire allouée à une base de connaissance. La fonction `free()` tous les éléments de la base de connaissance. Renvoie la liste de fait associée à la base de connaissance.


### Les fonctions pour parcourir une `DB` :

---
`ElmOfDB* getHeadRule(DB db)` : permet d'obtenir la première règle (`Rule`) de la base de connaissance (`db`). La fonction renvoie un pointeur sur le premier élément de la base de connaissance de type `ElmOfDB*` et `NULL` si le champ n'existe pas.

`ElmOFDB* getNextRule(ElmOfDB* rule)` : permet d'obtenir la règle suivante (`Rule`) d'une règle (`rule`). La fonction renvoie un pointeur sur la règle suivante de type `ElmOfDB*`. Renvoie `NULL` si `rule` est indéfinie.

`Rule getRule(ElmOfDB* rule)` : permet d'obtenir la règle (`Rule`) d'un élément de base de connaissance (`rule`). La fonction renvoie un pointeur sur la règle de type `Rule`. Renvoie `NULL` si `rule` est indéfinie.

`long getIdOfRule(ElmOfDB* rule)` : permet d'obtenir l'id d'un élément de base de connaissance (`rule`). La fonction renvoie un pointeur sur l'id de type `long`. Renvoie `-1` si `rule` est indéfinie.

`FactList getFactListOfDB(DB db)` : permet d'obtenir la liste de fait associée à une base de connaissance (`db`). La fonction renvoie un pointeur sur la liste de fait de type `FactList`.


## Fichier `ExpertSys.h`

---
`int expertSystem(FactList factsToTest, FactList resultFacts, DB knowledgeBase)` : permet de lancer l'expert système. La fonction renvoie `0` si tout s'est bien passé, `1` si `factsToTest` est vide, `2` si `resultFacts` est non vide, `3` si `knowledgeBase` est vide.