# Make a Push_Swap project

<br>

## 1st step : recuperer les arguments passer en parametres

<br>

```
./push_swap 6 10 7 3 4
```

<br>

Les arguments peuvent etre 2, si l'utilisateur met la suite desordonnee entre guillemets ou bien, une infinite.
Dans le cas ou il n'y en a que 2, on va split la string recu avec pour separateur le caractere espace. Nos nouveaux arguments auront donc pour valeur la string split. Or on va egalement ajoute un premier tableau contenant un caractere quelconque (ici '\0') car dans le second cas, le premier argument est le nom de l'executable.
Dans le cas ou le nombre d'argument est le nombre de chiffres desordonnes + le nom de l'executable, on peut passer a la deuxieme etape.

<br>

## 2nd step : verifier que la suite de nombre est conforme et creer la liste chainee

<br>

A partir du deuxieme argument av[1] et pour chacun d'entre eux, on :
    - verifie si c'est un nombre ;
    - transforme le nombre de type char en type long ;
    - verifie que sa valeur est comprise entre le INT_MIN et le INT_MAX ;
    - verifie qu'il n'y a pas de doublon.
Si un probleme survient dans l'une de ces verifications on libere l'espace alloue a la liste chainee et aux arguments uniquement si on a utiliser la fonction qui split auparavent. Puis on print un message d'erreur.
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
    - en tete de liste : on le rotate (= on le place en queue de liste)
    - au milieu de la liste : on reverse rotate (= on place le dernier en premier pour qu'ici le milieu se retrouve bas)
    - 

<br>

### 3.3 :

<br>

A

<br>

### 3.4 :

<br>

A

<br>
## ``` void  *ft_memmove(void *dest, const void *src, size_t n); ```
