# Algorithm des sous programmes

---
Dans cette sections vous pouvez retrouver tous les algorithmes des sous programmes en fonctions des données qu'ils traites.

## Les algorithmes avec des `FactList`

---
### `addFact`
Cette fonction sert a ajouter un élément dans une `FactList`.
````
    function addFact(list:FactList, fact:Properties):FactList
    Start
        newl:ElmOfFact
        fact(newl) <- affectfiel(fact)
        If isEmpty(fact(newl)) SO
            addFact <- EMTPY
        EndIf
        next(newl) = EMPTY
        If not isEmpty(list) SO
            next(newl) <- list
        EndIf
        addFact <- newl
    End
````

---
### `remouveAllFacts`
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
## Les algorithmes avec des `Rules`

---
### `addPremise`