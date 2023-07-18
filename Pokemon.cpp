#include <bits/stdc++.h>
using namespace std;

struct Pokemon{
    int dex;
    string Name;
    string type1;
    string type2;
    vector<int> Move;
    vector<int> Stats;
};

struct Move{
    string Name;
    string Type;
    int ps; //0->status, 1->physical, 2->special
    int attack;
    int power;
    int accuracy;    
};


class Moves{
    public:
        unordered_map<int, Move> MOVES;

        float get7to1(){
            int x=rand();
            x = x%30;
            float y=x+70;
            y /= 100;
            return y;
        }

        float eff(string a, string b){
            if(a=="fire"){
                if(b=="grass"||b=="bug"||b=="steel"||b=="ice") return 2;
                else if(b=="water"||b=="fire"||b=="dragon"||b=="rock") return 0.5;
                else return 1;
            }
            else if(a=="water"){
                if(b=="fire"||b=="rock"||b=="ground") return 2;
                else if(b=="water"||b=="grass"||b=="dragon") return 0.5;
                else return 1;
            }
            else if(a=="grass"){
                if(b=="water"||b=="rock"||b=="ground") return 2;
                else if(b=="fire"||b=="grass"||b=="poison"||b=="flying"||b=="bug"||b=="dragon"||b=="steel") return 0.5;
                else return 1;
            }
            else if(a=="electric"){
                if(b=="water"||b=="flying") return 2;
                else if(b=="ground") return 0;
                else if(b=="electric"||b=="grass"||b=="dragon") return 0.5;
                else return 1;
            }
            else if(a=="rock"){
                if(b=="fire"||b=="flying"||b=="bug"||b=="ice") return 2;
                else if(b=="fighting"||b=="ground"||b=="steel") return 0.5;
                else return 1;
            }
            else if(a=="poison"){
                if(b=="grass"||b=="fairy") return 2;
                else if(b=="steel") return 0;
                else if(b=="ground"||b=="poison"||b=="rock"||b=="ground") return 0.5;
                else return 1;
            }
            else if(a=="ground"){
                if(b=="fire"||b=="rock"||b=="poison"||b=="steel"||b=="electric") return 2;
                else if(b=="grass"||b=="bug") return 0.5;
                else if(b=="flying") return 0;
                else return 1;
            }
            else if(a=="flying"){
                if(b=="grass"||b=="bug"||b=="fighting") return 2;
                else if(b=="electric"||b=="rock"||b=="steel") return 0.5;
                else return 1;
            }
            else if(a=="steel"){
                if(b=="ice"||b=="fairy"||b=="rock") return 2;
                else if(b=="fire"||b=="water"||b=="electric"||b=="steel") return 0.5;
                else return 1;
            }
            else if(a=="bug"){
                if(b=="grass"||b=="psychic"||b=="dark") return 2;
                else if(b=="fighting"||b=="poison"||b=="flying"||b=="fire"||b=="ghost"||b=="steel"||b=="fairy") return 0.5;
                else return 1;
            }
            else if(a=="psychic"){
                if(b=="poison"||b=="fighting") return 2;
                else if(b=="dark") return 0;
                if(b=="psychic"||b=="steel") return 0.5;
                else return 1;
            }
            else if(a=="dark"){
                if(b=="psychic"||b=="ghost") return 2;
                else if(b=="fighing"||b=="dark"||b=="fairy") return 0.5;
                else return 1;
            }
            else if(a=="ghost"){
                if(b=="ghost"||b=="psychic") return 2;
                else if(b=="normal") return 0;
                else if(b=="dark") return 0.5;
                else return 1;
            }
            else if(a=="fairy"){
                if(b=="dragon"||b=="fighting"||b=="dark") return 2;
                else if(b=="steel"||b=="poison"||b=="fire") return 0.5;
                else return 1;
            }
            else if(a=="normal"){
                if(b=="ghost") return 0;
                else if(b=="rock"||b=="steel") return 0.5;
                else return 1;
            }
            else if(a=="fighting"){
                if(b=="normal"||b=="rock"||b=="ice"||b=="steel"||b=="dark") return 2;
                else if(b=="poison"||b=="flying"||b=="psychic"||b=="bug"||b=="fairy") return 0.5;
                else if(b=="ghost") return 0;
                else return 1;
            }
            else if(a=="ice"){
                if(b=="grass"||b=="dragon"||b=="ground"||b=="flying") return 2;
                else if(b=="fire"||b=="water"||b=="ice"||b=="steel") return 0.5;
                else return 1;
            }
            else if(a=="dragon"){
                if(b=="dragon") return 2;
                else if(b=="fairy") return 0;
                else if(b=="steel") return 0.5;
                else return 1;
            }
            return 0;
        }

