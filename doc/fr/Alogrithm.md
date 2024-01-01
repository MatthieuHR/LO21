# Algorithm des sous programmes

---
Dans cette section, vous pouvez retrouver tous les algorithmes des sous programmes en fonctions des données qu'ils traitent.

>Avant de commencer la fonction `isEmpty(elm:type)` permet de savoir si un élément est vide (`UNDEFINED`) peu importe le type `type`.
> 
> `Type` servira à indentifier le type d'un **fait**.

## Les algorithmes avec des `FactList`

---
### Les fonctions de bases
* `createElmOfFact()` renvoie un élément vide d'une liste de fait (`FactList`).
* `affectFiel(fact:Type)` renvoie un fait utilisable par une liste de fait (`FactList`) à partir du `fact`.
* `head(elm:FactList)` permet l'accès au premier élément de la liste.
* `fact(elm:ElmOfFact)` permet l'accession au champ `fact` de `elm`.
* `next(elm:ElmOfFact)` permet l'accession au suivant de `elm`.

---
### `addFact`
Cette fonction sert à ajouter un élément dans une `FactList`.
* `list` est la liste de fait où on veut ajouter l'élément.
* `fact` est le fait que l'on souhaite ajouter.
* `newl` est le nouvel élément de la `FactList` `list`.
>La fonction renvoie la liste de fait modifiée.
````
function addFact(list:FactList, fact:Type):FactList
Start
    newl:ElmOfFact <- createElmOfFact()
    fact(newl) <- affectfiel(fact)
    If isEmpty(fact(newl)) Then
        addFact <- EMTPY
    EndIf
    next(newl) = EMPTY
    If not isEmpty(list) Then
        next(newl) <- list
    EndIf
    addFact <- newl
End
````

---
### `remouveAllFacts`
Cette fonction permet de libérer la mémoire utilisée par une `FactList` en cas de besoin, par exemple en cas d'erreur.
* `list` est la liste que l'on souhaite vider.
>La fonction renvoie la liste de fait modifiée.
````
function remouveAllFacts(list:FactList):FactList
Start
    point:ElmOfFact <- head(list)
    While not isNull(point) Do
        head(list) <- point
        point <- next(point)
        free(point)
    Done
    remouveAllFacts <- point
End
````
## Les algorithmes avec des `Rule`

---

### Les fonctions de bases
* `head(elm:Premise)` permet l'accès au premier élément de la liste.
* `tail(elm:Premise)` permet l'accès au dernier élément de la liste.
* `createElmOfPremise()` Renvoie un élément vide d'une prémisse (`Premise`).
* `premise(elm:ElmOfPremise)` permet l'accession au champ `premise` de `elm`.
* `next(elm:ElmOfPremise)` permet l'accession au suivant de `elm`.
* `createRule()` Renvoie un élément vide d'une règle (`Rule`).
* `premise(elm:Rule)` permet l'accession au champ `premise` de `elm`.
* `conclusion(elm:Rule)` permet l'accession au champ `conclusion` de `elm`.
* `next(elm:ElmOfPremise)` permet l'accession au suivant de `elm`.

