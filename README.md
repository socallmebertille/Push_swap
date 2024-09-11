# Make a Push_Swap project

<br>

## 1st step : recuperer les arguments passer en parametres

<br>

```
./push_swap "6 10 7 3 4"
```

<br>

Les arguments peuvent etre 2, si l'utilisateur met la suite desordonnee entre guillemets ou bien, une infinite.
<br>
Dans le cas ou il n'y en a que 2, on va split la string recu avec pour separateur le caractere espace. Nos nouveaux arguments auront donc pour valeur la string split. Or on va egalement ajoute un premier tableau contenant un caractere quelconque (ici '\0') car dans le second cas, le premier argument est le nom de l'executable.

<br>

```
./push_swap 6 10 7 3 4
```

<br>

Dans le cas ou le nombre d'argument est le nombre de chiffres desordonnes + le nom de l'executable, on peut passer a la deuxieme etape.

<br>

## 2nd step : verifier que la suite de nombre est conforme et creer la liste chainee

<br>

A partir du deuxieme argument av[1] et pour chacun d'entre eux, on :
<br>
- verifie si c'est un nombre ;
- transforme le nombre de type char en type long ;
- verifie que sa valeur est comprise entre le INT_MIN et le INT_MAX ;
- verifie qu'il n'y a pas de doublon.
<br>
Si un probleme survient dans l'une de ces verifications on libere l'espace alloue a la liste chainee et aux arguments uniquement si on a utiliser la fonction qui split auparavent. Puis on print un message d'erreur.
<br>
Sinon on peut creer la liste chainee qui correspondra a la stack A. Puis on libere l'espace alloue aux arguments uniquement si on a utiliser la fonction qui split auparavent.

<br>

## 3rd step : tant que la stack A n'est pas ordonee on verifie :

<br>

### 3.1 : s'il n'y a que 2 nombres

<br>

Dans le cas, on a juste a swap les 2 nombres, cad, swap les donnees concernant previous et next des 2 maillons de la liste.

<br>

### 3.2 : s'il n'y a que 3 nombres

<br>

On recupere le maillons le plus grand et si il se trouve :
<br>
- en tete de liste : on le rotate (= on le place en queue de liste) ;
- au milieu de la liste : on reverse rotate (= on place le dernier en premier pour qu'ici le milieu se retrouve bas) ;
- en queue de liste ET que la tete est > au milieu : on les swap.

<br>

### 3.3 : sinon (= s'il y a + de 3 nombres)

<br>

On deplace les nombres dans une stack temporaire B sous forme de liste chainee egalement jusqu'a n'avoir que 3 nombres dans A afin de proceder a l'algo pour 3 dans A. Or on va deplacer les elements dans B pour obtenir un premier tri grossier. 

<br>

#### 3.3.1 : on pre-tri

<br>

On calcule la mediane (= nb se situant au milieu d'une liste ordonne) qui nous servira de repere pour push l'element dans B ou le rotate dans A. On repetera l'operation autant de fois que la liste A possede + de 3 elements.

<br>

#### 3.3.2 : on recupere les donnees de chaque element de B

<br>

Tant que l'on a des elements dans B on met a jour :
<br>
- les index de positions des noeuds et leurs positions vis-a-vis de la mediane (de A pour les elements de A, respectivement pour B) ;
- la cible de chaque element de B vis-avis de B (cad, le plus proche superieur de B dans A) s'il en a un, sinon le plus petit de A ;
- le cout de deplacement de chaque element B vers la tete de liste B additionne a celui de sa cible
- -> si l'element est au-dessus de la mediane : nb de rotate = numero de position
- -> sinon : nb de reverse rotate = longueur de la liste - numero de position
- l'element le moins cher
<br>
Une fois cela calcule, on deplace l'element le moins couteux et sa target dans les stacks associees puis on peut donc push celui de B dans A au-dessus de sa target. On repete l'operation autant de fois que d'element dans B.

<br>

### 3.4 : on oublie pas de recuperer le plus petit element en haut

<br>

Il se peut qu'en replacant les element de B dans A, l'element le plus faible se perde en bout de liste. Dans ce cas, meme principe, si superieur a la mediane on rotate sinon on reverse rotate.

<br>

### 4th step : on oublie de proceder au maximum de verif


<br>

```
git clone https://github.com/o-reo/push_swap_visualizer.git
cd push_swap_visualizer
mkdir build
cd build
cmake ..
make
./bin/visualizer
```

<br>

On sait qu'on a un visualiseur a notre disposition qui permet de generer de grandes listes aleatoires, de tester notre programme et de pouvoir observer son comportement ainsi que son bon fonctionnement.

<br>

```
ARG = "45456 25 98 2 487 359 6 ....."
valgrind ./push_swap $ARG
```

<br>

On sait egalement que notre bon et vieil ami est la pour nous signaler si l'on a autant de malloc que de free.

<br>

```
funcheck ./push_swap $ARG
```

<br>

Et notre fameux funcheck qui nous permet de nous assurer que chacun de nos malloc est bien proteger et ne corrompera pas notre programme.

<br>

```
./push_swap $ARG | ./checker_linux $ARG
```

<br>

Pour finir, le checker propose par le sujet, pouvant etre realise dans la partie bonus. Il permet de verifier que la stack B est vide, que les solutions apportees par le programme fonctionnent, que la liste fournie par l'utilisateur est valide. En bref, que tout s'est bien deroule.