        void ALLPOKEMON(vector<Pokemon> Allpokemon){
            Allpokemon.push_back({1, "Bulbasaur", "grass", "poison", {}, {45,49,49,65,65,45}});
            Allpokemon.push_back({2, "Ivysaur", "grass", "poison", {}, {60,62,63,80,80,40}});
            Allpokemon.push_back({3, "Venusaur", "grass", "poison", {}, {80,82,83,100,100,80}});
            Allpokemon.push_back({4, "Charmander", "fire", "", {}, {39,52,43,60,50,55}});
            Allpokemon.push_back({5, "Charmelon", "fire", "", {}, {58,64,58,80,65,80}});
            Allpokemon.push_back({6, "Charizard", "fire", "flying", {}, {78,84,78,109,85,100}});
            Allpokemon.push_back({7, "Squirtle", "water", "", {}, {44,48,65,50,64,43}});
            Allpokemon.push_back({8, "Wartortle", "water", "", {}, {59,63,80,65,80,58}});
            Allpokemon.push_back({9, "Blastoise", "water", "", {}, {79,83,100,85,105,78}});
            Allpokemon.push_back({10, "Caterpie", "bug", "", {}, {45,30,35,20,20,45}});
            Allpokemon.push_back({11, "Metapod", "bug", "", {}, {50,20,55,25,25,30}});
            Allpokemon.push_back({12, "Butterfree", "bug", "flying", {}, {60,45,50,90,80,70}});
            Allpokemon.push_back({13, "Weedle", "bug", "poison", {}, {40,35,30,20,20,50}});
            Allpokemon.push_back({14, "Kakuna", "bug", "poison", {}, {45,25,50,25,25,35}});
            Allpokemon.push_back({15, "Beedrill", "bug", "poison", {}, {65,90,40,45,80,75}});
            Allpokemon.push_back({16, "Pidgey", "normal", "flying", {}, {40,45,40,35,35,56}});
            Allpokemon.push_back({17, "Pidgeotto", "normal", "flying", {}, {63,60,55,50,50,71}});
            Allpokemon.push_back({18, "Pidgeot", "normal", "flying", {}, {83,80,75,70,70,101}});
            Allpokemon.push_back({19, "Rattata", "normal", "", {}, {30,56,35,25,35,72}});
            Allpokemon.push_back({20, "Raticate", "normal", "", {}, {55,81,60,50,70,97}});
            Allpokemon.push_back({21, "Spearow", "normal", "flying", {}, {40,60,30,31,31,70}});
            Allpokemon.push_back({22, "Fearow", "normal", "flying", {}, {65,90,65,61,61,100}});
            Allpokemon.push_back({23, "Ekans", "poison", "", {}, {35,60,44,40,54,55}});
            Allpokemon.push_back({24, "Arbok", "poison", "", {}, {60,95,69,65,79,80}});
            Allpokemon.push_back({25, "Pikachu", "electric", "", {}, {35,55,40,50,50,90}});
            Allpokemon.push_back({26, "Raichu", "electric", "", {}, {60,90,55,90,80,110}});
            Allpokemon.push_back({27, "Sandshrew", "ground", "", {}, {50,75,85,20,30,40}});
            Allpokemon.push_back({28, "Sandslash", "ground", "", {}, {75,100,110,45,55,65}});
            Allpokemon.push_back({29, "Nidoran - F", "poison", "", {}, {75,47,52,40,40,41}});
            Allpokemon.push_back({30, "Nidorina", "poison", "", {}, {70,62,67,55,55,56}});
            Allpokemon.push_back({31, "Nidoqueen", "poison", "ground", {}, {90,92,87,75,85,76}});
            Allpokemon.push_back({32, "Nidoran - M", "poison", "", {}, {46,57,40,40,40,50}});
            Allpokemon.push_back({33, "Nidorino", "poison", "", {}, {61,72,57,55,44,65}});
            Allpokemon.push_back({34, "Nidoking", "poison", "ground", {}, {81,102,77,85,75,85}});
            Allpokemon.push_back({35, "Clefairy", "fairy", "", {}, {70,45,48,60,65,35}});
            Allpokemon.push_back({36, "Clefable", "fairy", "", {}, {95,70,73,95,90,60}});
            Allpokemon.push_back({37, "fire", "", {}, {38,41,40,50,65,65}});
            Allpokemon.push_back({38, "fire", "", {}, {73,76,75,81,100,100}});
            Allpokemon.push_back({39, "normal", "fairy", {}, {115,45,20,45,25,20}});
            Allpokemon.push_back({40, "normal", "fairy", {}, {140,70,45,85,50,45}});
            Allpokemon.push_back({41, "poison", "flying", {}, {40,45,35,30,40,55}});
            Allpokemon.push_back({42, "poison", "flying", {}, {75,80,70,65,75,90}});
            Allpokemon.push_back({43, "grass", "poison", {}, {45,50,55,75,65,30}});
            Allpokemon.push_back({44, "grass", "poison", {}, {60,65,70,85,75,40}});
            Allpokemon.push_back({45, "grass", "poison", {}, {75,80,85,110,90,50}});
            Allpokemon.push_back({46, "bug", "grass", {}, {35,70,55,45,55,25}});
            Allpokemon.push_back({47, "bug", "grass", {}, {60,95,80,60,80,30}});
            Allpokemon.push_back({48, "bug", "poison", {}, {60,55,50,40,55,45}});
            Allpokemon.push_back({49, "bug", "poison", {}, {70,65,60,90,75,90}});
            Allpokemon.push_back({50, "ground", "", {}, {10,55,25,35,45,95}});
            Allpokemon.push_back({51, "ground", "", {}, {35,100,50,50,70,120}});
            Allpokemon.push_back({52, "normal", "", {}, {35,45,35,40,40,90}});
            Allpokemon.push_back({53, "normal", "", {}, {65,70,60,65,65,115}});
            Allpokemon.push_back({54, "water", "", {}, {50,52,48,65,50,55}});
            Allpokemon.push_back({55, "water", "", {}, {80,82,78,95,80,85}});
            Allpokemon.push_back({56, "fighting", "", {}, {40,80,35,35,45,70}});
            Allpokemon.push_back({57, "fighting", "", {}, {65,105,60,60,70,95}});
            Allpokemon.push_back({58, "fire", "", {}, {55,70,45,70,50,60}});
            Allpokemon.push_back({59, "fire", "", {}, {90,110,80,110,80,95}});
            Allpokemon.push_back({60, "water", "", {}, {40,50,40,40,40,90}});
            Allpokemon.push_back({61, "water", "", {}, {65,65,65,50,50,90}});
            Allpokemon.push_back({62, "water", "fighting", {}, {90,95,95,70,90,70}});
            Allpokemon.push_back({63, "psychic", "", {}, {25,20,15,105,55,90}});
            Allpokemon.push_back({64, "psychic", "", {}, {40,35,30,120,70,105}});
            Allpokemon.push_back({65, "psychic", "", {}, {55,50,45,135,95,120}});
            Allpokemon.push_back({66, "fighting", "", {}, {70,80,50,35,35,35}});
            Allpokemon.push_back({67, "fighting", "", {}, {80,100,70,50,60,45}});
            Allpokemon.push_back({68, "fighting", "", {}, {80,130,80,65,85,55}});
            Allpokemon.push_back({69, "grass", "poison", {}, {50,75,35,70,35,40}});
            Allpokemon.push_back({70, "grass", "poison", {}, {65,90,50,85,45,55}});
            Allpokemon.push_back({71, "grass", "poison", {}, {80,105,65,100,70,70}});
            Allpokemon.push_back({72, "water", "poison", {}, {40,40,35,50,100,70}});
            Allpokemon.push_back({73, "water", "poison", {}, {80,70,65,80,12,110}});
            Allpokemon.push_back({74, "rock", "ground", {}, {}});
            Allpokemon.push_back({75, "rock", "ground", {}, {}});
            Allpokemon.push_back({76, "rock", "ground", {}, {}});
            Allpokemon.push_back({77, "fire", "", {}, {}});
            Allpokemon.push_back({78, "fire", "", {}, {}});
            Allpokemon.push_back({79, "water", "psychic", {}, {}});
            Allpokemon.push_back({80, "water", "psychic", {}, {}});
            Allpokemon.push_back({81, "electric", "steel", {}, {}});
            Allpokemon.push_back({82, "electric", "steel", {}, {}});
            Allpokemon.push_back({83, "normal", "flying", {}, {}});
            Allpokemon.push_back({84, "normal", "flying", {}, {}});
            Allpokemon.push_back({85, "normal", "flying", {}, {}});
            Allpokemon.push_back({86, "water", "", {}, {}});
            Allpokemon.push_back({87, "water", "ice", {}, {}});
            Allpokemon.push_back({88, "poison", "", {}, {}});
            Allpokemon.push_back({89, "poison", "", {}, {}});
            Allpokemon.push_back({90, "water", "", {}, {}});
            Allpokemon.push_back({91, "water", "ice", {}, {}});
            Allpokemon.push_back({92, "ghost", "poison", {}, {}});
            Allpokemon.push_back({93, "ghost", "poison", {}, {}});
            Allpokemon.push_back({94, "ghost", "poison", {}, {}});
            Allpokemon.push_back({95, "rock", "ground", {}, {}});
            Allpokemon.push_back({96, "psychic", "", {}, {}});
            Allpokemon.push_back({97, "psychic", "", {}, {}});
            Allpokemon.push_back({98, "water", "", {}, {}});
            Allpokemon.push_back({99, "water", "", {}, {}});
            Allpokemon.push_back({100, "electric", "", {}, {}});
            Allpokemon.push_back({101, "electric", "", {}, {}});
            Allpokemon.push_back({102, "grass", "psychic", {}, {}});
            Allpokemon.push_back({103, "grass", "psychic", {}, {}});
            Allpokemon.push_back({104, "ground", "", {}, {}});
            Allpokemon.push_back({105, "ground", "", {}, {}});
            Allpokemon.push_back({106, "fighting", "", {}, {}});
            Allpokemon.push_back({107, "fighting", "", {}, {}});
            Allpokemon.push_back({108, "normal", "", {}, {}});
            Allpokemon.push_back({109, "poison", "", {}, {}});
            Allpokemon.push_back({110, "poison", "", {}, {}});
            Allpokemon.push_back({111, "ground", "rock", {}, {}});
            Allpokemon.push_back({112, "ground", "rock", {}, {}});
            Allpokemon.push_back({113, "normal", "", {}, {}});
            Allpokemon.push_back({114, "grass", "", {}, {}});
            Allpokemon.push_back({115, "normal", "", {}, {}});
            Allpokemon.push_back({116, "water", "", {}, {}});
            Allpokemon.push_back({117, "water", "", {}, {}});
            Allpokemon.push_back({118, "water", "", {}, {}});
            Allpokemon.push_back({119, "water", "", {}, {}});
            Allpokemon.push_back({120, "water", "", {}, {}});
            Allpokemon.push_back({121, "water", "psychic", {}, {}});
            Allpokemon.push_back({122, "psychic", "fairy", {}, {}});
            Allpokemon.push_back({123, "bug", "flying", {}, {}});
            Allpokemon.push_back({124, "ice", "psychic", {}, {}});
            Allpokemon.push_back({125, "electric", "", {}, {}});
            Allpokemon.push_back({126, "fire", "", {}, {}});
            Allpokemon.push_back({127, "bug", "", {}, {}});
            Allpokemon.push_back({128, "normal", "", {}, {}});
            Allpokemon.push_back({129, "water", "", {}, {}});
            Allpokemon.push_back({130, "water", "flying", {}, {}});
            Allpokemon.push_back({131, "water", "ice", {}, {}});
            Allpokemon.push_back({132, "normal", "", {}, {}});
            Allpokemon.push_back({133, "normal", "", {}, {}});
            Allpokemon.push_back({134, "water", "", {}, {}});
            Allpokemon.push_back({135, "electric", "", {}, {}});
            Allpokemon.push_back({136, "fire", "", {}, {}});
            Allpokemon.push_back({137, "normal", "", {}, {}});
            Allpokemon.push_back({138, "rock", "water", {}, {}});
            Allpokemon.push_back({139, "rock", "water", {}, {}});
            Allpokemon.push_back({140, "rock", "water", {}, {}});
            Allpokemon.push_back({141, "rock", "water", {}, {}});
            Allpokemon.push_back({142, "rock", "flying", {}, {}});
            Allpokemon.push_back({143, "normal", "", {}, {}});
            Allpokemon.push_back({144, "ice", "flying", {}, {}});
            Allpokemon.push_back({145, "electric", "flying", {}, {}});
            Allpokemon.push_back({146, "fire", "flying", {}, {}});
            Allpokemon.push_back({147, "dragon", "", {}, {}});
            Allpokemon.push_back({148, "dragon", "", {}, {}});
            Allpokemon.push_back({149, "dragon", "flying", {}, {}});
            Allpokemon.push_back({150, "psychic", "", {}, {}});
            Allpokemon.push_back({151, "psychic", "", {}, {}});
            Allpokemon.push_back({152, "grass", "", {}, {}});
            Allpokemon.push_back({153, "grass", "", {}, {}});
            Allpokemon.push_back({154, "grass", "", {}, {}});
            Allpokemon.push_back({155, "fire", "", {}, {}});
            Allpokemon.push_back({156, "fire", "", {}, {}});
            Allpokemon.push_back({157, "fire", "", {}, {}});
            Allpokemon.push_back({158, "water", "", {}, {}});
            Allpokemon.push_back({159, "water", "", {}, {}});
            Allpokemon.push_back({160, "water", "", {}, {}});
            Allpokemon.push_back({161, "normal", "", {}, {}});
            Allpokemon.push_back({162, "normal", "", {}, {}});
            Allpokemon.push_back({163, "normal", "flying", {}, {}});
            Allpokemon.push_back({164, "normal", "flying", {}, {}});
            Allpokemon.push_back({165, "bug", "flying", {}, {}});
            Allpokemon.push_back({166, "bug", "flying", {}, {}});
            Allpokemon.push_back({167, "bug", "poison", {}, {}});
            Allpokemon.push_back({168, "bug", "poison", {}, {}});
            Allpokemon.push_back({169, "poison", "flying", {}, {}});
            Allpokemon.push_back({170, "water", "electric", {}, {}});
            Allpokemon.push_back({171, "water", "electric", {}, {}});
            Allpokemon.push_back({172, "electric", "", {}, {}});
            Allpokemon.push_back({173, "fairy", "", {}, {}});
            Allpokemon.push_back({174, "normal", "fairy", {}, {}});
            Allpokemon.push_back({175, "fairy", "", {}, {}});
            Allpokemon.push_back({176, "fairy", "flying", {}, {}});
            Allpokemon.push_back({177, "psychic", "flying", {}, {}});
            Allpokemon.push_back({178, "psychic", "flying", {}, {}});
            Allpokemon.push_back({179, "electric", "", {}, {}});
            Allpokemon.push_back({180, "electric", "", {}, {}});
            Allpokemon.push_back({181, "electric", "", {}, {}});
            Allpokemon.push_back({182, "grass", "", {}, {}});
            Allpokemon.push_back({183, "water", "fairy", {}, {}});
            Allpokemon.push_back({184, "water", "fairy", {}, {}});
            Allpokemon.push_back({185, "rock", "", {}, {}});
            Allpokemon.push_back({186, "water", "", {}, {}});
            Allpokemon.push_back({187, "grass", "flying", {}, {}});
            Allpokemon.push_back({188, "grass", "flying", {}, {}});
            Allpokemon.push_back({189, "grass", "flying", {}, {}});
            Allpokemon.push_back({190, "normal", "", {}, {}});
            Allpokemon.push_back({191, "grass", "", {}, {}});
            Allpokemon.push_back({192, "grass", "", {}, {}});
            Allpokemon.push_back({193, "bug", "flying", {}, {}});
            Allpokemon.push_back({194, "water", "ground", {}, {}});
            Allpokemon.push_back({195, "water", "ground", {}, {}});
            Allpokemon.push_back({196, "psychic", "", {}, {}});
            Allpokemon.push_back({197, "dark", "", {}, {}});
            Allpokemon.push_back({198, "dark", "flying", {}, {}});
            Allpokemon.push_back({199, "water", "psychic", {}, {}});
            Allpokemon.push_back({200, "ghost", "", {}, {}});
            Allpokemon.push_back({201, "psychic", "", {}, {}});
            Allpokemon.push_back({202, "psychic", "", {}, {}});
            Allpokemon.push_back({203, "normal", "psychic", {}, {}});
            Allpokemon.push_back({204, "bug", "", {}, {}});
            Allpokemon.push_back({205, "bug", "steel", {}, {}});
            Allpokemon.push_back({206, "normal", "", {}, {}});
            Allpokemon.push_back({207, "ground", "flying", {}, {}});
            Allpokemon.push_back({208, "steel", "ground", {}, {}});
            Allpokemon.push_back({209, "fairy", "", {}, {}});
            Allpokemon.push_back({210, "fairy", "", {}, {}});
            Allpokemon.push_back({211, "water", "poison", {}, {}});
            Allpokemon.push_back({212, "bug", "steel", {}, {}});
            Allpokemon.push_back({213, "bug", "rock", {}, {}});
            Allpokemon.push_back({214, "bug", "fighting", {}, {}});
            Allpokemon.push_back({215, "dark", "ice", {}, {}});
            Allpokemon.push_back({216, "normal", "", {}, {}});
            Allpokemon.push_back({217, "normal", "", {}, {}});
            Allpokemon.push_back({218, "fire", "", {}, {}});
            Allpokemon.push_back({219, "fire", "rock", {}, {}});
            Allpokemon.push_back({220, "ice", "ground", {}, {}});
            Allpokemon.push_back({221, "ice", "ground", {}, {}});
            Allpokemon.push_back({222, "water", "rock", {}, {}});
            Allpokemon.push_back({223, "water", "", {}, {}});
            Allpokemon.push_back({224, "water", "", {}, {}});
            Allpokemon.push_back({225, "ice", "flying", {}, {}});
            Allpokemon.push_back({226, "water", "flying", {}, {}});
            Allpokemon.push_back({227, "steel", "flying", {}, {}});
            Allpokemon.push_back({228, "dark", "fire", {}, {}});
            Allpokemon.push_back({229, "dark", "fire", {}, {}});
            Allpokemon.push_back({230, "water", "dragon", {}, {}});
            Allpokemon.push_back({231, "ground", "", {}, {}});
            Allpokemon.push_back({232, "ground", "", {}, {}});
            Allpokemon.push_back({233, "normal", "", {}, {}});
            Allpokemon.push_back({234, "normal", "", {}, {}});
            Allpokemon.push_back({235, "normal", "", {}, {}});
            Allpokemon.push_back({236, "fighting", "", {}, {}});
            Allpokemon.push_back({237, "fighting", "", {}, {}});
            Allpokemon.push_back({238, "ice", "psychic", {}, {}});
            Allpokemon.push_back({239, "electric", "", {}, {}});
            Allpokemon.push_back({240, "fire", "", {}, {}});
            Allpokemon.push_back({241, "normal", "", {}, {}});
            Allpokemon.push_back({242, "normal", "", {}, {}});
            Allpokemon.push_back({243, "electric", "", {}, {}});
            Allpokemon.push_back({244, "fire", "", {}, {}});
            Allpokemon.push_back({245, "water", "", {}, {}});
            Allpokemon.push_back({246, "rock", "ground", {}, {}});
            Allpokemon.push_back({247, "rock", "ground", {}, {}});
            Allpokemon.push_back({248, "rock", "dark", {}, {}});
            Allpokemon.push_back({249, "psychic", "flying", {}, {}});
            Allpokemon.push_back({250, "fire", "flying", {}, {}});
            Allpokemon.push_back({251, "psychic", "grass", {}, {}});
        }

        void AllMOVES(vector<Move> Allmove){
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
            Allmove.push_back({" ", " ", 0, 0, 0, 100});
        }

        float damageout(Move* M, vector<Pokemon*> A, int x, int y){
            float damage;
            int power = M->power;
            float STAB = (M->Type==A[x]->type1)||(M->Type==A[x]->type2)?1.5:1;
            int attack = M->ps?A[x]->Stats[3]:A[x]->Stats[1];
            int defense = M->ps?A[y]->Stats[4]:A[x]->Stats[2];
            float type1 = eff(M->Type, A[y]->type1);
            float type2 = eff(M->Type, A[y]->type2);
            float random = get7to1();
            damage = (22*power*attack/defense)/50;
            damage += 2;
            damage = STAB * damage * type1 * type2 * random;
            return damage;
        }

};

int main() {
    
    return 0;
}