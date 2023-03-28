#include <iostream>
#include <vector>

int main() {
    int totalCards, handSize;
    std::cin >> totalCards >> handSize;
    std::vector<std::pair<int,int>> cards(totalCards);
    for (int i = 0; i < totalCards; i++) {
        std::cin >> cards[i].first >> cards[i].second;
    }

    int turns = 1; // set turns to 1 as we are drawing one card
    bool sequenceExists = false;
    int count[5] = {0}; // array to keep count of each color
    for(int i = 0; i < handSize; i++){
        count[cards[i].first]++;
    }
    for(int i = 1; i <= 4; i++){
        if(count[i] >= 3){
            sequenceExists = true;
            break;
        }
    }

    if(sequenceExists){
        for(int i = 0; i < handSize; i++){
            if(cards[i].first == cards[handSize].first && sequenceExists){
                count[cards[i].first]--;
                turns--;
                if(count[cards[i].first] < 3)
                    sequenceExists = false;
            }
        }
    }
        if (sequenceExists) {
        std::cout << turns << std::endl;
    } else {
        std::cout << "neibb" << std::endl;
    }
    return 0;
}
