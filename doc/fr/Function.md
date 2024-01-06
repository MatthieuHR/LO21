# Guide des fonctions (en C)

----
Dans cette partie, vous pourrez retrouver toutes les fonctions implémenter en C et ainsi que leurs usages et déclarations.

Cette partie sera traitée en fonctions des fichiers `.h` et chaque fichier succédant inclus tous les fichiers précédent.
>[!NOTE]
>
>Il vous suffit donc d'inclure le fichier `ExpertSys.h` pour faire fonctionner le tout.


## Fichier `Properties.h`

---
`Bool isUndefinedProperty(void* prop)` : dit si un fait (`prop`) est vide, c'est-à-dire pointe sur `NULL`. Renvoie `True` si est vide, `False` sinon.


## Fichier `FactList.h`

---
`Bool isEmptyProperty(void* prop)` : dit si un fait (`prop`) est vide. Renvoie `True` si est vide, `False` sinon.

`FactList createFactList(Bool (*cmpValue)(void*, void*), Bool (*isEmpty)(void *), void(*freeValue)(void*)))` : revoie un objet de type `FactList` avec tous ses champs `NULL` sauf `cmpValue` qui est remplie avec le paramètre `cmpValue`,`isEmpty` qui est remplie avec le paramètre `isEmpty`,`freeValue` qui est remplie avec le paramètre `freeValue` et `last_id` qui vaut `-1`. Sert à créer un objet utilisable pour les autres fonctions.

`Bool isAlreadyInFactList(FactList list, void* fact)` : permet de savoir si un fait (`fact`) est deja dans `list` en se basant sur le pointeur de fonction contenue dans le champ `cmpValue` de `list`. Renvoi `True` si `cmpValue()` renvoie `True` pour une comparaison et `False` sinon. La fonction est récursive.

`Bool isPresentInFactList(FactList list, void* fact)` : permet de savoir si un fait (`fact`) est deja dans `list` en se basant sur l'adresse mémoire des faits (ex : `fact`). Renvoi `True` si les adresses mémoire sont identiques et `False` sinon. La fonction est récursive.

`Bool isUndefinedFactList(FactList list)` : permet de savoir si une liste de fait (`list`) est vide. Une liste de fait est indefinite si elle pointe sur `NULL`.La fonction renvoie `True` si la liste est vide et `False` sinon.

`Bool isEmptyFactList(FactList list)` : permet de savoir si une liste de fait (`list`) est vide. Une liste de fait est vide. La fonction renvoie `True` si la liste est vide et `False` sinon.

`FactList addFact(FactList list, void* fact)` : ajoute un fait (`fact`) à une liste de fait à condition qu'un autre fait ne renvoie pas `True` quand il est comparé avec `fact` à l'aide de la fonction `cmpValue()` dans le champ du même nom dans `list`. La fonction renvoie quoi qu'il arrive la même `list` avec un élément en plus ou non.

`FactList removeAFact(FactList list, void* fact)` : permet de supprimer un fait (`fact`) d'une liste de fait (`list`). La fonction renvoie quoi qu'il arrive la même `list` avec un élément en moins ou non.

`FactList removeAFactAndFree(FactList list, void* fact)` : permet de supprimer un fait (`fact`) d'une liste de fait (`list`). La fonction `free()` le fait supprimé. La fonction renvoie quoi qu'il arrive la même `list` avec un élément en moins ou non.

`FactList removeAFactById(FactList list, long id)` : permet de supprimer un fait (`fact`) d'une liste de fait (`list`) en fonction de son champ `id`. La fonction renvoie quoi qu'il arrive la même `list` avec un élément en moins ou non.

`FactList removeAFactByIdAndFree(FactList list, long id)` : permet de supprimer un fait (`fact`) d'une liste de fait (`list`) en fonction de son champ `id`. La fonction `free()` le fait supprimé. La fonction renvoie quoi qu'il arrive la même `list` avec un élément en moins ou non.

