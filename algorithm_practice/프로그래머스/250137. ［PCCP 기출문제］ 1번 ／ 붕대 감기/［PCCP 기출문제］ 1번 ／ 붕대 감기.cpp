#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int max_health = health;
    int curr_attack_time = 0;
    for(int time = 0, cont_heal = -1; time <= *attacks.back().begin(); ++time)
    {
        if(curr_attack_time == attacks.size())
            break;
        if(time == attacks[curr_attack_time].front())
        {
			cont_heal = 0;
            health -= attacks[curr_attack_time].back();
            ++curr_attack_time;
            if(health <= 0)
                return -1;
        }
        else
        {
            health += bandage[1];
            if(++cont_heal == bandage[0])
            {
                cont_heal = 0;
                health += bandage[2];   
            }
            if(health > max_health)
                health = max_health;
        }
    }
    return health;
}