class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        for(int i = 0; i < asteroids.size(); i++){
            if(mass > 1e5) return true;
            if(mass < asteroids[i]) return false;
            mass += asteroi
            s[i];
        }
        return true;
    }
};

// Approch : Go with random order And we will get to know only way to save planets is to collide the smaller one fiorst to increase the mass 
