# 📡 Minitalk

## 📖 Présentation
**Minitalk** est un projet qui a pour but de mettre en place un système de communication entre deux processus sous Unix.  
L’émetteur (client) envoie un message au récepteur (serveur) en utilisant uniquement les signaux Unix `SIGUSR1` et `SIGUSR2`.  

Ce projet permet de se familiariser avec :
- La gestion des signaux sous Unix.
- La communication inter-processus (IPC).
- La rigueur dans la manipulation de bas niveau en C.

---

## 🎯 Objectifs et Contraintes
- Implémenter un **serveur** capable de recevoir des messages.
- Implémenter un **client** qui envoie une chaîne de caractères au serveur.
- Utiliser uniquement les signaux `SIGUSR1` et `SIGUSR2` pour transmettre les données. (Manipuliation des bits)
- Le serveur doit afficher les messages reçus en temps réel.
- Le code doit respecter les normes de l’école 42.
- Gestion des erreurs obligatoire (pid invalide, signal manquant, etc.).

## ⭐ Bonus :
  - Communication bidirectionnelle (accusé de réception).
  - Envoi de chaînes Unicode.
---

## 🚀 Utilisation

### 1️⃣ Compilation
Dans le répertoire du projet, lancez la commande :
```bash
make
```
### 2️⃣ Lancement du serveur
Exécutez le serveur :  
```bash
./server  
```
Le serveur affiche son **PID**, indispensable pour que le client sache où envoyer les messages.

### 3️⃣ Envoi d’un message depuis le client
En utilisant le PID du serveur affiché précédemment : 
```bash
./client <PID_SERVEUR> "Votre message ici"  
```
Exemple :  
./client 4242 "Hello World!"  

Le serveur affichera :  
Hello World!  

---
