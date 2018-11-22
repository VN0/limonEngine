//
// Created by engin on 27.11.2017.
//

#ifndef LIMONENGINE_HUMANENEMY_H
#define LIMONENGINE_HUMANENEMY_H


#include "ActorInterface.h"
#include "../../libs/imgui/imgui.h"
#include "../Utils/LimonConverter.h"

class HumanEnemy: public ActorInterface {
    static ActorRegister<HumanEnemy> reg;

    const long PLAYER_SHOOT_TIMEOUT = 1000;
    long playerPursuitStartTime = 0L;
    long playerPursuitTimeout = 500000L; //if not see player for this amount, return.
    bool returnToPosition = false;
    glm::vec3 initialPosition;
    glm::vec3 lastWalkDirection;
    std::string currentAnimation;
    bool hitAnimationAwaiting = false;
    long dieAnimationStartTime = 0;
    long hitAnimationStartTime = 0;
    long lastSetupTime;
    long shootPlayerTimer = 0;
    uint32_t hitPoints = 100;

public:
    HumanEnemy(uint32_t id, LimonAPI *limonAPI) : ActorInterface(id, limonAPI) {}

    void play(long time, ActorInterface::ActorInformation &information) override;

    bool interaction(std::vector<LimonAPI::ParameterRequest> &interactionInformation) override;

    std::vector<LimonAPI::ParameterRequest> getParameters() const override;

    void setParameters(std::vector<LimonAPI::ParameterRequest> parameters) override;


    std::string getName() const override {
        return "ENEMY_AI_SWAT";
    }
};


extern "C" void registerActors(std::map<std::string, ActorInterface*(*)(uint32_t, LimonAPI*)>*);



#endif //LIMONENGINE_HUMANENEMY_H