`FactList removeAllFacts(FactList list)` : permet de vider une liste de fait, mais ne vide pas le champ `cmpValue` intact. Cette fonction ne `free()` pas les faits de `list`. Renvoie une `Factlist` semblable à celle créée par la fonction `createFactList()`.

`FactList removeAllFactsAndFree(FactList list)` : permet de vider une liste de fait, mais ne vide pas le champ `cmpValue` intact. Cette fonction `free()` tous les fait de `list`. Renvoie une `Factlist` semblable à celle créée par la fonction `createFactList()`.

`void* getFactById(FactList list, long id)` : permet d'obtenir un pointeur sur le fait souhaité en fonction de son champ `id`. Le paramètre `id` est celui qui doit matcher le champ `id`. Renvoi un fait s'il est trouvé sinon `NULL`.

`ElmOfFact* getHeadOfFactList(FactList list)` : permet d'obtenir le premier élément d'une liste de fait (`list`). La fonction renvoie un pointeur sur le premier élément de la liste de fait de type `ElmOfFact*`.

`ElmOfFact* nextOfFact(ElmOfFact* elm)` : permet d'obtenir l'élément suivant d'un élément de fait (`elm`). La fonction renvoie un pointeur sur l'élément suivant de type `ElmOfFact*`. Renvoie `NULL` si `elm` est `NULL`.

`void* getFact(ElmOfFact* elm)` : permet d'obtenir le fait d'un élément de fait (`elm`). La fonction renvoie un pointeur sur le fait de type `void*`. Renvoie `NULL` si `elm` est `NULL`.

`long getIdOfFact(ElmOfFact* elm)` : permet d'obtenir l'id d'un élément de fait (`elm`). La fonction renvoie un pointeur sur l'id de type `long`. Renvoie `-1` si `elm` est `NULL`.

`FactList freeFactList(FactList list)` : permet de libérer la mémoire allouée à une liste de fait. Renvoie `NULL`. La fonction `free()` tous les fait de `list`.


## Fichier `Rules.h`

---
`Bool isEqualsRule(Rule rule1, Rule rule2)` : permet de savoir si deux règles (`rule1` et `rule2`) sont identiques par rapport a tous leurs champs. La fonction renvoie `True` si les règles sont identiques et `False` sinon.

`Rule createEmptyRule(FactList facts)` : renvoie un objet de type `Rules` avec tous ces champs `NULL` sauf `facts` qui vaut le paramètre `facts`.

`Bool isUndefinedRule(Rule rule)` : permet de savoir si une règle (`rule`) est vide. Une règle est vide si elle pointe sur `NULL`. La fonction renvoie `True` si la règle est vide et `False` sinon.

`Bool isEmptyRule(Rule rule)` : permet de savoir si une règle (`rule`) est vide. Une règle est vide si elle pointe sur `NULL` ou si sa prémise est vide. La fonction renvoie `True` si la règle est vide et `False` sinon.

`Rule addFactInPremise(Rule rule, void* premise)` : permet d'ajouter un fait (`premise`) dans le champ `premise` d'une règle (`rule`). Le fait n'est pas ajouté s'il n'est pas dans la liste de fait. La fonction renvoie quoi qu'il arrive `rule` modifier ou non.

`Rule setConclusion(Rule rule, void* conclusion)` : permet de définir une conclusion (`conclusion`) dans le champ `conclusion` d'une règle (`rule`). La fonction renvoie quoi qu'il arrive `rule` modifier ou non. Le fait n'est pas ajouté s'il n'est pas dans la liste de fait ou vide (`NULL`).

`Rule removeFromPremise(Rule rule, void* premise)` : permet de supprimer un fait (`premise`) dans le champ `premise` d'une règle (`rule`). La fonction renvoie quoi qu'il arrive `rule` modifier ou non.

`Rule removeFromPremiseById(Rule rule, long id)` : permet de supprimer un fait (`premise`) dans le champ `premise` d'une règle (`rule`) en fonction de son champ `id`. La fonction renvoie quoi qu'il arrive `rule` modifier ou non.

