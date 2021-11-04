// RPG.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
// implement template avec les encounter.
// implementer les resistance au type de damage avec des tags 
//
#include <iostream>
#include"Unit.h"
#include"Weapon.h"
#include"Mercant.h"
#include"Item.h"
#include"Supply.h"
#include "Abilitie.h"
using namespace std;


int main()
{
    
    Unit player("jojo", 10,8,14,45,9,18,2);
    Unit* playerPtr = &player;
    Mercant armurier;
    Weapon longSword= Weapon("long Sword",20,20,20,12);
    // on vas setter l'inventaire du marchand
    armurier.AddItem(Weapon("woodenstaff", 2, 1, 4, 1.5));
    armurier.AddItem(Item("cailloux", 1, 1, true, true));
    armurier.AddItem(longSword);

    cout << "what's your name traveller ?";
    string playerName;
    cin >> playerName;
    cout << "hello " << playerName << " Nice to meet you\n";

    armurier.AddMoney(40);
    player.AddMoney(50);
    Supply healingPotion = Supply("healing potion", 4, EffectSupply::Heal);
    Abilitie explosion = Abilitie("explosion", map<Effect, int> { {Effect::Burn, 100}, { Effect::Blinded, 100 }},0,4);
    player.AddAbilitie(explosion);
    player.AddItem(healingPotion);
    

    /*armurier.SellItem(player, longSword);
    cout<<explosion.GetChanceEffectWork(Effect::Burn)<<endl;
    cout<<explosion.GetChanceEffectWork(Effect::AcidSolving)<<endl;

    cout << player.RollInitiative(player.mDiceTwenty) << endl;
    cout << armurier.RollInitiative(player.mDiceTwenty) << endl;
    cout << player.GetCharacModifier(player.GetConstitution()) << endl;
    cout << player.UseAbilitie(explosion) << endl;
    cout << player.IsKnowedAbilitie("explosion") << endl;
    cout << player.IsKnowedAbilitie("prout") << endl;

    explosion.ResolutionEffect(Effect::Burn);
    cout << explosion.TestingChanceResolutionEffect(30) << endl;*/
    player.UseSupply(healingPotion);
    
   

   


    
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
