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
#include"RoundManager.h"
#include "Abilitie.h"
using namespace std;

Unit player;
void InitPlayer(Unit& choosenUnit);

int main()
{
    //declarartion d'un roundManager
    RoundManager roundManager;
    //InitPlayer(player);
    
    InitPlayer(player);
    
    




    Supply healingPotion = Supply("healing potion", 4, (EffectSupply::Heal|EffectSupply::Cure),1,8);
    Abilitie explosion = Abilitie("explosion", map<Effect, int> { {Effect::Burn, 100}, { Effect::Blinded, 100 }}, 0, 4, 6, TargettingType::AllEnemie);
    Abilitie heal = Abilitie("heal ", map<Effect, int> { {Effect::Cure, 100}}, 0, 1, 6, TargettingType::OneAlly, AbilitieType::Heal);

    
    // sett characters
    
    Unit* playerPtr = &player;
    Unit gerard("Gerard", 10,5, 8, 6, 12, 9, 2, 18, UnitType::Ally);
    Mercant armurier("pascal",10,5,8,6,12,9,2,18,UnitType::Ennemie);
    Weapon longSword= Weapon("long Sword",20,20,20,12);
     //on vas setter les point de vie des different personnages
    player.SetMaxHp(20);
    player.SetCurrentHp(15);
    gerard.SetCurrentHp(20);
    gerard.SetMaxHp(7);
    armurier.SetMaxHp(20);
    armurier.SetCurrentHp(20);
     //on vas setter l'inventaire du marchand
    armurier.AddItem(Weapon("woodenstaff", 2, 1, 4, 1.5));
    armurier.AddItem(Item("cailloux", 1, 1, true, true));
    armurier.AddItem(longSword); 
    // on vas donner une potion de soins a tout les Personnages
    player.AddItem(longSword);
    armurier.AddItem(healingPotion);
    gerard.AddItem(healingPotion);
    player.AddItem(healingPotion);
    // learn Abilitie
    player.LearnAbilitie(explosion);
    player.LearnAbilitie(heal);

    // initialisation d'une rencontre
    roundManager.AddUnit(&player);
    roundManager.AddUnit(&armurier);
    roundManager.AddUnit(&gerard);
    roundManager.NewRound();

   
    player.UseAbility(heal);
    //healingPotion.GetEffect();
    

   

   

    
   
    
    
   

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
    /*player.UseSupply(healingPotion);
    player.DisplayUnitType();
    armurier.DisplayUnitType();
    gerard.DisplayUnitType();
    cout << player.GetCurrentHp() << endl;*/
    

    
    //roundManager.DisplayRoundlist();
    //player.UseAbility(heal);
   
    
   


    
}

void InitPlayer(Unit& choosenUnit) {
    int playerChoice;
    string playerName;
    cout << "what's your name traveller ?";
    cin >> playerName;
    cout << "hello " << playerName << " Nice to meet you\n";

    cout << "please select your classe with the corresponding number" << endl;
    cout << "1 :warrior\n 2 :Wizard\n 3 :Rogue\n" << endl;
    cin >> playerChoice;
    switch(playerChoice)
    {
    case 1:
        choosenUnit = Unit(playerName, 30, 5, 20, 12, 18, 8, 10, 12, UnitType::Ally);
        player.DisplaySumUp();
        break;
    case 2:
        choosenUnit = Unit(playerName, 15, 20, 6, 14, 10, 20, 18, 8, UnitType::Ally);
        player.DisplaySumUp();
        break;
    case 3:
        choosenUnit = Unit(playerName, 20, 10, 14, 20, 14, 12, 12, 8, UnitType::Ally);
        player.DisplaySumUp();
    default:
        cout << "you haven't choose a good number please select a unmber between 1 and 3" << endl;
        InitPlayer(choosenUnit);
        break;
    }
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