`Bool factInPremise(Premise premise, void* prop)` : permet de savoir si un fait (`prop`) est dans une prémise (`premise`). La fonction renvoie `True` si le fait est dans la prémise et `False` sinon. La fonction est récursive.

`Bool isPremiseEmpty(Rule rule)` : permet de savoir si une `prémise` d'une règle (`rule`) est vide. La fonction renvoie `True` si la prémise est vide et `False` sinon. La fonction est récursive.

`Bool isUndefinedConclusion(Rule rule)` : permet de savoir si une `conclusion` d'une règle (`rule`) est vide (pointe sur `NULL`). La fonction renvoie `True` si la conclusion est vide et `False` sinon.

`ElmOfPremise* getHeadOfPremise(Rule rule)` : permet d'obtenir le premier élément de la prémise d'une règle (`rule`). La fonction renvoie un pointeur sur le premier élément de la prémise de type `ElmOfPremise*`.

`ElmOfPremise* nextOfPremise(ElmOfPremise* elm)` : permet d'obtenir l'élément suivant d'un élément de prémise (`elm`). La fonction renvoie un pointeur sur l'élément suivant de type `ElmOfPremise*`. Renvoie `NULL` si `elm` est `NULL`.

`void* getPremise(ElmOfPremise* elm)` : permet d'obtenir le fait d'un élément de prémise (`elm`). La fonction renvoie un pointeur sur le fait de type `void*`. Renvoie `NULL` si `elm` est `NULL`.

`void* getConclusion(Rule rule)` : permet d'obtenir la conclusion d'une règle (`rule`). La fonction renvoie un pointeur sur la conclusion de type `void*`.

`void* getIdOfPremise(ElmOfPremise* elm)` : permet d'obtenir l'id d'un élément de prémise (`elm`). La fonction renvoie un pointeur sur l'id de type `long`. Renvoie `-1` si `elm` est `NULL`.

`FactList getFactListOfRule(Rule rule)` : permet d'obtenir la liste de fait associée à une règle (`rule`). La fonction renvoie un pointeur sur la liste de fait de type `FactList`.

`FactList freeRule(Rule rule)` : permet de libérer la mémoire allouée à une règle. La fonction `free()` tous les éléments de la prémise et la conclusion. Renvoie la liste de fait associée à la règle. Revoie `NULL` si la mèmoire n'a pas pu être libérée.

## Fichier `DB.h`

---
`DB createEmptyDB(FactList facts)` : permet de créer une base de connaissance vide avec une liste de fait associée (`facts`). La fonction renvoie un pointeur sur la base de connaissance de type `DB`.

`Bool isUndefinedDB(DB db)` : permet de savoir si une base de connaissance (`db`) est vide. Une base de connaissance est vide si elle pointe sur `NULL`. La fonction renvoie `True` si la base de connaissance est vide et `False` sinon.

`Bool isEmptyDB(DB db)` : permet de savoir si une base de connaissance (`db`) est vide. Une base de connaissance est vide si elle pointe sur `NULL` ou si elle ne contient aucune règle. La fonction renvoie `True` si la base de connaissance est vide et `False` sinon.

`DB addRule(DB db, Rule rule)` : permet d'ajouter une règle (`rule`) à une base de connaissance (`db`). La fonction renvoie quoi qu'il arrive `db` modifier ou non. La fonction ne fait rien si la règle est vide ou la base de donnée.

`ElmOfDB* getHeadRule(DB db)` : permet d'obtenir la première règle (`Rule`) de la base de connaissance (`db`). La fonction renvoie un pointeur sur le premier élément de la base de connaissance de type `ElmOfDB*`.

`ElmOFDB* getNextRule(ElmOfDB* rule)` : permet d'obtenir la règle suivante (`Rule`) d'une règle (`rule`). La fonction renvoie un pointeur sur la règle suivante de type `ElmOfDB*`. Renvoie `NULL` si `rule` est `NULL`.

`Rule getRule(ElmOfDB* rule)` : permet d'obtenir la règle (`Rule`) d'un élément de base de connaissance (`rule`). La fonction renvoie un pointeur sur la règle de type `Rule`. Renvoie `NULL` si `rule` est `NULL`.