---
### `addPremise`
Cette fonction permet d'ajouter un élément à la premise d'une règle.
* `rule` est la règle à laquelle on veut modifier la prémisse.
* `premise` est un fait qui provient d'une liste de fait (`FactList`) et que l'on souhaite ajouter à la prémisse de la règle.
* `newl` est le nouvel élément de la prémisse.
* `point` est un pointeur pour parcourir la liste afin de faire un ajout en queue.
>La fonction renvoie la règle modifiée.
````
function addPremise(rule:Rule, premise:Type):Rule
Stat
    If not isEmpty(premise) Then
        newl:ElmOfPremise <- createElmOfPremise()
        premise(newl) <- premise
        next(newl) <- UNDEFINED
        If isEmpty(rule) Then
            rule <- createEmptyRule()
        EndIf
        If isEmpty(premise(rule)) Then
            head(premise(rule)) <- newl
        EndIf
        next(newl) <- tail(premise(rule)
        tail(premise(rule)) <- newl
    EndIf
    addPremise <- rule
End
````

---
### `createConclusion`
Cette fonction permet de mettre à jour la conclusion d'une règle.
* `rule` est la règle à laquelle on veut modifier la conclusion.
* `conclusion` est un fait qui provient d'une liste de fait (`FactList`) et que l'on souhaite utiliser comme conclusion de la règle.
>La fonction renvoie la règle modifiée.
````
function createConclusion(rule:Rule, conclusion:Type):Rule
Start
    If not isEmpty(conclusion) Then
        If not isEmpty(conclusion(rule)) Then
            free(conclusion(rule))
        EndIf
        conclusion(rule) <- conclusion
    EndIf
    createConclusion <- rule
End
````

---
### `factInPremise`
Cette fonction sert à définir récursivement si un fait est dans une prémisse de règle.
* `premise` est la prémisse provenant d'une règle (`Rule`) dont on veut savoir si le fait y est contenu.
* `prop` est le fait que l'on cherche.
>La fonction renvoie `True` si la propriété est comprise, `False` sinon.
````
function factInPremise(premise:Premise, prop:Type):Bool
Start
    If isEmpty(premise) Then
        factInPremise <- False
    EndIf
    If premise(head(premise)) = prop Then
        factInPremise <- True
    Endif
    new:Premise <- createPremise()
    head(new) <- next(head(premise)
    tail(new) <- tail(premise)
    factInPremise <- factInPremise(new, prop)
End
````

---
### `removePremise`
Cette fonction permet de retirer un fait de la prémisse.
* `rule` est la règle à laquelle on veut modifier la prémisse.
* `premise` est un fait qui provient d'une liste de fait (`FactList`) et que l'on souhaite retirer à la prémisse de la règle.
* `point` est un pointeur pour parcourir la liste.
>La fonction renvoie la règle modifiée.
````
function removePremise(rule:Rule, premise:Type):Rule
Start
    If not isEmpty(premise(Rule)) Then
        point:ElmOfPremise <- head(premise(rule))
        If premise(point) = premise Then
            head(premise(rule)) <- next(point)
            free(point)
        Else
            If not isEmpty(next(point)) Then
                While not isEmpty(next(point)) Do
                    If premise(next(point)) = premise Then
                        tmp:ElmOfPremise <- next(point)
                        next(point) <- next(next(point))
                        free(tmp)
                        removePremise <- rule
                    EndIf
                    point <- next(point)
                Done
            EndIf
        EndIf
    EndIf
    removePremise <- rule
End
````

## Les algorithmes avec des `BC`

---
### Les fonctions de bases
* `head(elm:BC)` permet l'accès au premier élément de la liste.
* `createElmOfBC()` Renvoie un élément vide d'une base de connaissance (`BC`).
* `rule(elm:ElmOfBC)` permet l'accession au champ `rule` de `elm`.
* `next(elm:ElmOfBC)` permet l'accession au suivant de `elm`.

---
### `addRuleToBC`
Cette fonction permet d'ajouter une règle à une base de connaissance.
* `bc` est la base de connaissance à laquelle on veut ajouter une règle.
* `rule` est une règle que l'on souhaite ajouter.
* `newl` est le nouvel élément de la base de connaissance.
* `point` est un pointeur pour parcourir la liste afin de faire un ajout en queue.
>La fonction renvoie la base de connaissance modifiée.
```
function addRuleToBC(bc:BC, rule:Rule):BC
Start
    newl:ElmOfBC
    rule(newl) <- rule
    next(newl) <- UNDEFINED
    If not isEmpty(bc) Then
        point:ElmOfBC <- head(bc)
        While not isEmpty(next(point)) Do
            point <- next(point)
        Done
        next(point) <- newl
        addRuleToBC <- bc
    Else
        head(bc) <- newl
        addRuleToBC <- bc
    EndIf
End
```

---
### `copyOfBC`
Cette fonction permet de réaliser une copie d'une base de connaissance.
* `bc` est la base de connaissance que l'on souhaite copier.
* `point` est un pointeur pour parcourir la base de connaissance `bc`.
* `new_rule` est l'ensemble de nouvelles règles que l'on ajoute à `bc`.
* `premise` est l'ensemble des premise des règles de `bc`.
>La fonction revoit la copie de la bc.
````
function copyOfBC(bc:BC):BC
Start 
    new_bc:BC <- createBC()
    point:ElmOfBC <- head(bc)
    While not isEmpty(point) Do
        new_rule:Rule <- createRule()
        premise:ElmOfPremise <- premise(rule(point))
        While not isEmpty(premise) Do
            new_rule <- addPremise(new_rule, premise(premise))
            premise <- next(premise)
        Done
        conclusion(new_rule) <- conclusion(rule(point))
        new_bc <- addRuleToBC(new_bc, new_rule)
        point <- next(point)
    Done
    copyOfBC <- new_bc
End
````