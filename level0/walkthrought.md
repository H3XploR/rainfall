depuis m4 max, il faut changer les paramètres UTM, de display et retirer uefi boot.

Ensuite il faut taper le mdp du sujet,

output de differente commande:

cmd> file level0 -> level0: setuid ELF 32-bit LSB executable, 
                            Intel 80386, version 1 (GNU/Linux), 
                            statically linked, for GNU/Linux 2.6.24, 
                            BuildID[sha1]=0x85cf4024dbe79c7ccf4f30e7c601a356ce04f412, 
                            not stripped

Le but est d'acceder a .pass du levelX (niveau suivant)
le programme fait un atoi sur le premier arguments, si le premier argument
est egale a 423, il me transforme en user level1.
Je peux donc acceder au .pass du user level1, le mot de passe etant:
1fe8a524fa4bec01ca4ea2a869af2a02260d4a7d5fe7e7c24d8617e6dca12d3a