`long getIdOfRule(ElmOfDB* rule)` : permet d'obtenir l'id d'un élément de base de connaissance (`rule`). La fonction renvoie un pointeur sur l'id de type `long`. Renvoie `-1` si `rule` est `NULL`.

`Rule removeARule(DB db, Rule rule)` : permet de supprimer une règle (`rule`) d'une base de connaissance (`db`). La fonction renvoie quoi qu'il arrive `db` modifier ou non. La fonction ne fait rien si la règle est vide ou la base de donnée.

`Rule removeARuleAndFree(DB db, Rule rule)` : permet de supprimer une règle (`rule`) d'une base de connaissance (`db`). La fonction renvoie quoi qu'il arrive `db` modifier ou non. La fonction ne fait rien si la règle est vide ou la base de donnée.

`Rule removeARuleById(DB db, long id)` : permet de supprimer une règle (`rule`) d'une base de connaissance (`db`) en fonction de son champ `id`. La fonction renvoie quoi qu'il arrive `db` modifier ou non. La fonction ne fait rien si la règle est vide ou la base de donnée.

`Rule removeARuleByIdAndFree(DB db, long id)` : permet de supprimer une règle (`rule`) d'une base de connaissance (`db`) en fonction de son champ `id`. La fonction renvoie quoi qu'il arrive `db` modifier ou non. La fonction ne fait rien si la règle est vide ou la base de donnée.

`Rule removeAllRules(DB db)` : permet de supprimer toutes les règles d'une base de connaissance (`db`). La fonction renvoie quoi qu'il arrive `db` modifier ou non. La fonction ne fait rien si la base de donnée est vide.

`Rule removeAllRulesAndFree(DB db)` : permet de supprimer toutes les règles d'une base de connaissance (`db`). La fonction renvoie quoi qu'il arrive `db` modifier ou non. La fonction ne fait rien si la base de donnée est vide.

`DB copyDB(DB db)` : permet de copier une base de connaissance (`db`). La fonction renvoie un pointeur sur la base de connaissance de type `DB`. La fonction ne copie pas la liste de fait associée à la base de connaissance.

`FactList freeDB(DB db)` : permet de libérer la mémoire allouée à une base de connaissance. La fonction `free()` tous les éléments de la base de connaissance. Renvoie la liste de fait associée à la base de connaissance.

`FactList getFactListOfDB(DB db)` : permet d'obtenir la liste de fait associée à une base de connaissance (`db`). La fonction renvoie un pointeur sur la liste de fait de type `FactList`.

`Bool isPresentInDB(DB db, Rule rule)` : permet de savoir si une règle (`rule`) est déjà dans une base de connaissance (`db`) par rapport à son adresse mémoire. La fonction renvoie `True` si la règle est dans la base de connaissance et `False` sinon.

`Bool isAlreadyInDB(DB db, Rule rule)` : permet de savoir si une règle (`rule`) est déjà dans une base de connaissance (`db`) par rapport à son contenu (comparaisons de ses champs). La fonction renvoie `True` si la règle est dans la base de connaissance et `False` sinon. **Fonction non commander car très couteuse.**

`Bool isUndefinedDB(DB db)` : permet de savoir si une base de connaissance (`db`) est vide. Une base de connaissance est vide si elle pointe sur `NULL`. La fonction renvoie `True` si la base de connaissance est vide et `False` sinon.

## Fichier `ExpertSys.h`

---
`int expertSystem(FactList factsToTest, FactList resultFacts, DB knowledgeBase)` : permet de lancer l'expert système. La fonction renvoie `0` si tout c'est bien passé, `-1` si `factsToTest` est vide, `-2` si `resultFacts` est vide, `-3` si `knowledgeBase` est vide, `-4` si `factsToTest` et `resultFacts` sont vide, `-5` si `factsToTest` et `knowledgeBase` sont vide, `-6` si `resultFacts` et `knowledgeBase` sont vide, `-7` si `factsToTest`, `resultFacts` et `knowledgeBase` sont vide.