# Fonction de test et commentaires

---
Dans ces sections, nous allons vous commenter un jeu de tests que nous avons réalisé pour tester notre système expert. Nous allons vous présenter les résultats obtenus et vous expliquer pourquoi nous avons choisi ce test.

## Le test :

---
Nous avons décidé, pour tester notre bibliothèque, de réaliser un système de moteur expert graphique. Le sujet est très enfantin, mais il nous a permis de tester l'ensemble des fonctionnalités de notre bibliothèque. Voici le sujet : **Quand doit-on se promener ?**

Nous avons laissé à l'utilisateur la possibilité de modifier intégralement la base de connaissance des règles aux faits. Pour découvrir toutes les actions possibles merci de lancer le programme et suivre l'interface.

Quasiment toutes les fonctionnalités de notre bibliothèque sont utilisées dans ce programme. Nous avons donc pu tester l'ensemble de notre bibliothèque. Les seules fonctions non utilisées sont des variantes d'autres fonctions déjà utilisées. Nous avons aussi décidé de vous présenter plusieurs manières de réaliser la meme opération.

Nous sommes aussi conscient que notre programme n'est pas parfait, mais nous avons fait de notre mieux pour vous présenter un programme fonctionnel et complet. Par exemple un fait retirer d'une base de connaissance n'est pas retiré des règles qui le contiennent. Nous avons aussi décidé de ne pas gérer les erreurs de l'utilisateur.

Le fichier `main.c` est disponible dans le dossier exemple.

>[!NOTE]
> 
> Pour découvrir les faits (au nombre de 4 pqr défaut) merci de lancer le programme et d'imprimer les faits.

Pour compiler le programme, il vous suffit de lancer la commande suivante depuis la racine du projet :
```bash
gcc -o main main.c -I ../include/ ../src/*.c
```
De plus un ficher make est disponible à la racine du projet.

## Les résultats :

---
Le constat est assez positif, toutes les fonctions implémentée marche comme espérer et nous n'avons pas eu de problèmes majeurs.

Cependant, quelques fonctions en plus seraient intéressantes comme le fait de pouvoir retirer un fait de toutes les règles qui le contiennent. Mais cela peut être traiter manuellement avec l'implémentation d'une fonction.

### Analyse avec Valgrind :

---
Nous avons aussi testé notre programme avec Valgrind pour vérifier qu'il n'y avait pas de fuites mémoires. 

Notre programme ne semble pas avoir de fuite mémoire. Nous avons aussi testé notre programme avec l'option `--leak-check=full` et nous n'avons pas eu de fuite mémoire.
>[!NOTE]
> 
> Cependant, les fuites pendant l'implémentation ont été nombreuses et nous vous conseillons de faire attention à ce point et d'utiliser Valgrind pour vérifier votre programme.

Nous pensons aussi que le champ `last_id` des listes de faits peut différer entre les règles et base de connaissances car ce n'est pas un pointeur mais ous n'avons pas eu le temps de vérifier ce point.

## Conclusion :

---
Nous avons donc pu tester notre bibliothèque et nous avons pu constater que notre bibliothèque fonctionne comme espérer.

Nous avons apprécié travailler sur ce projet et nous avons appris beaucoup de chose. Nous avons aussi pu mettre en pratique nos connaissances en C et nous avons pu découvrir de nouvelles fonctionnalités du langage.

>Et désoler pour le retard de rendu, nous avions cru qu'il était pour le lendemain.

---
Pour en apprendre plus sur les fonctions merci de vous rendre dans la section [Guide des fonctions (en C)](Function.md)
